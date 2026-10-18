typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { s16 a, b, c; } T6;
extern T6 D_0044B470[];

void func_001A8B70(u8 *p, u8 *q) {
    extern void func_00175670();
    T6 *t = &D_0044B470[p[0x20]];
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.666666626930237f * (f32)t->a;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 1.666666626930237f * (f32)t->a;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.142857074737549f * (f32)t->b;
    if (*(s8 *)(q + 0x150) != 0 && q[0x1E4] == 0x15 && q[0xFD + 0x100] == 0) {
        func_00175670();
        return;
    }
    {
        u32 u = p[4];
        p[4] = u + 1;
    }
    p[0x13C] = 0;
}
