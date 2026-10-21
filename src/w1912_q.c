#include "cri_sj_memory_types.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0040F010(void *, int);
extern CriSjInterface D_004908C8;
extern u8 D_004BE9D0[];


CriSjMemory *func_0040F0B8(char *x, s32 y) {
    s32 i;
    CriSjMemory *e;
    for (i = 0; i < 0x20; i++) {
        if (D_004908F8[i].active == 0) break;
    }
    if (i == 0x20) return 0;
    e = &D_004908F8[i];
    e->active = 1;
    e->interface = &D_004908C8;
    e->buffer = x;
    e->size = y;
    e->uuid = (struct _UUID *)D_004BE9D0;
    e->error_callback = func_0040F010;
    e->error_context = e;
    func_0040F1D0((struct SJ_OBJ *)e);
    return e;
}
