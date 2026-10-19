/* ./try.sh src/grok_bg_0031EEB0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 D_004C1768[];
extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_0031EEB0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        p[0x206] = 3;
        *(s16 *)(p + 0x1C) = 4;
        *(f32 *)(p + 0x5C) = (1.6666666269302368f * (f32)D_004C1768[20 + p[0x1B7]]) / 65536.0f;
        if (p[0x1E6])
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_001757E0(p, 21, 39);
    }
}
