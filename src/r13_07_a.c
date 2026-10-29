/* func_003A3970 (residual case body of dispatch head func_003A3940, live-in q=a1, r=a2). Metrowerks 3.0: ./try30.sh src/r13_07_a.c "-O3 -Op -sdatathreshold 8" */
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
extern G3c *D_004C2794;
typedef struct { s16 x, y; } SP2;
extern SP2 D_00472BC0[];
typedef struct { u8 pad[0x1C]; s16 h1c; s16 h1e; } H1C;


void func_003A3970(u8 *p, u8 *q, u8 *r)
{
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    SP2 *t;
    f32 off;
    u8 *pb;
    f32 m, a;
    *(B3c *)(p + 0xEC) = *(B3c *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[4]++;
    p[0x24] = 0;
    pb = p + 2;
    if (q[5] || q[0x1E4] != 0x15 || q[0x1FD] || *(s8 *)(q + 0x1B3))
        *(s8 *)(r + 3) = -1;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x30;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*pb]++;
    *(s16 *)(p + 0x1E) = p[0x20] * 2;
    t = &D_00472BC0[*(s16 *)(p + 0x1E)];
    off = -90.0f;
    *(s16 *)(p + 0x1C) = 1;
    if (*(s16 *)(p + 0x140)) {
        off = -off;
        ((H1C *)p)->h1c = -1;
    }
    a = 1.6666666269302368f * (f32)t->x;
    *(f32 *)(p + 0x34) = a + (*(f32 *)(q + 0x34) + off);
    m = 147.8571319580078f;
    *(f32 *)(p + 0x38) = 2.142857074737549f * (f32)t->y + (*(f32 *)(q + 0x38) + m);
    func_001E7F60(p);
    func_001757E0(p, 0x17, 3);
}
