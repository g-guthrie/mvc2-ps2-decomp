typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
#include "cri_sj_ring_buffer_types.h"

extern void func_0040EFE0(void);

extern void func_0040AAB8(s32 a, s32 *out);
s32 func_0040ADC8(s32 a) {
    s32 v[12];
    func_0040AAB8(a, v);
    return v[0] != 0;
}

extern char D_004BC460[];
extern void func_003FB128(char *s);
s32 func_004025C0(u8 *p) {
    if (p == 0) {
        func_003FB128(D_004BC460);
        return -1;
    }
    return *(s32 *)(p + 0x4C);
}

extern char D_004BE8A8[];
extern void func_0011EB60(char *s);
void func_0040EE28(s32 a, s32 b) {
    if (b != 0x10) {
        func_0011EB60(D_004BE8A8);
    }
}

extern void func_0011D8F8(s32 *p, s32 v, s32 n);
extern void func_0040EFF8(void);
void func_0040F6D0(SJ_OBJ *object) {
    s32 *p = (s32 *)object;
    func_0040EFE0();
    if (p != 0) {
        func_0011D8F8(p, 0, 0x40);
        p[1] = 0;
    }
    func_0040EFF8();
}

extern s32 D_00632140[];
extern void func_00409708(s32 a, s32 *b, s32 c, s32 d, s32 e);
void func_00410A80(s32 a, s32 b, s32 *c) {
    s32 *d = D_00632140;
    s32 x = c[0];
    d[0] = a;
    d[1] = b;
    d[2] = x;
    d[3] = c[1];
    func_00409708(0x28, d, 4, 0, 0);
}

extern void func_00118F48(f32 *x, s32 *out);
s32 func_00118FA8(f32 x) {
    s32 v[4];
    f32 t = x;
    func_00118F48(&t, v);
    if ((v[0] ^ 2) == 0) {
        return 0;
    }
    if (v[2] < 0) {
        return 0;
    }
    if (v[2] >= 0x1F) {
        return v[1] ? (s32)0x80000000 : 0x7FFFFFFF;
    }
    {
        u32 r = (u32)v[3] >> (0x1E - v[2]);
        return v[1] ? -(s32)r : (s32)r;
    }
}

#include "HtciFileRequest.h"
extern HtciFileRequest D_00489220[13];
HtciFileRequest *func_0040B6A8(void) {
    HtciFileRequest *r = 0;
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_00489220[i].slot_state == 0) {
            r = &D_00489220[i];
        }
    }
    return r;
}
