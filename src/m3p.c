typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_00456D50[];
extern u8 D_00457D00[];

s32 func_0028E100(u8 *p) {
    u8 *s = p + 0x2B8;
    if (p[0x2BB] != 0 || func_00189310(p, D_00456D50, p + 0x3A8) == 0) return 0;
    func_0018A990(p, p + 0x3A8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0xC;
    func_00186A60(p, 0x15);
    if ((s8)p[0x539] == 0) {
        s[0x1A] = 0;
    } else {
        s[0x1A] = p[0x212];
    }
    return 1;
}

extern u8 D_004D18A0;
extern s32 func_00175700();
extern s16 func_00182E80();
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00356B50();
void func_00356AB0(u8 *p) {
    s8 i;
    for (i = 0; i <= 7; i++) {
        u8 *q = func_003DA750(0, 1, 1);
        if (q != 0) {
            *(void **)(q + 0x10) = func_00356B50;
            q[0x20] = 2;
            q[0x21] = i;
            *(u32 *)(q + 0x18) = *(u32 *)(p + 0x18);
            *(u8 **)(q + 0x14) = p;
            q[1] = p[1];
            *(s16 *)(q + 0x26) = 0x901;
            q[7] = p[7];
        }
    }
}

extern void func_0011D8F8(u8 *, s32, s32);
extern void func_0018EA00(u8 *, u8 *);
extern void func_0018E810(u8 *, u8 *);
extern void func_0018E790(u8 *);
extern void func_0018E6C0(u8 *);
void func_0018CDF0(u8 *p, u8 *q) {
    s8 t;
    func_0011D8F8(p + 0x370, 0, 8);
    p[0x24A] = 0x78;
    t = *(s8 *)(p + 0x246);
    p[0x24D] = t;
    if (t == 0) p[0x24D] = 0x10;
    func_0018EA00(p, q);
    func_0018E810(p, q);
    if (p[0x20D] == 2) {
        func_0018E790(p);
    } else {
        func_0018E6C0(p);
        *(s16 *)(p + 0x1C) = 2;
        p[0x20D] = 2;
    }
}

extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
void func_002B02E0(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        func_001843A0(p);
    } else {
        s32 r = func_00175700(p);
        if ((s8)r < 0) func_00184540(p);
    }
}

extern V3 D_00444388;
extern V3 D_00444398;
extern void func_00150EC0();
void func_00150E10(u8 *p, s16 x) {
    u8 *q = func_003DA750(0, 0xD, 1);
    if (q != 0) {
        q[0x13C] = 1;
        *(void **)(q + 0x10) = func_00150EC0;
        *(s16 *)(q + 0xCC) = x;
        *(u8 **)(q + 0x84) = p;
        *(s32 *)(q + 0xD0) = 0x11;
        *(V3 *)(q + 0x34) = D_00444388;
        *(V3 *)(q + 0x50) = D_00444398;
    }
}

