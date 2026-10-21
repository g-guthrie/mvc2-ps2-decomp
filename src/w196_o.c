typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
#include "cri_sj_ring_buffer_types.h"
#include "runtime_span_types.h"

extern CriSjInterface D_00494DA8;
extern struct _UUID D_004BEA20;
extern void D_0040FD18(void *context, s32 error);

struct RuntimeQueryContext *func_0040FDC0(s32 mode, struct RuntimeNode *pool, s32 bytes)
{
    extern void func_0040FEF8(SJ_OBJ *object);
    s32 i;
    struct RuntimeQueryContext *e;
    for (i = 0; i < 0x40; i++) {
        if (D_00494DD8[i].active == 0) break;
    }
    if (i == 0x40) return 0;
    e = &D_00494DD8[i];
    e->active = 1;
    e->interface = &D_00494DA8;
    e->mode = mode;
    e->uuid = &D_004BEA20;
    e->pool = pool;
    e->capacity = bytes / 16;
    e->fallback = D_0040FD18;
    e->fallbackArgument = e;
    func_0040FEF8((SJ_OBJ *)e);
    return e;
}
