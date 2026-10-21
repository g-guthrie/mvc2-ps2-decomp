#include "cri_sj_ring_buffer_types.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_0040FC08(SJ_OBJ *object, s32 m, s32 lim, s32 *out)
{
    SJRBFRecord *o = (SJRBFRecord *)object;
    extern void func_0040EFE0(void);
    extern void func_0040EFF8(void);
    s32 r;
    func_0040EFE0();
    if (m == 0) {
        r = (o->bsize - o->unk14) + o->xsize;
        if (o->unk10 < r) r = o->unk10;
        r = (r < lim) ? r : lim;
    } else if (m == 1) {
        r = (o->bsize - o->unk18) + o->xsize;
        if (o->unk0C < r) r = o->unk0C;
        r = (r < lim) ? r : lim;
    } else {
        r = 0;
        if (o->err_func != 0) o->err_func(o->err_obj, -3);
    }
    *out = r;
    func_0040EFF8();
    return r == lim;
}
