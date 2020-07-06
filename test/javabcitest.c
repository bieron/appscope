#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "test.h"
#include "javabci.h"

/*
JavaTest.class compiled from ./manual/JavaTest.java
*/
unsigned char JavaTest_class[] = {
  0xca, 0xfe, 0xba, 0xbe, 0x00, 0x00, 0x00, 0x34, 0x00, 0x2a, 0x0a, 0x00,
  0x08, 0x00, 0x1b, 0x09, 0x00, 0x1c, 0x00, 0x1d, 0x0a, 0x00, 0x1e, 0x00,
  0x1f, 0x07, 0x00, 0x20, 0x0a, 0x00, 0x04, 0x00, 0x1b, 0x08, 0x00, 0x21,
  0x0a, 0x00, 0x04, 0x00, 0x22, 0x07, 0x00, 0x23, 0x01, 0x00, 0x0b, 0x73,
  0x74, 0x61, 0x74, 0x69, 0x63, 0x46, 0x69, 0x65, 0x6c, 0x64, 0x01, 0x00,
  0x12, 0x4c, 0x6a, 0x61, 0x76, 0x61, 0x2f, 0x6c, 0x61, 0x6e, 0x67, 0x2f,
  0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x3b, 0x01, 0x00, 0x0d, 0x43, 0x6f,
  0x6e, 0x73, 0x74, 0x61, 0x6e, 0x74, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x08,
  0x00, 0x24, 0x01, 0x00, 0x06, 0x66, 0x69, 0x65, 0x6c, 0x64, 0x31, 0x01,
  0x00, 0x06, 0x66, 0x69, 0x65, 0x6c, 0x64, 0x32, 0x01, 0x00, 0x13, 0x4c,
  0x6a, 0x61, 0x76, 0x61, 0x2f, 0x6c, 0x61, 0x6e, 0x67, 0x2f, 0x49, 0x6e,
  0x74, 0x65, 0x67, 0x65, 0x72, 0x3b, 0x01, 0x00, 0x06, 0x3c, 0x69, 0x6e,
  0x69, 0x74, 0x3e, 0x01, 0x00, 0x03, 0x28, 0x29, 0x56, 0x01, 0x00, 0x04,
  0x43, 0x6f, 0x64, 0x65, 0x01, 0x00, 0x0f, 0x4c, 0x69, 0x6e, 0x65, 0x4e,
  0x75, 0x6d, 0x62, 0x65, 0x72, 0x54, 0x61, 0x62, 0x6c, 0x65, 0x01, 0x00,
  0x05, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x01, 0x00, 0x15, 0x28, 0x4c, 0x6a,
  0x61, 0x76, 0x61, 0x2f, 0x6c, 0x61, 0x6e, 0x67, 0x2f, 0x53, 0x74, 0x72,
  0x69, 0x6e, 0x67, 0x3b, 0x29, 0x56, 0x01, 0x00, 0x0c, 0x6e, 0x61, 0x74,
  0x69, 0x76, 0x65, 0x4d, 0x65, 0x74, 0x68, 0x6f, 0x64, 0x01, 0x00, 0x04,
  0x6d, 0x61, 0x69, 0x6e, 0x01, 0x00, 0x16, 0x28, 0x5b, 0x4c, 0x6a, 0x61,
  0x76, 0x61, 0x2f, 0x6c, 0x61, 0x6e, 0x67, 0x2f, 0x53, 0x74, 0x72, 0x69,
  0x6e, 0x67, 0x3b, 0x29, 0x56, 0x01, 0x00, 0x0a, 0x53, 0x6f, 0x75, 0x72,
  0x63, 0x65, 0x46, 0x69, 0x6c, 0x65, 0x01, 0x00, 0x0d, 0x4a, 0x61, 0x76,
  0x61, 0x54, 0x65, 0x73, 0x74, 0x2e, 0x6a, 0x61, 0x76, 0x61, 0x0c, 0x00,
  0x10, 0x00, 0x11, 0x07, 0x00, 0x25, 0x0c, 0x00, 0x26, 0x00, 0x27, 0x07,
  0x00, 0x28, 0x0c, 0x00, 0x29, 0x00, 0x15, 0x01, 0x00, 0x17, 0x69, 0x6f,
  0x2f, 0x63, 0x72, 0x69, 0x62, 0x6c, 0x2f, 0x73, 0x63, 0x6f, 0x70, 0x65,
  0x2f, 0x4a, 0x61, 0x76, 0x61, 0x54, 0x65, 0x73, 0x74, 0x01, 0x00, 0x0b,
  0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x0c,
  0x00, 0x14, 0x00, 0x15, 0x01, 0x00, 0x10, 0x6a, 0x61, 0x76, 0x61, 0x2f,
  0x6c, 0x61, 0x6e, 0x67, 0x2f, 0x4f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x01,
  0x00, 0x06, 0x73, 0x74, 0x61, 0x74, 0x69, 0x63, 0x01, 0x00, 0x10, 0x6a,
  0x61, 0x76, 0x61, 0x2f, 0x6c, 0x61, 0x6e, 0x67, 0x2f, 0x53, 0x79, 0x73,
  0x74, 0x65, 0x6d, 0x01, 0x00, 0x03, 0x6f, 0x75, 0x74, 0x01, 0x00, 0x15,
  0x4c, 0x6a, 0x61, 0x76, 0x61, 0x2f, 0x69, 0x6f, 0x2f, 0x50, 0x72, 0x69,
  0x6e, 0x74, 0x53, 0x74, 0x72, 0x65, 0x61, 0x6d, 0x3b, 0x01, 0x00, 0x13,
  0x6a, 0x61, 0x76, 0x61, 0x2f, 0x69, 0x6f, 0x2f, 0x50, 0x72, 0x69, 0x6e,
  0x74, 0x53, 0x74, 0x72, 0x65, 0x61, 0x6d, 0x01, 0x00, 0x07, 0x70, 0x72,
  0x69, 0x6e, 0x74, 0x6c, 0x6e, 0x00, 0x20, 0x00, 0x04, 0x00, 0x08, 0x00,
  0x00, 0x00, 0x03, 0x00, 0x19, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x01, 0x00,
  0x0b, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0c, 0x00, 0x02, 0x00, 0x0d, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 0x11, 0x00, 0x01, 0x00, 0x12, 0x00,
  0x00, 0x00, 0x1d, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x05, 0x2a,
  0xb7, 0x00, 0x01, 0xb1, 0x00, 0x00, 0x00, 0x01, 0x00, 0x13, 0x00, 0x00,
  0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x14,
  0x00, 0x15, 0x00, 0x01, 0x00, 0x12, 0x00, 0x00, 0x00, 0x24, 0x00, 0x02,
  0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0xb2, 0x00, 0x02, 0x2b, 0xb6, 0x00,
  0x03, 0xb1, 0x00, 0x00, 0x00, 0x01, 0x00, 0x13, 0x00, 0x00, 0x00, 0x0a,
  0x00, 0x02, 0x00, 0x00, 0x00, 0x09, 0x00, 0x07, 0x00, 0x0a, 0x01, 0x00,
  0x00, 0x16, 0x00, 0x15, 0x00, 0x00, 0x00, 0x09, 0x00, 0x17, 0x00, 0x18,
  0x00, 0x01, 0x00, 0x12, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x02, 0x00, 0x02,
  0x00, 0x00, 0x00, 0x0f, 0xbb, 0x00, 0x04, 0x59, 0xb7, 0x00, 0x05, 0x4c,
  0x2b, 0x12, 0x06, 0xb6, 0x00, 0x07, 0xb1, 0x00, 0x00, 0x00, 0x01, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0f, 0x00,
  0x08, 0x00, 0x10, 0x00, 0x0e, 0x00, 0x11, 0x00, 0x01, 0x00, 0x19, 0x00,
  0x00, 0x00, 0x02, 0x00, 0x1a
};
unsigned int JavaTest_class_len = 677;

