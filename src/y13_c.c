typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C29D4;

typedef struct { u8 p0[3]; u8 f3, f4, f5, f6, f7; u8 p1[0x10]; u8 f18; u8 p2[0x15]; u8 f2e; u8 p3[0x1D]; u8 f4c; u8 p4[0x3B]; u8 f88; } G28;
extern G28 *D_004C2840;
extern u8 D_004F4384[];
extern u8 D_004D18FA[];
extern u8 D_004D18FB[];

void func_00172450(void) {
    extern void func_0011D8F8();
    extern void func_003D7DF0();
    extern void func_00170F60();
    extern void func_00180490();
    extern void func_001712F0();
    extern void func_00172520();
    extern void func_00171700();
    extern void func_001E2130();
    extern void func_00170160();
    func_0011D8F8(D_004F4384, 0, 0x80);
    D_004C2840->f18 = 3;
    D_004C2840->f88 = 0;
    D_004C2840->f2e = 1;
    D_004C2840->f4c = 0;
    func_003D7DF0();
    func_00170F60();
    func_00180490();
    func_001712F0();
    func_00172520();
    D_004C2840->f88 = 3;
    func_00171700();
    func_001E2130();
    func_00170160(0xE);
    D_004D18FA[0] = 5;
    D_004D18FB[0] = 5;
    D_004C2840->f3 = 0;
    D_004C2840->f4 = 0;
    D_004C2840->f5 = 0;
    D_004C2840->f6 = 0;
    D_004C2840->f7 = 0;
}

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G94;
extern G94 *D_004C2794;

void func_0022FED0(u8 *p) {
    extern void func_001861B0();
    extern void func_001757E0();
    extern void func_0019DE50();
    u32 t = p[7];
    p[7] = t + 1;
    func_001861B0(p);
    p[0x169] = 0x15;
    p[0x168] = *(s8 *)(p + 0x1B7) + 0xD;
    func_001757E0(p, p[0x169], p[0x168]);
    if (p[0x269] == 3) {
        p[0x1B5] = 0x41;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    } else {
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x40;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    func_0019DE50(p, 8, 0);
}

extern u32 D_004C2830;

void func_0013B3C0(u8 *p, s32 n) {
    extern u8 *func_003DA750();
    extern void func_0013B5F0();
    extern void func_0013B4A0();
    extern void func_00170DF0();
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
        *(u32 *)(o + 0xC8) = (u32)(p + 0x88);
        *(u32 *)(o + 0x14) = *(u32 *)(p + 0x14);
        o[0x20] = p[0x20];
        o[0x21] = p[0x21];
        *(s16 *)(o + 0xCC) = 0xAF;
        *(u32 *)(o + 0x84) = D_004C2830;
        if (n != 0) *(u32 *)(o + 0x10) = (u32)func_0013B5F0;
        else *(u32 *)(o + 0x10) = (u32)func_0013B4A0;
        *(u32 *)(o + 0xD0) = 0x810;
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        o[0x22] = 0;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        *(u32 *)(o + 0xD4) = 6;
        *(u32 *)(o + 0x5C) = 0x3C23D70A;
        func_00170DF0(*(u32 *)(o + 0x84));
    }
}

extern u32 D_004C1678, D_004C167C, D_004C1680;

void func_00310030(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        *(u32 *)(p + 0x408) = (u32)&D_004C1678;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        *(u32 *)(p + 0x408) = (u32)&D_004C167C;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u32 *)(p + 0x408) = (u32)&D_004C1680;
        p[0x1BB] = 2;
        func_001E3710(p, 0x16);
        break;
    }
    p[0x1B5] = (s8)p[0x1B5];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
