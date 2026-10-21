typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_0045B730[];
extern u8 D_004C1210[8];
s32 func_002EDBF0(u8 *o) {
    s32 func_00189310(); void func_0018A990(); void func_00186A60();
    if (func_00189310(o, D_0045B730, o + 0x380) == 0) return 0;
    if (**(s8**)(o + 0x420) == 0) return 0;
    func_0018A990(o, o + 0x380);
    o[0x1FD] = D_004C1210[*(s32*)(o + 0x2D4)];
    o[5] = 0; o[7] = 0; o[6] = 0;
    func_00186A60(o, 0x1D);
    return 1;
}

extern u8 D_0045B0B8[];
s32 func_002E4020(u8 *o) {
    s32 func_00189660(); void func_0018A990(); void func_00186A60();
    u8 *q = o + 0x2B8;
    if (func_00189660(o, D_0045B0B8, o + 0x388) == 0) return 0;
    if (*(s8*)(o + 0x1E8) != 0 || *(s8*)(q + 9) != 0) return 0;
    func_0018A990(o, o + 0x388);
    o[5] = 0; o[6] = 0; o[7] = 0;
    o[0x1FD] = 1;
    func_00186A60(o, 0x15);
    return 1;
}

extern u8 D_004F1F45[];
extern u8 D_004F1F46[];
typedef struct { u8 pad[0x7C]; s16 f7C[1]; } G6;
extern G6 *D_004C2794;
void func_002698B0(u8 *o, void *context) {
    s32 func_00175700(); void func_001757E0(); void func_00374E50();
    s8 r = func_00175700();
    if (r < 0) {
        u32 t = o[7]; o[7] = t + 1;
        D_004F1F45[0] = 2;
        D_004F1F46[0] = 1;
        o[0x1B5] = 0x45;
        o[0x1B2] = *(u16*)(o + 0x1C0) = 0;
        *(s32*)(o + 0x1D8) = 0;
        {
            D_004C2794->f7C[o[2]] = D_004C2794->f7C[o[2]] + 1;
        }
        func_001757E0(o, 0x16, 0x29, 1);
        func_00374E50(o, 0);
    }
}

extern s8 D_00583BC7[];
extern u16 D_004C291C[2];
extern u8 *D_004C2840;
s32 func_0032C180(s32 a) {
    void func_003298B0(); void func_0012E780();
    if ((D_004C291C[D_00583BC7[0] ^ 1] & 0x3FC) != 0) {
        func_003298B0(-1, 0x14, 1);
        *(s16*)(D_004C2840 + 8) = 0x14;
        D_004C2840[0x19] = 1;
        if (a != 0) D_004C2840[4] = 7;
        else D_004C2840[4] = 9;
        func_0012E780(D_00583BC7[0] + 0xD);
        func_0012E780(2);
        return 1;
    }
    return 0;
}

extern u8 D_004C0C98[8];
void func_002AF810(u8 *o) {
    void func_00175700(); void func_003958B0(); void func_001E3210(); void func_001757E0();
    s16 t;
    func_00175700(o);
    if (*(s8*)(o + 0x151) != 0) {
        o[0x151] = 0;
        if (*(s32*)(o + 0xD0) == 0) {
            func_003958B0(o, 0);
        } else {
            func_003958B0(o, 6);
        }
        func_001E3210(o, 0x1E);
        o[0x28F] = 0;
        o[0x28E] = 0x10;
    }
    t = *(s16*)(o + 0x1C) - 1;
    *(s16*)(o + 0x1C) = t;
    if (t <= 0) {
        u32 u = o[6]; o[6] = u + 1;
        func_001757E0(o, 0x15, (D_004C0C98 + *(s32*)(o + 0xD0) * 2)[o[0x1B7]]);
    }
}

extern u8 D_004505C0[];
s32 func_002089C0(u8 *o) {
    s32 func_00189660(); void func_0018A990(); void func_00186A60();
    u8 *q = o + 0x2B8;
    if (func_00189660(o, D_004505C0, o + 0x378) == 0) return 0;
    if (o[0x20D] == 2 && *(s8*)(q + 1) == 0) return 0;
    if (*(s8*)(q + 1) == 0) {
        o[0x1FD] = 0xF;
    } else {
        if (q[2] != 0) return 0;
        o[0x1FD] = 0x10;
    }
    func_0018A990(o, o + 0x378);
    o[5] = 0; o[7] = 0; o[6] = 0;
    func_00186A60(o, 0x15);
    return 1;
}

extern u8 D_004B7134[];
extern f32 D_004B7160[], D_004B7164[], D_004B7168[], D_004B716C[];
void func_0021F810(u8 *o) {
    void func_0018C4B0(); void func_001757E0();
    o[0x1B5] = D_004B7134[0];
    o[0x1B2] = *(u16*)(o + 0x1C0) = 0;
    *(s32*)(o + 0x1D8) = 0;
    D_004C2794->f7C[o[2]] = D_004C2794->f7C[o[2]] + 1;
    func_0018C4B0(o, 5);
    func_001757E0(o, 0x15, 0xC);
    if (o[0x1E6] != 0) {
        *(f32*)(o + 0x5C) = D_004B7160[0];
        *(f32*)(o + 0x68) = D_004B7164[0];
    } else {
        *(f32*)(o + 0x5C) = -D_004B7160[0];
        *(f32*)(o + 0x68) = -D_004B7164[0];
    }
    *(f32*)(o + 0x60) = D_004B7168[0];
    *(f32*)(o + 0x6C) = D_004B716C[0];
}
