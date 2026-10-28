/* MWCC 3.0: ./try30.sh src/nq204_c.c "-O3 -Op -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
typedef struct { u8 pad[0x5C]; f32 f5c; u8 p2[8]; f32 f68; } N;
typedef struct { u8 pad[0x34]; f32 f34; } M;
extern G3c *D_004C2794;
extern s16 D_00472E40[];
extern s16 D_00472E42[];

void residual_003A7700(u8 *o, u8 *q) {
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003A79B0(u8 *, u8 *);
    u32 t;
    u32 z;
    u8 *p2;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(q + 0xEC);
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
    o[0x31] = 1;
    o[0x14F] = 0x22;
    o[0x14E] = 0x22;
    ((M *)o)->f34 = *(f32 *)(q + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(q + 0x3C);
    p2 = o + 2;
    if (*(s16 *)(o + 0x140) == 0) {
        *(f32 *)(o + 0x34) -= 1.6666666269302368f * (f32)D_00472E40[o[0x21] * 2];
    } else {
        *(f32 *)(o + 0x34) += 1.6666666269302368f * (f32)D_00472E40[o[0x21] * 2];
    }
    *(f32 *)(o + 0x38) += 2.142857074737549f * (f32)D_00472E42[o[0x21] * 2];
    *(f32 *)(o + 0x38) += (f32)(0x10 - (s16)(func_00174170() & 0x1F));
    if (q[0x1B7] == 0) {
        *(u32 *)(o + 0x5C) = 0xC1BAAAAA;
        *(u32 *)(o + 0x68) = 0xBE555555;
    } else {
        *(u32 *)(o + 0x5C) = 0xC1D55555;
        *(u32 *)(o + 0x68) = 0xBE555555;
    }
    if (*(s16 *)(o + 0x140) != 0) {
        N *sa = (N *)o;
        sa->f5c = -sa->f5c;
        sa->f68 = -sa->f68;
    }
    o[0x1B5] = 0x44;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    func_001757E0(o, 0x17, 0x29);
    func_003A79B0(o, q);
}
