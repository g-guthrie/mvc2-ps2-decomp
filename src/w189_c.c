typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w189_c.c "-O3 -Op -sdatathreshold 8" */
typedef struct G248 { u8 pad[0x7C]; s16 h7C[1]; } G248;
extern G248 *D_004C2794;
extern s32 data_s8_004C03B0[2];
extern s32 D_004C03B4[2];
extern s32 D_004C03B8[2];
extern void func_001E3710(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_00248B10(u8 *p) {
    u32 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = data_s8_004C03B0;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(s32 **)(p + 0x408) = D_004C03B4;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        func_001E3710(p, 0x16);
        *(s32 **)(p + 0x408) = D_004C03B8;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    t = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}

typedef struct E12F { u16 h0; u16 h2; u16 h4; u16 h6; u8 pad[0x0C]; } E12F;
typedef struct T12F { u8 pad[0x106]; u16 h106; u16 h108; } T12F;
extern s32 D_004C2874;
extern s32 D_004D17A8[];
extern u8 D_004D17C2[];
extern E12F D_004F4480[];
extern T12F *D_004C2840;
extern s32 D_004C2870;
extern void func_0012FA40(s32);
s32 func_0012F930(s32 arg) {
    s32 r = 0;
    s32 i;
    s32 off;
    E12F *e;
    u32 a;
    u32 m = 0x8000;
    if (D_004C2874 != 0) return 0;
    if (D_004D17A8[0] != 0) return 0;
    if (D_004D17C2[0] != 0) return 0;
    i = 0;
    off = 0;
    do {
        e = (E12F *)((u8 *)D_004F4480 + off);
        a = e->h0;
        if (((a & m) && (e->h4 & 2)) || ((e->h4 & m) && (a & 2))) {
            r = 1;
            D_004C2840->h108 = 0;
            D_004C2840->h106 = 0;
            switch (arg) {
            case 0:
                D_004C2870 = r;
                break;
            case 1:
                func_0012FA40(r);
                break;
            }
        }
        i++;
        off += 0x14;
    } while (i < 2);
    return r;
}

typedef struct P249 {
    u8 pad0[2]; u8 b2; u8 pad3[0x34 - 3]; f32 f34; u8 pad38[0x140 - 0x38]; s16 h140; u8 pad142[0x151 - 0x142];
    s8 b151; u8 pad152[0x160 - 0x152]; u16 h160; u8 pad162[0x1B2 - 0x162]; u8 b1B2; u8 pad1B3[2]; u8 b1B5;
    u8 pad1B6[0x1C0 - 0x1B6]; u16 h1C0; u8 pad1C2[0x1D8 - 0x1C2]; s32 w1D8; u8 pad1DC[0x1FC - 0x1DC]; u8 b1FC;
} P249;
void func_00249280(P249 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    u16 a;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    switch (p->b1FC) {
    case 2:
        if (p->b151 != 0) {
            p->b151 = 0;
            p->b1B5 = 2;
            p->b1B2 = p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7C[p->b2]++;
        }
        break;
    case 1:
        if (p->b151 != 0) {
            p->b151 = 0;
            p->b1B5 = 1;
            p->b1B2 = p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7C[p->b2]++;
        }
        break;
    case 0:
        break;
    }
    a = p->h160;
    if (a != 0) {
        if (p->h140 == 0) {
            p->f34 += 1.6666666269302368f * (f32)(s16)a;
        } else {
            p->f34 -= 1.6666666269302368f * (f32)(s16)a;
        }
        p->h160 = 0;
    }
}
