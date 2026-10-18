typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

void func_0017C7F0(u8 *p) {
    extern void func_00175700();
    extern void func_0017C790();
    extern s32 func_001864a0();
    extern s32 func_00174240();
    extern void func_00180E20();
    extern void func_00132730();
    if (p[7] == 0) {
        p[7] = p[7] + 1;
        func_0017C790(p);
        return;
    }
    func_00175700(p);
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (func_001864a0(p)) func_0017C790(p);
    if (func_00174240(p) == 0) {
        p[0] = 0;
        p[0x13C] = 0;
        func_00180E20(p);
        func_00132730(p);
    }
}

void func_0023B4C0(u8 *p) {
    extern s8 func_00175700();
    extern void func_00183D90();
    extern void func_001863F0();
    extern void func_001843A0();
    if (p[0x213] == 3) func_00183D90();
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        unsigned int offset;
        p[0x151] = 0;
        p[0x1B5] = 0x1C;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
}

void func_003B6110(u8 *p) {
    extern void func_003B6630();
    extern s8 func_00175700();
    extern void func_001E7F60();
    u8 *q = p + 0x88;
    if (*(s8 *)(p + 0x1B2) != 0) {
        p[4] = 2;
        p[5] = 0;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        p[4] = 2;
        p[5] = 0;
    }
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (func_00175700(p) < 0) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            s8 t;
            u32 u;
            func_003B6630(p);
            *(s16 *)(p + 0x1C) = 1;
            t = *(s8 *)(q + 0x22) - 1;
            *(s8 *)(q + 0x22) = t;
            if (t == 0) {
                u = p[4];
                p[4] = u + 1;
                p[5] = 0;
                func_001757E0(p, 0x15, 0x19);
            }
        }
    }
    func_001E7F60(p);
}

extern u8 D_004C0AFC[4];
extern u8 D_004C0B00[4];
extern u8 D_004C0B04[4];

void func_0029BDA0(u8 *p) {
    extern void func_001CB610();
    extern void func_0038F440();
    extern void func_001E3710(u8 *, u8);
    extern void func_001757E0(u8 *, s32, u8);
    u16 s0;
    u16 s1;
    s0 = p[0x1FC];
    s1 = s0 + 3;
    switch (s0) {
    case 0:
        *(u8 **)(p + 0x408) = D_004C0AFC;
        p[0x1BB] = 0;
        break;
    case 1:
        *(u8 **)(p + 0x408) = D_004C0B00;
        p[0x1BB] = 1;
        break;
    case 2:
        *(u8 **)(p + 0x408) = D_004C0B04;
        p[0x1BB] = 2;
        if ((*(u16 *)(p + 0x20E) & 0x800) != 0) {
            p[6] = 1;
            s0 = 6;
            s1 = 0x13;
            func_001CB610(p, 0x16);
        } else {
            func_0038F440(p, 0);
        }
        break;
    }
    func_001E3710(p, p[0x1FC] + 0x14);
    p[0x1B5] = s1;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    {
        unsigned int offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
    func_001757E0(p, 8, s0);
}

extern u32 D_004C2078[2];

void func_002AFE40(u8 *p) {
    extern void func_00175700();
    extern void func_00185490();
    extern void func_00183d50();
    u32 *a, *b, *c, *d;
    u32 t;
    d = (u32 *)(p + 0x6C);
    c = (u32 *)(p + 0x68);
    b = (u32 *)(p + 0x60);
    a = (u32 *)(p + 0x5C);
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    func_00175700();
    t = p[0x15B];
    if (t != 0) {
        p[0x1B5] = t;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        {
            unsigned int offset = p[2] * 2;
            offset += (unsigned int)D_004C2794;
            ++*(s16 *)(offset + 0x7C);
        }
        p[0x15B] = 0;
    }
    if (*(float *)(p + 0x38) < *(float *)(p + 0x430)) {
        u32 u = p[6];
        p[6] = u + 1;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        *(float *)(p + 0x38) = *(float *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0xE));
        func_00185490(p);
        func_00183d50(p);
    }
}
