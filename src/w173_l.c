typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0045AA10[];
extern s16 D_0045AA12[];

void func_002DA3F0(u8 *p)
{
    extern int func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 i, a, b;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0, 0);
        return;
    }
    i = *(s8 *)(p + 0x151);
    a = D_0045AA10[i * 2] << 8;
    b = D_0045AA12[i * 2] << 8;
    if (*(s16 *)(p + 0x140) == 0) a = -a;
    *(f32 *)(p + 0x5C) = 1.66666662693f * (f32)a / 65536.0f;
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)b / 65536.0f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
}
