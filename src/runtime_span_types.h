#ifndef MVC2_RUNTIME_SPAN_TYPES_H
#define MVC2_RUNTIME_SPAN_TYPES_H

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

struct RuntimeSpan
{
    s32 start;
    s32 length;
};

struct RuntimeNode
{
    struct RuntimeNode *next;
    u32 unknown;
    struct RuntimeSpan span;
};

typedef void (*RuntimeFallback)(void *argument, s32 error);

struct _sj_vtbl;
struct _UUID;

struct RuntimeQueryContext
{
    struct _sj_vtbl *interface;
    s8 active;
    s8 mode;
    u8 padding6[2];
    struct _UUID *uuid;
    struct RuntimeNode *pool;
    s32 capacity;
    struct RuntimeNode *moved;
    struct RuntimeNode *entries[4];
    RuntimeFallback fallback;
    void *fallbackArgument;
};
typedef char RuntimeQueryContext_size_check[sizeof(struct RuntimeQueryContext) == 0x30 ? 1 : -1];
extern struct RuntimeQueryContext D_00494DD8[64];

#endif
