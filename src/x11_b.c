typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[3]; u8 b3; u8 pad4[0x18]; s32 w1c; u8 pad20[0x68]; s8 b88; s8 b89; u8 pad8a[7]; u8 b91; u8 b92; } G19;
extern G19 *D_004C2840;

typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G27;
extern G27 *D_004C2794;
void func_0023AF00(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            p[0x1B5] = 0x1A;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7c[p[2]]++;
        }
        break;
    }
}

void func_00255380(u8 *p) {
    extern void func_00176090();
    u8 *q = p + 0x2B8;
    s32 k;
    if (p[0x1E4] != 0x14) *(u16 *)(q + 2) = 0;
    if (p[0x1E4] != 0x14) goto reset;
    if (*(u16 *)(q + 4) == 0) {
        *(u16 *)(q + 4) = 0;
        func_00176090(p, 0, 0, 1);
        return;
    }
    k = (u8)(D_004C2840->w1c % 4);
    if (k >= 2) {
        func_00176090(p, 0, 6, 1);
    } else if (k >= 0) {
        func_00176090(p, 0, 0, 1);
    } else {
reset:
        *(u16 *)(q + 4) = 0;
        func_00176090(p, 0, 0, 1);
    }
}

extern s32 D_004C2928;
extern u8 D_004F20B0[];
extern u8 D_004F2668[];
void func_0032A900(void) {
    extern void func_0032A9E0();
    extern void func_003DA6F0();
    extern void func_003D7310();
    extern void func_00152570();
    s32 v;
    func_0032A9E0(D_004F20B0);
    func_0032A9E0(D_004F2668);
    if (D_004C2928 == (v = D_004C2840->b88 | D_004C2840->b89)) {
        if (v == 3) {
            D_004C2840->b3 = 4;
        } else {
            D_004C2840->b3 = 5;
        }
        D_004F20B0[5] = 0;
        D_004F20B0[6] = 0;
        D_004F20B0[7] = 0;
        D_004F2668[5] = 0;
        D_004F2668[6] = 0;
        D_004F2668[7] = 0;
        D_004C2840->b91 = 0;
        D_004C2840->b92 = 0;
    }
    func_003DA6F0(6);
    func_003DA6F0(8);
    func_003DA6F0(1);
    func_003D7310(func_00152570);
}

typedef struct O18 { u8 pad0; u8 b1; u8 pad2[0xE]; void (*f10)(); struct O18 *f14; u8 *f18; u8 pad1c[4]; u8 b20; u8 b21; u8 pad22[4]; s16 h26; } O18;
extern s16 D_004C27A4[2];
extern void func_00348F20();
s32 func_00348C90(u8 *p) {
    extern O18 *func_003DA750();
    O18 *o;
    O18 *n;
    if (D_004C27A4[0] <= 1) return 0;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        o->f10 = func_00348F20;
        o->f18 = p;
        o->b1 = p[1];
        o->b20 = 0;
        o->b21 = 0;
        o->h26 = 0x301;
    }
    if ((n = func_003DA750(o, 1, 2)) != 0 && o != 0) {
        n->f10 = func_00348F20;
        n->f18 = p;
        n->f14 = o;
        n->b1 = p[1];
        n->b20 = 1;
        n->b21 = 0;
        n->h26 = 0x301;
        o->f14 = n;
    }
    return 0;
}

