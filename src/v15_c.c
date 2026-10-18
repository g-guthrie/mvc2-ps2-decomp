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

typedef struct { f32 x, y, z; } V3_15;
extern u8 D_0045BA30[];

extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_001FE3B0(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[6]; p[6] = t + 1;
            *(f32 *)(p + 0x68) = (p[0x1E6] != 0) ? 0.833333313f : -0.833333313f;
            func_001757E0(p, 2, 3);
        }
    }
}

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

void func_002F8520(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            f32 w;
            u32 t = p[6]; p[6] = t + 1;
            *(s16 *)(p + 0x1C) = 0x10;
            if (p[0x1E6] != 0) w = -0.833333313f;
            else w = 0.833333313f;
            *(f32 *)(p + 0x68) = w;
            func_001757E0(p, 2, 2);
        }
    }
}

extern s8 D_004D1960[];
extern u8 D_004D1970[];
