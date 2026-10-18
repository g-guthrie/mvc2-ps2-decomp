typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#define P(t,o) (*(t*)(p+(o)))
#define Q(t,o) (*(t*)(*(u8**)(p+0x18)+(o)))

extern f32 func_00117078(f32);
void func_00384410(u8 *p) {
    u8 *r;
    u8 *q = *(u8 **)(p + 0x18);
    r = *(u8 **)(q + 0x220);
    if (*(s16 *)(q + 0x1E) != 1) {
        f32 off;
        f32 d;
        if (q[0x1E6]) off = 106.6666641f;
        else off = -106.6666641f;
        d = func_00117078(*(f32 *)(r + 0x34) - (*(f32 *)(q + 0x34) + off));
        if (d > 80.0f) *(s16 *)(p + 0x1C0) = 0x10;
    }
}

extern s32 func_00175670();
extern void func_001E3210();
void func_001BB650(u8 *p, u8 *q) {
    f32 v = P(f32,0x118) - 0.009523808956f;
    P(f32,0x118) = v;
    if (v < 0.0f) P(f32,0x118) = 0.0f;
    *(s32 *)(q + 0x2D8) = 2;
    if ((s8)func_00175670(p) < 0) {
        P(u8,4) = 2;
        P(u8,0x13C) = 0;
        P(u32,0x118) = 0;
    } else if (P(s8,0x151) == 2) {
        P(s8,0x151) = 0;
        func_001E3210(p, 0x1F);
    }
}

extern f32 D_004B41F0[];
void func_00163120(u8 *p) {
    f32 *tp;
    u32 t;
    u32 i = P(u8,5);
    P(f32,0x50) -= 0.03846153989f;
    P(f32,0x54) -= 0.03846153989f;
    tp = D_004B41F0;
    tp += i;
    P(s32,0x48) += 0x348;
    P(f32,0x78) = *tp;
    P(f32,0x7C) = *tp;
    P(f32,0x80) = *tp;
    t = P(u8,5);
    P(u8,5) = t + 1;
    if ((u8)(t + 1) > 0xD) {
        u32 u = P(u8,4);
        P(u8,4) = u + 1;
    }
}
