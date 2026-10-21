typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
#include "cri_sj_ring_buffer_types.h"

extern u8 D_004AB388;
extern s32 D_00439920[];
extern s32 func_0011FE88(void *, s32);
extern void func_0011D8F8(void *, s32, s32);
typedef struct Obj { s32 *vt; } Obj;

typedef struct T44 { u8 b[0x44]; } T44;
extern u8 D_00487B60[];
T44 *func_00409208(u32 i) { if (i >= 8) return 0; return (T44 *)((u32)D_00487B60 + i * 0x44); }
void func_0040F180(SJ_OBJ *object) {
    s32 *p = (s32 *)object;
    if (p) { func_0011D8F8(p, 0, 0x24); p[1] = 0; }
}
typedef s32 (*VF)(void *, s32);
s32 func_0040EA98(u8 *p) {
    Obj *o = *(Obj **)(*(u8 **)(p + 8) + 8);
    s32 r = ((VF)o->vt[9])(o, 0);
    return r / 2;
}
typedef struct Item { s32 pad[2]; Obj *obj; } Item;
typedef struct Tbl { s32 pad[2]; Item *items[1]; } Tbl;
typedef struct Own { s32 pad[3]; Tbl *tbl; } Own;
u32 func_003FEFE8(Own *p, s32 i) {
    Obj *o = p->tbl->items[i]->obj;
    u32 r = ((u32 (*)(void *, s32))o->vt[9])(o, 0);
    return r >> 1;
}
