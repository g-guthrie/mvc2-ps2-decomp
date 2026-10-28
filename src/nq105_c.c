typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } Bq;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gq;
extern Gq *D_004C2794;

void residual_003B34E0(u8 *o, u8 *a) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003B3650(u8 *, u8 *);
    u32 t;
    u32 z;
    u8 *q;
    u8 *r;
    q = *(u8 **)(o + 0x14);
    t = o[4];
    o[4] = t + 1;
    *(Bq *)(o + 0xEC) = *(Bq *)(q + 0xEC);
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
    *(s8 *)(o + 0x31) = -2;
    r = o + 2;
    if (*(s16 *)(o + 0x1E) == 0) {
        o[0x1B0] = 0x42;
        t = q[0x23];
        q[0x23] = t + 1;
        q[0x23] &= 3;
        o[0x1B5] = *(s8 *)(q + 0x23) + 0x37;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *r; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        o[0x1B1] = 0x42;
    }
    o[0x14F] = 0x1A;
    o[0x14E] = 0x1A;
    func_001757E0(o, 0x17, (u8)(o[0x21] + 0xF));
    func_003B3650(o, a);
}
