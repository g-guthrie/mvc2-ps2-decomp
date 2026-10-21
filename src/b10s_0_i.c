#include "cri_sj_ring_buffer_types.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
s32 func_0040F750(SJ_OBJ *object, s32 k) {
    SJRBFRecord *o = (SJRBFRecord *)object;
    if (k == 1) return o->unk0C;
    if (k == 0) return o->unk10;
    if (o->err_func != 0) {
        o->err_func(o->err_obj, -3);
    }
    return 0;
}
