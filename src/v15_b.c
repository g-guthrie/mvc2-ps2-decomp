typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u16 D_004F4484;
extern u16 D_004F4498;
extern u32 D_004636B0[];

typedef float f32;
extern f32 D_004CD178[];
extern f32 D_004CD17C[];
extern s8 D_004F7FC8[];
extern u8 D_00457CA0[];

typedef struct { u8 pad0[2]; u8 b2; u8 pad1[0x1E6 - 3]; u8 b1e6; u8 pad2[0x35E - 0x1E7]; u16 m; } P89;
typedef struct { u8 pad[8]; u16 f; } Q89;

s32 func_002952A0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_00457CA0, p + 0x398) == 0) return 0;
    if (p[0x210] == 0) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    func_0018A990(p, p + 0x398);
    p[0x1FD] = 4;
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}

void func_00257220(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    extern void func_002575B0();
    extern void func_00257CC0();
    switch (p[0x1FC]) {
    case 3: func_00257CC0(p); break;
    case 4: func_00257CC0(p); break;
    case 2: func_002575B0(p); break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}

typedef struct { f32 x, y, z; } V3_15;
extern u8 D_0045BA30[];

s32 func_002F22D0(u8 *p) {
    extern s32 func_00189310();
    extern void func_00186A60();
    if (func_00189310(p, D_0045BA30, p + 0x3A0) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    if (p[0x20D] == 2) p[0x1FD] = 3;
    else p[0x1FD] = 2;
    p[0x1B7] = 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern u16 D_004D18DC;
extern u8 D_004D18DB;

extern u8 D_004F20B0[];
extern u8 D_004F2668[];
extern u8 D_004F20B5[];
extern u8 D_004F20B6[];
extern u8 D_004F20B7[];
extern u8 D_004F266D[];
extern u8 D_004F266E[];
extern u8 D_004F266F[];
extern u8 *D_004C2840;
typedef struct { u8 p0[3]; u8 f3; u8 pad[0x88-4]; s8 f88; s8 f89; u8 pad2[0x91-0x8A]; u8 f91; u8 f92; } G32;
extern s32 D_004C2928;

extern s8 D_004D1960[];
extern u8 D_004D1970[];
