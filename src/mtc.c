#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"
#include "mtc.h"

struct _mtc_t
{
    transport_t* transport;
    format_t* format;
    int metric_disabled;
};

mtc_t*
mtcCreate()
{
    mtc_t* mtc = calloc(1, sizeof(mtc_t));
    if (!mtc) {
        DBG(NULL);
        return NULL;
    }

    // TBD.  This is a quick and dirty way to disable metric output.
    // Added 31-Jan-2020 for a demo.
    mtc->metric_disabled = (getenv("SCOPE_METRIC_DISABLE") != NULL);

    return mtc;
}

void
mtcDestroy(mtc_t** mtc)
{
    if (!mtc || !*mtc) return;
    mtc_t* m = *mtc;
    transportDestroy(&m->transport);
    fmtDestroy(&m->format);
    free(m);
    *mtc = NULL;
}

int
mtcSend(mtc_t* mtc, const char* msg)
{
    if (!mtc || !msg) return -1;

    return transportSend(mtc->transport, msg);
}

int
mtcSendMetric(mtc_t* mtc, event_t* e)
{
    if (!mtc || !e) return -1;

    if (mtc->metric_disabled) return 0;

    char* msg = fmtStatsDString(mtc->format, e, NULL);
    int rv = mtcSend(mtc, msg);
    if (msg) free(msg);
    return rv;
}

void
mtcFlush(mtc_t* mtc)
{
    if (!mtc) return;
    transportFlush(mtc->transport);
}

int
mtcNeedsConnection(mtc_t* mtc)
{
    if (!mtc) return 0;
    return transportNeedsConnection(mtc->transport);
}

int
mtcConnect(mtc_t* mtc)
{
    if (!mtc) return 0;
    return transportConnect(mtc->transport);
}

int
mtcDisconnect(mtc_t* mtc)
{
    if (!mtc) return 0;
    return transportDisconnect(mtc->transport);
}

void
mtcTransportSet(mtc_t* mtc, transport_t* transport)
{
    if (!mtc) return;

    // Don't leak if mtcTransportSet is called repeatedly
    transportDestroy(&mtc->transport);
    mtc->transport = transport;
}

void
mtcFormatSet(mtc_t* mtc, format_t* format)
{
    if (!mtc) return;

    // Don't leak if mtcFormatSet is called repeatedly
    fmtDestroy(&mtc->format);
    mtc->format = format;
}

