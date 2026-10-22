typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s8 p0[2]; s8 b2; s8 b3; s8 b4; s8 b5; s8 b6; s8 b7;
    u8 p8[0x11]; s8 b19;
    u8 p1a[0x10]; s8 b2a;
    u8 p2b[0x21]; s8 b4c;
    u8 p4d[3]; s8 b50; s8 b51;
    u8 p52[0x33]; s8 b85; u8 p86; s8 b87; s8 b88;
    u8 p89[2]; s8 b8b; s8 b8c; u8 p8d[2]; s8 b8f;
    u8 p90[0xD]; s8 b9d; u8 p9e; s8 b9f;
    u8 pa0[0x13]; s8 bb3;
} G;

extern G *D_004C2840;
extern s8 D_004D18DE[];
typedef struct {
    u8 p0[0x4E8]; s32 w4e8; s32 w4ec; u8 p4f0[0x28]; u32 w518; u32 w51c;
    u8 p520[0x19]; s8 b539; u8 p53a[1]; s8 b53b; u8 p53c[6]; s8 b542; s8 b543;
    u8 p544[4]; s32 w548; s32 w54c; u8 p550[4]; u8 u554; u8 u555; u8 u556;
    u8 p557[0x5B8 - 0x557];
} P;
extern P D_004F20B0[];
extern P D_004F2668;
extern s8 D_004F25F0[], D_004F3160[], D_004F3CD0[];
extern u8 D_004F2601[];

void func_00171DB0(void)
{
    extern void func_00172370(s32);
    extern void func_00127FA0();
    extern void func_00127C50();
    extern void func_00131340();
    extern void func_001723C0();
    extern void func_001E40E0();
    extern void func_001E4140(void);
    extern void func_0016EE50();
    extern void func_003DAC00();
    extern void func_00326AF0();
    extern void func_003DA9D0(s32);
    extern void func_001529A0();
    extern void func_003D7310(void *);

    P *p0, *p1;
    s32 i;
    u8 t;

    D_004C2840->b3 = D_004C2840->b3 + 1;
    D_004C2840->b4 = 0;
    D_004C2840->b5 = 0;
    D_004C2840->b6 = 0;
    D_004C2840->b7 = 0;
    D_004C2840->b19 = 1;
    if (D_004C2840->b8c != 0) {
        D_004C2840->b2 = 4;
        D_004C2840->b3 = 0;
    }
    if (D_004C2840->b8f != 0) {
        if (D_004D18DE[0] == 1) D_004C2840->b9f = 1;
        else D_004C2840->b9f = 0;
    } else {
        if (D_004C2840->b9d == 1) D_004C2840->b9f = 0;
        else D_004C2840->b9f = 1;
    }
    if (D_004D18DE[0] < 0) {
        D_004C2840->b88 = 0;
        func_00172370(3);
    } else {
        D_004C2840->b88 &= 1 << D_004D18DE[0];
        func_00172370(3 - D_004C2840->b88);
    }
    if (D_004C2840->b2a != 0) D_004C2840->b88 = 0;
    if ((i = D_004D18DE[0]) >= 0) {
        s32 o = i ^ 1;
        P *me = &D_004F20B0[i];
        s8 t;
        s32 u;
        if (D_004C2840->b8f != 0) {
            t = me->b543 + 1;
            me->b543 = t;
            if (t > 99) me->b543 = 99;
            if (me->b53b < me->b543) me->b53b = me->b543;
            D_004C2840->b85 = me->b542;
        } else if (me->b539 == 0) {
            s32 off = o * 0x5B8;
            D_004C2840->b85 = D_004C2840->b85 + 1;
            me->b542 = D_004C2840->b85;
            u = D_004F25F0[off];
            if (u < 0x20) me->w518 |= 1 << u;
            else me->w51c |= 1 << (u - 0x20);
            u = D_004F3160[off];
            if (u < 0x20) me->w518 |= 1 << u;
            else me->w51c |= 1 << (u - 0x20);
            u = D_004F3CD0[off];
            if (u < 0x20) me->w518 |= 1 << u;
            else me->w51c |= 1 << (u - 0x20);
        }
    }
    p0 = D_004F20B0;
    p1 = &D_004F2668;
    if (D_004C2840->b4c == 1 || D_004C2840->b4c == 5) {
        switch (D_004D18DE[0]) {
        case 0:
            { u32 q = p0->u554; p0->u554 = q + 1; if ((u8)(q + 1) > 99) p0->u554 = 99; }
            { u32 q = p1->u555; p1->u555 = q + 1; if ((u8)(q + 1) > 99) p1->u555 = 99; }
            p0->b543 = p0->u554;
            break;
        case 1:
            { u32 q = p1->u554; p1->u554 = q + 1; if ((u8)(q + 1) > 99) p1->u554 = 99; }
            { u32 q = p0->u555; p0->u555 = q + 1; if ((u8)(q + 1) > 99) p0->u555 = 99; }
            p1->b543 = p1->u554;
            break;
        case -1:
            { u32 q = p0->u556; p0->u556 = q + 1; if ((u8)(q + 1) > 99) p0->u556 = 99; }
            { u32 q = p1->u556; p1->u556 = q + 1; if ((u8)(q + 1) > 99) p1->u556 = 99; }
            break;
        }
    } else {
        if (D_004C2840->b8f != 0) {
            func_00127FA0(p0);
            func_00127FA0(p1);
        } else {
            if (p0->b539 == 0) {
                p0->w548 = p0->w4ec;
                p0->w54c = p0->w4e8;
                func_00127C50(p0);
            }
            if (p1->b539 == 0) {
                p1->w548 = p1->w4ec;
                p1->w54c = p1->w4e8;
                func_00127C50(p1);
            }
        }
    }
    switch (D_004C2840->b4c) {
    case 0:
        if (D_004C2840->b8c != 0) {
            D_004C2840->b51 = 1;
            { s32 k = D_004C2840->bb3 ? 0x32 : 0x64; func_00131340(k * (D_004C2840->b87 + 1)); }
        }
        break;
    case 1:
    case 2:
        func_001723C0();
        break;
    case 5:
    case 7:
        if (D_004F2601[D_004D18DE[0] * 0x5B8] == 0 && D_004C2840->b8c != 0) func_00131340(0x3E8);
        break;
    }
    func_001E40E0();
    func_001E4140();
    func_0016EE50();
    func_003DAC00();
    func_00326AF0();
    func_003DA9D0(3);
    func_003DA9D0(4);
    func_003DA9D0(1);
    func_003DA9D0(2);
    func_003D7310(func_001529A0);
}
