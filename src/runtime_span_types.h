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

struct RuntimeQueryContext
{
    u8 unknown0[5];
    s8 mode;
    u8 unknown6[6];
    struct RuntimeNode *pool;
    s32 capacity;
    struct RuntimeNode *moved;
    struct RuntimeNode *entries[4];
    RuntimeFallback fallback;
    void *fallbackArgument;
};

#endif
