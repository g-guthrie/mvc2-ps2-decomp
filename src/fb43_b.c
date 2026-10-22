typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_00450EE0[];

typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 b7;
    u8 pad8[0x14];
    s16 h1c;
    s16 h1e;
    u8 pad20[0x14];
    f32 f34;
    f32 f38;
    u8 pad3c[0x24];
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6c;
} Q43;

void func_0021AB20(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001830D0(u8 *, u32 *, s32);
    u8 *q;
    s32 m;
    p[0x40C] = 2;
    p[0x33C] = 5;
    q = p;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    *(f32 *)(q + 0x34) += *(f32 *)(q + 0x5C);
    *(f32 *)(q + 0x5C) += *(f32 *)(q + 0x68);
    *(f32 *)(q + 0x38) += *(f32 *)(q + 0x60);
    *(f32 *)(q + 0x60) += *(f32 *)(q + 0x6C);
    func_00175700(q);
    m = (s8)q[0x151];
    if (m & 2) {
        s32 *t;
        u32 b = q[6];
        q[6] = b + 1;
        q[7] = 0;
        *(s8 *)(q + 0x151) ^= 2;
        *(s16 *)(q + 0x1C) = 8;
        *(s16 *)(q + 0x1E) = 0;
        t = D_00450EE0;
        if (q[0x20D] == 2) t += 2;
        *(f32 *)(q + 0x5C) = 1.6666666f * (f32)t[0] / 65536.0f;
        *(f32 *)(q + 0x60) = 2.142857074737549f * (f32)t[1] / 65536.0f;
        if (q[0x1E6] != 0) {
            *(f32 *)(q + 0x5C) = -*(f32 *)(q + 0x5C);
        }
        q[0x20D] = 2;
    } else if (m & 1) {
        u32 v[4];
        q[0x404] = 0;
        q[0x405] = 0;
        *(s8 *)(q + 0x151) ^= 1;
        if (q[0x20D] == 2) {
            v[0] = 0xC1D55555;
            v[1] = 0x432B6DB6;
        } else {
            v[0] = 0xC2F00000;
            v[1] = 0x42DEDB6D;
        }
        func_001830D0(q, v, 1);
    }
}
