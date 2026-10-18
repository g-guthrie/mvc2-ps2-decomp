typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0032C180(s32);
extern void func_00123760(void);
extern void func_001E3CE0(s32);
extern u8 D_00583B9B[];
extern s8 *D_004C2840;

extern void func_003B6FF0(void *, void *, s16 *);
extern void func_003B70F0(void *, void *);
void func_003B6CB0(u8 *a, u8 *b) {
    s16 *h = (s16 *)(a + 0x88);
    *(s8 *)(a + 0x92) = *(s8 *)(b + 0x2C1);
    if (*(s8 *)(a + 0x92) < 0) {
        u32 t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
    } else {
        s16 v = *h + 1;
        *h = v;
        *h = *h & 1;
        func_003B6FF0(a, b, h);
        func_003B70F0(a, b);
    }
}

extern u8 *func_003DA750(s32, s32, s32);
extern void func_001BBE00(void);
u8 *func_001BBD80(u8 *a, u8 b) {
    u8 *o;
    if ((o = func_003DA750(0, 3, 0)) == 0) return 0;
    *(void **)(o + 0x10) = (void *)func_001BBE00;
    *(u8 **)(o + 0x18) = a;
    *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
    *(s16 *)(o + 0x26) = 0x1706;
    *(u32 *)(o + 0xD0) = *(u16 *)(*(u8 **)(o + 0x18) + 0x168);
    o[0x23] = b;
    return o;
}

extern u8 *D_004C2794;
extern void func_001757E0(void *, s32, s32);
extern void func_001F9A40(void *);
void func_001FB110(u8 *p) {
    u32 t = p[6];
    s16 *q;
    p[6] = t + 1;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1B5] = p[0x1B7] ? 0x4E : 0x4E;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
    q[0x7C / 2] = q[0x7C / 2] + 1;
    *(s16 *)(p + 0x1C) = 0;
    func_001757E0(p, 0x15, 7);
    func_001F9A40(p);
}

extern void func_001555A0(void *, s32, s32, s32);
void func_00155490(void *a) {
    func_001555A0(a, 6, 3, 0);
    func_001555A0(a, 8, 4, 0);
    func_001555A0(a, 8, 4, 1);
    func_001555A0(a, 8, 4, 2);
    func_001555A0(a, 8, 4, 3);
    func_001555A0(a, 8, 4, 4);
    func_001555A0(a, 8, 4, 5);
}