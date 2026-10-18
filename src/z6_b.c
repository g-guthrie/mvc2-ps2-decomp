typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern s32 D_004C13C4[2];
extern s32 D_004C13C8[2];
extern s32 D_004C13CC[2];

void func_002FCAA0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 offset;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        *(s32 **)(p + 0x408) = D_004C13C4;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(s32 **)(p + 0x408) = D_004C13C8;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(s32 **)(p + 0x408) = D_004C13CC;
        p[0x1BB] = 2;
        break;
    }
    *(volatile u8 *)(p + 0x1B5) = p[0x1B5];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (u32)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_001757E0(p, 9, p[0x168]);
}
extern u8 *D_004C2794;
extern s32 D_004C0CC0[2];
extern s32 D_004C0CC4[2];
extern s32 D_004C0CC8[2];

void func_002B31F0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 offset;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = D_004C0CC0;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        func_001E3710(p, 0x15);
        *(s32 **)(p + 0x408) = D_004C0CC4;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(s32 **)(p + 0x408) = D_004C0CC8;
        p[0x1BB] = 2;
        func_001E3710(p, 0x16);
        break;
    }
    *(volatile u8 *)(p + 0x1B5) = p[0x1B5];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (u32)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_001757E0(p, 7, p[0x168]);
}

extern u8 *D_004C2794;

void func_001F5B10(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001830D0(u8 *, u32 *, s32);
    u32 offset;
    u32 t;
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if ((s8)func_00175700(p) < 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6];
        p[6] = t + 1;
        p[0x1B5] = 0x28;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x15, 0xC);
        v[0] = 0xC2200000;
        v[1] = 0x431A4924;
        func_001830D0(p, v, 1);
    }
}

extern u8 *D_004C2840;
extern u8 D_004D18A6[];

void func_0016EA90(void) {
    extern void func_003DA6F0(s32);
    extern void func_003DA650(s32);
    extern void func_001E8A50();
    extern void func_001E8B10();
    s32 v = *(s16 *)(D_004C2840 + 0xE);
    if (v != 0) {
        if ((s16)v > 2) func_003DA6F0(0x12);
        *(s16 *)(D_004C2840 + 0xE) -= 1;
    } else {
        func_003DA6F0(0x12);
        *(s16 *)(D_004C2840 + 8) -= 1;
        if (*(s16 *)(D_004C2840 + 8) < 0xB5) {
            (*(s8 *)(D_004C2840 + 0x92))++;
            D_004D18A6[0] = 0;
            func_003DA650(6);
            func_003DA650(7);
            func_003DA650(0xC);
            func_003DA650(8);
            func_003DA650(9);
            func_003DA650(0xA);
            func_003DA650(0x5B);
            func_003DA650(0xB);
            func_003DA650(5);
            func_003DA650(0x11);
            func_001E8A50();
            func_001E8B10();
        }
    }
}
