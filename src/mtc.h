#ifndef __MTC_H__
#define __MTC_H__
#include "format.h"
#include "log.h"
#include "transport.h"

typedef struct _mtc_t mtc_t;

// Constructors Destructors
mtc_t*              mtcCreate();
void                mtcDestroy(mtc_t**);

// Accessors
int                 mtcSend(mtc_t*, const char* msg);
int                 mtcSendMetric(mtc_t*, event_t*);
void                mtcFlush(mtc_t*);

// Setters (modifies mtc_t, but does not persist modifications)
int                 mtcNeedsConnection(mtc_t *);
int                 mtcConnect(mtc_t *);
int                 mtcDisconnect(mtc_t *);
void                mtcTransportSet(mtc_t*, transport_t*);
void                mtcFormatSet(mtc_t*, format_t*);


#endif // __MTC_H__

