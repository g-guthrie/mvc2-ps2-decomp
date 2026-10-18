typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D1570[], D_004D1370[], D_004F7D30[], D_004F2603[][0x5B8], D_00473B70[], D_004F4484[];
extern void func_0014E770(u8 *);
extern void func_00127BB0(u8 *);
extern void func_00175700(u8 *, u8 *);
extern void func_0012F060(void);
extern float func_00117240(float);
extern float func_00116FA0(float);
extern void func_001E3710(u8 *, s32);
extern void func_00126400(void);
extern void func_00322020(u8 *, u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001E3CE0(s32);
extern void func_00178F20(u8 *, u8 *);
extern void func_003AE8A0(u8 *);
extern void func_001CABF0(u8 *);

typedef struct { s32 w[16]; } S64;

void func_003DE3A0(S64 *d, S64 *s) { *d = *s; }

void func_00127C10(void) {
    func_00127BB0(D_004D1570);
    func_00127BB0(D_004D1370);
    func_00127BB0(D_004F7D30);
}

void func_003B8AB0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    float f = *(float *)(p + 0xD4);
    u8 *r = p + 0xD0;
    if (*(u8 *)(q + 0x1E6) == 0) f = -f;
    *(float *)(p + 0x34) = *(float *)(q + 0x34) + f;
    *(float *)(p + 0x38) = *(float *)(q + 0x38) + *(float *)(r + 8);
    func_00175700(p, r);
}

void func_003DE720(float x, float *a, float *b) {
    *a = func_00117240(x);
    *b = func_00116FA0(x);
}

void func_003220F0(u8 *p, u8 *q) {
    *(u8 *)(p + 0x151) = 10;
    func_001E3710(p, 5);
    func_00126400();
    func_00322020(p, q);
}

void func_00178E10(u8 *p) {
    u32 v = *(u8 *)(p + 0x242);
    s32 t;
    u32 w;
    if ((s32)v > 0x10) {
        v = (0x20 - (s8)v) & 0x1F;
    }
    v = v & 0xFF;
    t = v + 2;
    w = (u8)(t / 4);
    func_001757E0(p, 0xD, (u8)(w + 0x10));
}

void func_0036D400(u8 *p) {
    *(u8 *)(p + 0x13C) = 1;
    *(float *)(p + 0x34) = *(float *)(*(u8 **)(p + 0x18) + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
    *(float *)(p + 0x3C) = *(float *)(*(u8 **)(p + 0x18) + 0x3C);
    *(u8 *)(p + 0x24) = 10;
    *(s32 *)(p + 0x118) = 0x3F800000;
    func_001757E0(p, 0x17, (u8)(*(u8 *)(*(u8 **)(p + 0x18) + 7) + 0x32));
}

void func_003AE260(u8 *p) {
    if (*(u8 *)(*(u8 **)(p + 0x18) + 0x1E4) != 0x16) {
        func_003AE8A0(p);
    } else {
        ((void (*)(u8 *))(*(u32 *)(D_00473B70 + *(u8 *)(p + 4) * 4)))(p);
    }
}
