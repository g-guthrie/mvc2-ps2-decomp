typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[2];
    u8 b4;
    u8 pad5[0x34 - 5];
    f32 f34;
    f32 f38;
    f32 f3c;
    u8 pad40[0x140 - 0x40];
    s16 h140;
    u8 pad142[0x159 - 0x142];
    u8 b159;
} Q;
typedef struct {
    u8 pad0[0x18];
    Q *q;
    u8 pad1c[0x34 - 0x1C];
    f32 f34;
    f32 f38;
    f32 f3c;
    u8 pad40[0x50 - 0x40];
    f32 f50;
    u8 pad54[4];
    f32 f58;
    u8 pad5c[0x74 - 0x5C];
    f32 f74;
    f32 f78;
    f32 f7c;
    f32 f80;
    u8 pad84[0x13C - 0x84];
    u8 b13c;
} A;
extern s16 *D_00461D10[];
extern f32 *D_00461AE0[];
void func_0015E6C0(A *a) {
    extern void func_003DAA40();
    Q *q = a->q;
    f32 c, e, h, o, r;
    if (q->b4 >= 2) {
        a->b13c = 0;
        func_003DAA40(a);
        return;
    }
    if (q->b0 == 0 || q->b159 == 0xFF) {
        a->b13c = 0;
        return;
    }
    a->b13c = 1;
    c = 1.6666666f;
    r = (f32)D_00461D10[q->b1][q->b159 & 0x1F];
    e = c * r;
    if (q->h140 != 0) e = -e;
    a->f34 = q->f34 + e;
    o = 1.0f;
    a->f38 = o + q->f3c;
    a->f3c = 0;
    {
        f32 *t = D_00461AE0[q->b1];
        t += (q->b159 >> 4) & 0xE;
        h = 1.2f;
        a->f50 = h * t[0];
        a->f58 = h * t[1];
    }
    *(u32 *)&a->f74 = 0x3F000000;
    *(u32 *)&a->f78 = 0x3F000000;
    *(u32 *)&a->f7c = 0x3F000000;
    *(u32 *)&a->f80 = 0x3F000000;
}
