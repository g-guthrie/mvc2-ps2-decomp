typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 a; s32 b; } T19EF00;
extern T19EF00 D_0044AD10[];

void func_0019EF00(u8 *p, u16 *q)
{
    extern void func_00175700(u8 *);
    u8 *r;
    s32 t;
    s32 i;
    u32 u;
    f32 f;
    r = *(u8 **)(p + 0x18);
    p[0x13C] = 0;
    if (*(u16 *)(r + 0x168) != *q) {
        u = p[4];
        p[4] = u + 1;
    } else {
        t = (s8)(*(s8 *)(r + 0x151) & 0xF0);
        if (t != 0) {
            p[0x13C] = 1;
            i = (s8)((s8)t / 16 - 1);
            *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)D_0044AD10[i].a / 65536.0f;
            *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)D_0044AD10[i].b / 65536.0f;
            if (*(s16 *)(r + 0x140) == 0)
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x34) = *(f32 *)(r + 0x34) + *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38) + *(f32 *)(p + 0x60);
            *(s16 *)(p + 0x140) = *(s16 *)(r + 0x140);
            *(s8 *)(p + 0x31) = -2;
            func_00175700(p);
        }
    }
}
