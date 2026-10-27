typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_003BF050();

void func_003BEF10(u8 *a, u16 b)
{
    u8 *o;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(u32 *)(o + 0x10) = (u32)func_003BF050;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        *(s16 *)(o + 0x26) = 0x3602;
        o[0x20] = b >> 8;
        o[0x21] = b;
        o[0x22] = 0;
    }
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(u32 *)(o + 0x10) = (u32)func_003BF050;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        *(s16 *)(o + 0x26) = 0x3602;
        o[0x20] = b >> 8;
        o[0x21] = b;
        o[0x22] = 4;
    }
}

extern f32 D_0045EF08[];
extern f32 D_0045EED0[];
extern void func_0033D580(u8 *);
extern void func_003DAA40(u8 *);

void func_0033D490(u8 *p)
{
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += D_0045EF08[p[0x20]];
    switch (p[4]) {
    case 0:
        if (*(f32 *)(p + 0x38) <= -85.0f) {
            func_0033D580(p);
            p[4]++;
        }
        break;
    case 1:
        if (*(f32 *)(p + 0x38) <= D_0045EED0[p[0x20] * 6]) {
            func_003DAA40(p);
        }
        break;
    }
}

extern void func_003CAB20(u8 *, u8 *, unsigned int);
extern void func_003CAB00(u8 *, u8 *);
extern int func_00174470(const void *);
extern void func_001E3210(u8 *, s32);
extern void func_001E7F60(u8 *);
extern void func_00175700(u8 *);

void func_003CB650(u8 *p, u8 *q)
{
    s32 v;
    s32 t;
    if (q[5] != 0 && *(s8 *)(p + 0x1B2) == 0) {
        func_003CAB20(p, q, 0xF);
        return;
    }
    if (func_00174470(p) == 0) {
        func_003CAB00(p, q);
        return;
    }
    *(s32 *)(q + 0x2B8) = 4;
    if ((*(s8 *)(p + 0x1B2) & 0x11) != 0) {
        func_003CAB20(p, q, 0xD);
        return;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        v = p[0x15B];
        t = 0x2E;
        if (v > 0x2C) {
            t = v + 1;
        }
        func_001E3210(p, t & 0xFF);
        func_003CAB20(p, q, 8);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    {
        s16 h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) {
            func_001E3210(p, p[0x15B]);
        }
    }
    func_001E7F60(p);
}

typedef struct { u8 pad0[0x1E4]; u8 b1e4; u8 pad1[1]; u8 b1e6; u8 b1e7; u8 pad2[0x211 - 0x1E8]; s8 b211; u8 pad3[0x220 - 0x212]; s32 w220; u8 pad4[0x460 - 0x224]; s32 w460; u8 pad5[4]; s32 w468; s16 h46c; u8 pad6[0x4B6 - 0x46E]; s8 b4b6; u8 pad7[0x4F0 - 0x4B7]; s16 h4f0; } PS;
extern s32 D_004D18EC;
extern s32 func_001688C0(PS *, s32);
extern s32 func_0016A8B0(PS *, s32, s32);
extern s32 func_00166C80(PS *, s32, s32);

s32 func_00166710(PS *p, s32 a1)
{
    s32 r;
    s32 t;
    s32 c;
    if (p->b1e4 != p->w468) {
        return func_001688C0(p, a1);
    }
    t = p->b4b6 - 1;
    p->b4b6 = t;
    if ((s8)t == 0) {
        r = func_001688C0(p, a1);
    } else if (*(u8 *)&D_004D18EC != 0) {
        r = func_001688C0(p, a1);
    } else if ((c = p->b211) != 0 && (c & (2 >> p->b1e6)) != 0) {
        r = func_001688C0(p, a1);
    } else if (func_0016A8B0(p, p->w220, p->w460) != 0) {
        r = func_00166C80(p, a1, 1);
    } else {
        p->h4f0 = p->h46c;
        p->b1e7 = 0;
        r = 0;
    }
    return r;
}
