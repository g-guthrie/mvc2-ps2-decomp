typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 t7c[1]; } G1;
extern G1 *D_004C2794;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_00269530(u8 *p)
{
    extern s8 func_00175700();
    extern void func_00269D10();
    extern void func_001757E0();
    extern u8 *func_001B3E30(u8 *, int, int);
    s8 r;
    f32 x;
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x151) == 3) {
        p[6] = 5;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x1B5] = 0x43;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->t7c[p[2]]++;
        func_001757E0(p, 0x16, 0x34);
        D_004F1F45[0] = 1;
        D_004F1F46[0] = 1;
        return;
    }
    r = func_00175700();
    if (r < 0) {
        func_00269D10(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        func_001B3E30(p, 0x16, 0xD);
        func_001B3E30(p, 0x17, 0xD);
        func_001B3E30(p, 0x18, 0xD);
    } else if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        if (*(s16 *)(p + 0x140) != 0) {
            x = 26.666666030883789f;
        } else {
            x = -26.666666030883789f;
        }
        *(f32 *)(p + 0x34) += x;
    }
}

void func_002DF8C0(u8 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_00126400();
    extern void func_001843A0();
    extern void func_003A1280();
    u32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (*(s32 *)(p + 0x1C4) != *(s32 *)(q + 8)) {
            func_00126400();
            func_001843A0(p);
        }
    }
    v = p[0x15B];
    if (v != 0) {
        p[0x1B5] = (s8)v + 0x3B;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->t7c[p[2]]++;
        p[0x15B] = 0;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33C] = 5;
        t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x1C) = 0x32;
        p[0x209] = 2;
        *(u32 *)(p + 0x5C) = 0xBF555555;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(q + 8) + 0x34);
        func_003A1280(p, 0);
        func_003A1280(p, 1);
    }
}

extern u8 D_004BFDD4[4];
extern u8 D_004BFDD8[4];
extern u8 D_004BFDDC[4];

void func_002090C0(u8 *p)
{
    extern void func_001E3710();
    extern void func_001E3210();
    extern void func_001757E0();
    u32 v;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 9;
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = D_004BFDD4;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xA;
        func_001E3210(p, 0x1E);
        *(u8 **)(p + 0x408) = D_004BFDD8;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x22] = 0;
        *(u8 **)(p + 0x408) = D_004BFDDC;
        p[0x1BB] = 1;
        if ((*(u16 *)(p + 0x20E) & 0x800) != 0) {
            p[0x22] = 1;
            p[0x168] = 3;
            p[0x1B5] = 0x12;
            v = p[0x1B5];
            p[0x1B5] = v;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->t7c[p[2]]++;
            func_001757E0(p, 0xA, p[0x168]);
            return;
        }
        p[0x168] = 2;
        p[0x1B5] = 0xB;
        func_001E3210(p, 0x1E);
        break;
    default:
        break;
    }
    v = p[0x1B5];
    p[0x1B5] = v;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t7c[p[2]]++;
    func_001757E0(p, 0xA, p[0x168]);
}

extern s16 D_00475B60[];

void func_00373E90(u8 *p)
{
    extern s32 func_00174470();
    extern s32 func_00185980();
    extern void func_00374150();
    extern void func_00175700();
    extern void func_001E7F60();
    f32 one;
    if (func_00174470(p) == 0) {
        p[4] = 2;
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (*(u8 *)(*(u8 **)(p + 0x1C4) + 3) != 0) {
            p[0x1B2] = 0;
            p[0x1B5] = 0x3F;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->t7c[p[2]]++;
            return;
        }
        if (func_00185980(p) != 0) {
            func_00374150(p);
            return;
        }
    }
    one = 1.0f;
    *(f32 *)(p + 0x50) += 0.02199999988079071f;
    *(f32 *)(p + 0x54) += 0.02199999988079071f;
    if (!(*(f32 *)(p + 0x50) < one)) {
        *(f32 *)(p + 0x50) = one;
    }
    if (!(*(f32 *)(p + 0x54) < 1.0f)) {
        *(f32 *)(p + 0x54) = 1.0f;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    func_001E7F60(p);
}
