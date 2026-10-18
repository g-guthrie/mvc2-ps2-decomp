typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern s32 D_004C2838;
extern signed char data_s8_004C1514[12] __attribute__((section(".sdata")));
extern u8 *D_004C2840;
extern f32 D_00445380[];

void func_003147B0(u8 *p, s32 b) {
    extern void func_00185490();
    extern void func_00175C00();
    extern void func_00183D10();
    extern void func_0018C4B0();
    extern void func_001757E0();
    extern void func_003148B0();
    u32 t;
    u32 offset;
    t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_0018C4B0(p, 5);
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(u32 *)(p + 0x5C) = 0xC1555555;
    *(u32 *)(p + 0x68) = 0x3F200000;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    p[0x1B5] = 0x4D;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (u32)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_001757E0(p, 0xF, 0x11);
    func_003148B0(p, b);
}

void func_00250390(u8 *p) {
    extern void func_00175C00();
    extern void func_00175700();
    extern void func_001757E0();
    u32 t;
    u32 offset;
    if (*(u32 *)(D_004C2840 + 0x1C) & 2) {
        func_00175C00(p, 8);
    } else {
        func_00175C00(p, 0);
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0 && (*(u16 *)(p + 0x1C2) & 0x80) != 0) {
        t = p[6];
        p[6] = t + 1;
        *(u16 *)(p + 0x1C2) = 0;
        *(s16 *)(p + 0x1C) = 1;
        func_00175C00(p, 0);
        return;
    }
    if ((*(u16 *)(p + 0x1C2) & 0x80) == 0) {
        t = p[6];
        p[6] = t + 1;
        func_00175C00(p, 0);
        p[0x1B5] = 0x48;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        *(s16 *)(p + 0x1C) = 0;
        func_001757E0(p, 0x15, 6);
    }
}

void func_00305780(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    u8 *q = p + 0x2B8;
    u8 command;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(signed char **)(p + 0x408) = (signed char *)&data_s8_004C1514[0];
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        *(signed char **)(p + 0x408) = (signed char *)&data_s8_004C1514[4];
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 5;
        *(signed char **)(p + 0x408) = (signed char *)&data_s8_004C1514[8];
        func_001E3710(p, 0x16);
        p[0x1BB] = 2;
        q[0x13] = 8;
        q[0x12] = p[0x168];
        break;
    }
    command = p[0x1B5];
    *(volatile u8 *)(p + 0x1B5) = command;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    {
        u32 offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
    func_001757E0(p, 8, p[0x168]);
}

void func_0031C6B0(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    extern s32 func_001853E0();
    extern void func_001855D0();
    extern void func_001E3710();
    extern void func_001757E0();
    u32 offset;
    switch (p[0x1FC]) {
    case 0:
    case 2:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            if (func_001853E0(p) == 0) {
                if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x40) != 0) {
                    *(u16 *)(p + 0x366) = 0;
                    p[0x1B5] = 0x1B;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(s32 *)(p + 0x1D8) = 0;
                    offset = p[2] * 2;
                    offset += (u32)D_004C2794;
                    ++*(s16 *)(offset + 0x7C);
                    func_001855D0(p);
                    func_001E3710(p, 0x15);
                    func_001757E0(p, 8, 4);
                }
            }
        }
        break;
    }
}

void func_00263DB0(u8 *p) {
    extern void func_001861B0();
    extern void func_001757E0();
    extern void func_001E3710();
    extern void func_0018C4B0();
    extern void func_001B53E0();
    extern void func_00183D90();
    extern void func_001863F0();
    extern s32 func_00175700();
    extern void func_001843A0();
    u32 t;
    u32 offset;
    u8 command;
    if (p[6] == 0) {
        func_001861B0();
        t = p[6];
        p[6] = t + 1;
        p[0x1B5] = 0x1D;
        command = p[0x1B5];
        *(volatile u8 *)(p + 0x1B5) = command;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        p[0x20D] = 0;
        func_001757E0(p, 0x14, 3);
        func_001E3710(p, 0x16);
        func_0018C4B0(p, 5);
        func_001B53E0(p, 0, 2);
    }
    if (p[0x213] == 3) func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}
