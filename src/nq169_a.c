/* MWCC 3.0: ./try30.sh src/nq169_a.c "-O3 -Op -sdatathreshold 8" */
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
extern G3c *D_004C2794;
extern s16 D_00472F00[];

#define PAR q

void residual_003A7F30(u8 *o, u8 *a) {
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003A8150(u8 *, u8 *);
    u32 t;
    u32 z;
    u8 *q;
    u8 *p2;
    t = o[4];
    q = *(u8 **)(o + 0x14);
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(PAR + 0xEC);
    o[0x13C] = 1;
    o[2] = PAR[2];
    o[1] = PAR[1];
    *(f32 *)(o + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(PAR + 0x54);
    o[0x1B7] = PAR[0x1B7];
    o[0x1B8] = PAR[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(PAR + 0x24);
    o[0x13C] = 1;
    *(s8 *)(o + 0x31) = -2;
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    p2 = o + 2;
    if (o[0x21] == 0) {
        o[0x1B5] = 0x42;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    } else {
        o[0x1B5] = 0x43;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    }
    o[0x14F] = 0x1A;
    o[0x14E] = 0x1A;
    *(f32 *)(o + 0x34) = *(f32 *)(PAR + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(PAR + 0x3C);
    *(f32 *)(o + 0x38) += 2.142857074737549f * (f32)D_00472F00[(s16)(func_00174170() & 0xF)];
    *(u32 *)(o + 0x5C) = 0xC1BAAAAA;
    *(u32 *)(o + 0x68) = 0xBE555555;
    if (*(s16 *)(o + 0x140) != 0) {
        N *sa = (N *)o;
        sa->f5c = -sa->f5c;
        sa->f68 = -sa->f68;
    }
    func_001757E0(o, 0x17, 0x29);
    func_003A8150(o, a);
}
