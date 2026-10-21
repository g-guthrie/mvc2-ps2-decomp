typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad0[4]; u8 f4; u8 pad1[0x78 - 5]; } X_l;
typedef struct { u8 pad[0xD8]; u8 *f; } Y_l;
extern u8 *D_006337A0[];
extern s16 D_00633720[][8];

void func_0041D270(s32 a)
{
    extern s32 func_0041CEB0(u8);
    extern int func_0041CCA0(s16, s16 *, s16 *);
    s16 idx = a;
    u8 *s0;
    u8 **s1;
    s16 x, y;
    f32 one;
    if (idx < 0 || idx >= 0x38) return;
    s1 = &D_006337A0[idx];
    s0 = *s1;
    s0[4] = 0;
    func_0041CCA0(func_0041CEB0((u8)a), &x, &y);
    if ((D_00633720[x][y] & 0xFFC0) == 0) {
        *(f32 *)(s0 + 0x80) = 0.800000011920929f;
        *(f32 *)(s0 + 0x7C) = 0.800000011920929f;
        *(f32 *)(s0 + 0x78) = 0.800000011920929f;
    } else {
        *(f32 *)(s0 + 0x80) = 0.4000000059604645f;
        *(f32 *)(s0 + 0x7C) = 0.4000000059604645f;
        *(f32 *)(s0 + 0x78) = 0.4000000059604645f;
    }
    one = 1.0f;
    *(f32 *)(s0 + 0x3C) = -12.880000114440918f;
    *(f32 *)(s0 + 0x54) = one;
    *(f32 *)(s0 + 0x50) = one;
    s0 = *(u8 **)(*s1 + 0xD8);
    if (s0 != 0) {
        *(f32 *)(s0 + 0x3C) = -12.859999656677246f;
        *(f32 *)(s0 + 0x54) = one;
        *(f32 *)(s0 + 0x50) = one;
    }
}
