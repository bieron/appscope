import os
import json
import sys
import subprocess
import time
import watcher as w
import datetime
from utils import tabulate

help_text = '''options:
--help  display help text
--config config file for tests
--verbose verbose/debug output in console
'''


class Runner:
    def __init__(self, home, include_tests, exclude_tests, lib_path, verbose, log_path, process_timeout):
        self.__home = home
        self.__include_tests = include_tests
        self.__exclude_tests = exclude_tests
        self.__execution_id = "ltp:" + datetime.datetime.now().isoformat()
        self.__test_watcher = w.Watcher(log_path, self.__execution_id, verbose)
        self.__lib_path = lib_path
        self.__process_timeout = process_timeout

    def run(self):
        self.__test_watcher.start()

        for test in self.__include_tests:
            if test not in self.__exclude_tests:
                if os.path.isdir(test):
                    for d in os.listdir(test):
                        if d not in self.__exclude_tests:
                            self.__find_tests(self.__home + d)
                else:
                    self.__find_tests(self.__home + test)

        self.__test_watcher.finish()
        return (0, 1)[self.__test_watcher.has_failures()]

    def __find_tests(self, test_path):
        if not os.path.isdir(test_path):
            return

        for f in os.listdir(test_path):
            filename = test_path + '/' + f
            if os.path.isfile(filename) and os.access(filename, os.X_OK):
                if f not in self.__exclude_tests:
                    self.__execute_test(test_path, f, False)
                    self.__execute_test(test_path, f, True)

    def __execute_test(self, test_path, test, wrapped):
        print(tabulate(["Running " + test, "Scoped: " + str(wrapped), "Path: " + test_path], [25,17,0]))
        start = self.__now_ms()
        env = dict(os.environ)
        stdout = None
        stderr = None
        return_code = 0

        if wrapped:
            env['LD_PRELOAD'] = self.__lib_path

        p = subprocess.Popen('./' + test, stdout=subprocess.PIPE, stderr=subprocess.PIPE, cwd=test_path, env=env, universal_newlines=True)

        try:
            stdout, stderr = p.communicate(timeout=self.__process_timeout)
            return_code = p.returncode
        except subprocess.TimeoutExpired:
            p.kill()
            return_code = 124  # timeout return code
            stderr = "Exit by timeout. Timeout: " + self.__process_timeout

        self.__send_result(w.TestResult(test, wrapped, stdout, stderr, self.__now_ms() - start, return_code))

    def __send_result(self, result):
        if result.return_code == 0:
            self.__test_watcher.test_passed(result)
        else:
            self.__test_watcher.test_failed(result)

    def __now_ms(self):
        return int(round(time.time() * 1000))


def main(args):
    configs = []
    verbose = False
    log_path = None
    process_timeout = 300
    # parse args
    for i in range(len(args)):
        if args[i] == '--help':
            print(help_text)

        if args[i] == '--verbose':
            verbose = True
        if args[i] == '--config':
            path = args[i + 1]
            with open(path, "rb") as f:
                config = json.loads(f.read().decode("utf8"))
                log_path = config.get("log_path", "/tmp/")  # default path is "tmp" dir
                process_timeout = config["process_timeout"]
                configs = config["configs"]

    if len(configs) == 0:
        sys.stderr.write("no valid config")
        return 1

    test_results = 0

    for s in configs:
        c = configs[s]
        home = c["home"]
        include_tests = c["include_tests"]
        exclude_tests = c["exclude_tests"]
        lib_path = c["lib_path"]

        if not home.endswith('/'):
            home += '/'

        if c["enabled"]:
            if not os.path.exists(home):
                sys.stderr.write("tests home is not valid")
                return 1

            if Runner(home, include_tests, exclude_tests, lib_path, verbose, log_path, process_timeout).run() == 1:
                test_results = 1

    return test_results


if __name__ == "__main__":
    sys.exit(main(sys.argv))
