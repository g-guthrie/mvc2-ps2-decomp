#include "sony29_gs_half_offset.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef signed short s16;

typedef union {
    u64 raw;
    struct {
        u64 SCAX0 : 11;
        u64 pad0 : 5;
        u64 SCAX1 : 11;
        u64 pad1 : 5;
        u64 SCAY0 : 11;
        u64 pad2 : 5;
        u64 SCAY1 : 11;
        u64 pad3 : 5;
    } fields;
} GsScissor;

struct GsDrawContext {
    u8 pad0[0x20];
    u64 packedXY;
    u64 pad1;
    GsScissor scissor;
};

#define DEFINE_SCISSOR_SETTER(name) \
void name(GsDrawContext *ctx, s16 x, s16 y, s16 offsetY) \
{ \
    GsScissor scissor; \
    u64 raw; \
    u32 y1; \
    u32 x1; \
    s32 y1plus; \
    s32 x1plus; \
    u64 yWide; \
    u64 xWide; \
    u64 halfY1; \
    u64 halfX1; \
    u64 yScaled; \
    u64 xScaled; \
    u64 packed; \
    raw = ctx->scissor.raw; \
    scissor.raw = raw; \
    y1 = (u32)scissor.fields.SCAY1; \
    x1 = (u32)scissor.fields.SCAX1; \
    yWide = (u64)(s64)y; \
    y1plus = (s32)y1 + 1; \
    halfY1 = (u64)(s64)y1plus >> 1; \
    xWide = (u64)(s64)x; \
    x1plus = (s32)x1 + 1; \
    halfX1 = (u64)(s64)x1plus >> 1; \
    yWide -= halfY1; \
    xWide -= halfX1; \
    yScaled = yWide << 4; \
    xScaled = xWide << 4; \
    if (offsetY != 0) { \
        packed = xScaled | ((yScaled + 8) << 32); \
    } else { \
        packed = xScaled | (yWide << 36); \
    } \
    ctx->packedXY = packed; \
}

DEFINE_SCISSOR_SETTER(func_00101DF0)
DEFINE_SCISSOR_SETTER(func_00102058)
