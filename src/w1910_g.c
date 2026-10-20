#include "cri_sj_ring_buffer_types.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_00490D78[];
extern UUID D_004BEA10;

SJRBFRecord *func_0040F5E0(s8 *buf, s32 bsize, s32 xsize)
{
    extern void func_0040EFE0();
    extern void func_0040EFF8();
    extern void func_0040F530(void *, int);
    SJRBFRecord *e;
    s32 i;
    func_0040EFE0();
    for (i = 0; i < 0x100; i++) {
        if (D_00490DA8[i].used == 0) break;
    }
    if (i == 0x100) {
        e = 0;
    } else {
        e = &D_00490DA8[i];
        e->used = 1;
        e->sj.vtbl = (struct _sj_vtbl *)D_00490D78;
        e->buf = buf;
        e->bsize = bsize;
        e->xsize = xsize;
        e->uuid = &D_004BEA10;
        e->err_func = func_0040F530;
        e->err_obj = e;
        func_0040F728(&e->sj);
    }
    func_0040EFF8();
    return e;
}
