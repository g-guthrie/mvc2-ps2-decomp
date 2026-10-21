#ifndef MVC2_STREAM_GROUP_TYPES_H
#define MVC2_STREAM_GROUP_TYPES_H
#include "runtime_span_types.h"

typedef unsigned short u16;
typedef signed short s16;

struct QueryStream;

typedef struct StreamGroup {
    s8 active;                         /* 0x00 */
    s8 lifecycle;                      /* 0x01 */
    u8 stream_count;                   /* 0x02 */
    s8 mode;                           /* 0x03 */
    void *engine;                      /* 0x04 */
    void *resource;                    /* 0x08 */
    struct QueryStream *streams[2];                  /* 0x0C */
    struct RuntimeSpan request_span;   /* 0x14 */
    struct RuntimeSpan stream_spans[2];/* 0x1C */
    s32 progress_2c;                   /* 0x2C */
    s32 progress_30;                   /* 0x30 */
    s32 progress_34;                   /* 0x34 */
    s32 maximum_available;             /* 0x38 */
    s32 remaining_limit;               /* 0x3C */
    s32 consumed;                      /* 0x40 */
    s32 progress_44;                   /* 0x44 */
    void (*callback_48)(void *);       /* 0x48 */
    void *callback_argument_4c;        /* 0x4C */
    void (*callback_50)(void *, s32, s32, s32); /* 0x50 */
    void *callback_argument_54;        /* 0x54 */
    u8 transfer_buffer[0x40];           /* 0x58 */
    s32 result_98;                     /* 0x98 */
} StreamGroup;

typedef char StreamGroup_size_check[sizeof(StreamGroup) == 0x9C ? 1 : -1];
extern StreamGroup D_00484100[16];

#endif
