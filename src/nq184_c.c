typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B4c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G4c;
typedef struct { f32 a, b; } P4c;
extern G4c *D_004C2794;
extern void (*jtbl_00464150[])(u8 *, u8 *, u8 *);
extern f32 D_004B8530[];
extern f32 D_004B8534[];
extern P4c D_004B8510[];
extern P4c D_004B8514[];
extern u16 D_004B8540[];

void func_0037A880(u8 *p) {
    jtbl_00464150[p[4]](p, *(u8 **)(p + 0x18), p + 0x88);
}

void residual_0037A8B0(u8 *o, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    f32 f;
    o[4] = 1;
    *(B4c *)(o + 0xEC) = *(B4c *)(q + 0xEC);
    o[0x13C] = 1;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    o[0x13C] = 1;
    o[0x24] = 7;
    *(s32 *)(o + 0x5C) = 0;
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    o[0x1B5] = 0x31;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    *(u16 *)(o + 0x1C0) |= 0x200;
    *(V3 *)(o + 0x34) = *(V3 *)(q + 0x34);
    f = D_004B8530[o[0x20]];
    if (*(s16 *)(o + 0x140) == 0) f = -f;
    *(f32 *)(o + 0x34) += f;
    *(f32 *)(o + 0x38) += D_004B8534[o[0x20]];
    f = D_004B8510[o[0x20] + q[0x1B7]].a;
    if (*(s16 *)(o + 0x140) == 0) f = -f;
    *(f32 *)(o + 0x5C) = f;
    *(f32 *)(o + 0x60) = D_004B8514[o[0x20] + q[0x1B7]].a;
    *(s32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x6C) = 0xBF800000;
    *(u16 *)(o + 0x1C) = D_004B8540[o[0x20] >> 1];
    func_001757E0(o, 0x17, 0xD);
    func_001E7F60(o);
}
