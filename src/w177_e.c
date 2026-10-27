typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 h7c[1]; } GH;
extern GH *D_004C2794;
extern s32 D_004C13C4[2];
extern s32 D_004C13C8[2];
extern s32 D_004C13CC[2];
void func_002FC9B0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        *(s32 **)(p + 0x408) = D_004C13C4;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        *(s32 **)(p + 0x408) = D_004C13C8;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(s32 **)(p + 0x408) = D_004C13CC;
        p[0x1BB] = 2;
        break;
    }
    t = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
typedef struct { u8 p0[6]; u8 b6; u8 p7[0x34-7]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0x1B7-0x70]; u8 b1b7; u8 p1b8[0x1E6-0x1B8]; u8 b1e6; u8 p1e7[0x20D-0x1E7]; u8 b20d; u8 p20e[0x430-0x20E]; f32 f430; } PK;
extern f32 D_004C0D88[2];
void func_002BA710(PK *p) {
    extern void func_00175700(PK *);
    extern void func_001757E0(PK *, s32, s32);
    f32 *a, *b;
    f32 f;
    func_00175700(p);
    a = &p->f60;
    b = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= p->f430) {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->f38 = p->f430;
        p->b20d = 0;
        *a = 0;
        *b = 0;
        if (p->b1e6 != 0) f = D_004C0D88[p->b1b7]; else f = -D_004C0D88[p->b1b7];
        p->f68 = f;
        func_001757E0(p, 0x15, 7);
    }
}
extern s32 D_004C0E18[2];
extern s32 D_004C0E1C[2];
extern s32 D_004C0E20[2];
void func_002C5F90(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 t;
    u8 *q;
    q = p + 0x2B8;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = D_004C0E18;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        func_001E3710(p, 0x15);
        *(s32 **)(p + 0x408) = D_004C0E1C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        func_001E3710(p, 0x16);
        *(s32 **)(p + 0x408) = D_004C0E20;
        p[0x1BB] = 2;
        q[2] = 0;
        break;
    }
    t = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}
extern u16 D_004D18DC[];
extern u8 D_004D18DB[];
void func_0035CB20(u8 *p, u8 *q) {
    extern void func_001E7F60();
    u8 *s;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    s = q + 0x2B8;
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) {
        if (*(s8 *)(p + 0x1B4) != 0) {
            *(s8 *)(q + 0x1B4) = *(s8 *)(p + 0x1B4);
            *(s8 *)(p + 0x1B4) = *(s8 *)(p + 0x1B4) - 1;
        } else {
            p[0x1B5] = 0x57;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7c[p[2]]++;
            *(u16 *)(p + 0x1C0) |= 0x40;
            func_001E7F60(p);
        }
        if (s[1] != 0) {
            p[5]++;
            p[0x1B5] = *(s8 *)(q + 0x20) + 0x3F;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->h7c[p[2]]++;
        }
    }
}
typedef struct { u8 p0[0x2E]; s8 b2e; u8 p2f[0x92-0x2F]; s8 b92; u8 p93[0x9C-0x93]; s8 b9c; } GL;
extern GL *D_004C2840;
void func_001529A0(void) {
    extern s32 func_0016D130(void);
    extern void func_00153710(s32);
    extern void func_00153590(void);
    extern void func_001536C0(void);
    extern void func_00152AD0(void);
    extern void func_001534D0(s32);
    extern void func_00153390(void);
    extern void func_00153350(s32);
    extern void func_00153250(void);
    extern void func_00153310(void);
    extern void func_003ED1C0(s32, s32);
    extern void func_00153A40(s32, s32);
    extern void func_0016DF90(void);
    s32 r = func_0016D130();
    if (r != 0) {
        if (r == 1) {
            func_00153710(0xE);
            func_00153590();
            func_001536C0();
            if (D_004C2840->b92 < 2) func_00153710(0x12);
        } else {
            func_00152AD0();
            func_00153590();
            func_001534D0(0xB);
            func_00153390();
        }
    } else {
        if (D_004C2840->b9c == 0) {
            func_00153350(5);
            func_00153250();
            func_00153310();
        }
        func_00153350(7);
        func_003ED1C0(0, 0);
        func_00153710(0xE);
        func_00152AD0();
        func_001534D0(0xB);
        func_001536C0();
        func_00153390();
        func_00153710(0x12);
    }
    func_00153A40(4, 5);
    if (D_004C2840->b2e == 1) func_0016DF90();
}
