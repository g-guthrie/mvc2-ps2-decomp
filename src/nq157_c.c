typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3c;
typedef struct { s32 w[0x31]; } B157c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G157c;
extern G157c *D_004C2794;
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; u8 pad2[0x20]; f32 f5c; u32 f60; } F157c;

void residual_0039D400(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    u8 *q;
    F157c *sa;
    u8 *q2;

    sa = (F157c *)p;
    t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(*(u8 **)(p + 0x18) + 0x18);
    *(B157c *)(p + 0xEC) = *(B157c *)(q + 0xEC);
    p[0x13C] = 1;
    q2 = p + 2;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3c *)(p + 0x50) = *(V3c *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    sa->f38 += 102.85713958740234f;
    p[0x14F] = 0x20;
    p[0x14E] = 0x20;
    p[0x14D] = 0x20;
    p[0x14C] = 0x20;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (p[0x20] == 7) {
        sa->f60 = 0x424DB6DB;
        sa->f38 += 68.57142639160156f;
    }
    if (*(s16 *)(p + 0x140) != 0) {
        sa->f5c = 53.33333206176758f;
        sa->f34 += sa->f5c;
    } else {
        sa->f5c = -53.33333206176758f;
        sa->f34 += sa->f5c;
    }
    if (p[0x1B7] == 0) {
        p[0x1B5] = 0x30;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        { s32 x = *q2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    } else {
        p[0x1B5] = 0x32;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        { s32 x = *q2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    }
    func_001757E0(p, 0x14, 0);
}