static void
javaBciReadAndWriteClassWithoutModifications(void** state)
{
    java_class_t *classInfo = javaReadClass(JavaTest_class);
    assert_non_null(classInfo);

    assert_int_equal(classInfo->methods_count, 4);
    assert_int_equal(classInfo->fields_count, 3);
    int methodIndex = javaFindMethodIndex(classInfo, "print", "(Ljava/lang/String;)V");
    assert_int_equal(methodIndex, 1);

    methodIndex = javaFindMethodIndex(classInfo, "nativeMethod", "(Ljava/lang/String;)V");
    assert_int_equal(methodIndex, 2);

    methodIndex = javaFindMethodIndex(classInfo, "main", "([Ljava/lang/String;)V");
    assert_int_equal(methodIndex, 3);

    unsigned char *dest = malloc(JavaTest_class_len);
    javaWriteClass(dest, classInfo);
    javaDestroy(&classInfo);
    assert_null(classInfo);

    assert_true(memcmp(JavaTest_class, dest, JavaTest_class_len) == 0);
    free(dest);
}

int
main(int argc, char* argv[])
{
    printf("running %s\n", argv[0]);

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(javaBciReadAndWriteClassWithoutModifications),
    };
    return cmocka_run_group_tests(tests, groupSetup, groupTeardown);
}
