typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 w[0x31]; } W31;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } PS;
extern u8 *D_004BF5E8[2];

void residual_0019FD00(u8 *p) {
    extern void func_001757E0(u8 *, s32, u8);
    u8 *q;
    u8 *e;
    s32 n;
    u32 t;
    u8 f;
    q = *(u8 **)(p + 0x14);
    *(W31 *)(p + 0xEC) = *(W31 *)(q + 0xEC);
    n = 8;
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
    t = p[4]; p[4] = t + 1;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = *(s8 *)(q + 0x31) - 4;
    e = D_004BF5E8[p[0x20]];
    f = p[0x21];
    if (f & 0x80) {
        p[0x21] = f & 0x7F;
        n = 0xC;
        e += 4;
    }
    e += p[0x21] * 8;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    ((PS *)p)->f34 += 1.6666666269302368f * (f32)((s16 *)e)[0];
    ((PS *)p)->f38 += 2.142857074737549f * (f32)((s16 *)e)[1];
    func_001757E0(p, 0x17, n + p[0x20] * 2);
}
