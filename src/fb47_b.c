typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y; } LIM3BA7C0;
extern LIM3BA7C0 D_00474A10[];

void func_003BA7C0(u8 *p)
{
    extern void func_003BD7B0(u8 *);
    extern void func_003BCF30(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_003BD050(u8 *);
    extern void func_003BD480(u8 *);
    extern s32 func_003BD1D0(u8 *);
    extern s32 func_00175700(u8 *);
    extern s32 func_003BCEB0(u8 *, u8 *);
    extern void func_003BD4A0(u8 *);
    u8 *o;
    u8 *t;
    u8 *q;
    f32 d, c, a, dy;
    u32 n;
    o = *(u8 **)(p + 0x18);
    t = *(u8 **)(p + 0xD0);
    q = o + 0x2B8;
    func_003BD7B0(p);
    n = p[6];
    if (n == 0) {
        p[6] = n + 1;
        d = *(f32 *)(p + 0x34) - *(f32 *)(t + 0x34);
        c = -26.666666f;
        if (d > 0.0f)
            c = -c;
        d += c;
        a = d;
        if (d < 0.0f)
            a = -d;
        if (a > D_00474A10[t[1]].x)
            a = D_00474A10[t[1]].x;
        if (d < 0.0f)
            a = -a;
        *(f32 *)(p + 0x5C) = a;
        dy = *(f32 *)(p + 0x38) - *(f32 *)(t + 0x38) - D_00474A10[t[1]].y;
        if (dy < 0.0f)
            *(f32 *)(p + 0x60) = D_00474A10[t[1]].y;
        else
            *(f32 *)(p + 0x60) = dy;
        func_003BCF30(p);
        func_001757E0(p, 0x19, 1);
        return;
    }
    if (q[3] == 0 || o[0x425] != 0) {
        func_003BD4A0(p);
    } else if (func_003BD050(p) != 0) {
        func_003BD480(p);
    } else if (func_003BD1D0(p) != 0) {
        func_003BD480(p);
    } else {
        func_003BCF30(p);
        if ((s8)func_00175700(p) < 0) {
            if (func_003BCEB0(p, t) == 0)
                func_003BD4A0(p);
        }
    }
}
