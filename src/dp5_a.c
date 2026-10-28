/* nearmiss: ./try.sh "-O3 -Op -fp off -sdatathreshold 0" (3.0 same); 3 words differ: constant 1 held in $a1 where retail uses $a2 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { f32 a; f32 b; } HK3C_E8;
extern HK3C_E8 D_00459EC0[];
extern HK3C_E8 D_00459EC4[];
extern f32 D_004F1F4C[];

void func_001E3210(u8 *a0, s32 a1);
void func_001757E0(u8 *a0, s32 a1, s32 a2);

void func_002C8510(u8 *a0, s32 a1) {
    u8 *s0;
    s16 v;
    f32 g;

    *(s8 *)(a0 + 0x13C) = 0;
    a0[0x209] = 1;
    v = *(s16 *)(a0 + 0x1C) - 1;
    *(s16 *)(a0 + 0x1C) = v;
    if (v >= 0) {
        return;
    }
    s0 = a0;
    {
        u32 t6 = s0[6];
        s0[6] = t6 + 1;
    }
    s0[0x13C] = 1;
    *(f32 *)(s0 + 0x34) = (f32)((double)D_004F1F4C[0] - 320.0 + (double)D_00459EC0[s0[7]].a);
    g = D_00459EC4[s0[7]].a;
    *(f32 *)(s0 + 0x38) = *(f32 *)(*(u8 **)(s0 + 0x220) + 0x38) + g;
    if (*(f32 *)(s0 + 0x38) > *(f32 *)(s0 + 0x430)) {
        s0[0x20D] = 2;
        s0[0x1E8] = 0;
        s0[0x1E9] = 0;
        s0[0x1EA] = 0x11;
        s0[0x1ED] = 0;
    } else {
        s0[0x20D] = 0;
    }
    func_001E3210(s0, 0x1C);
    {
        s16 t = (s0[7] & 1) ? 0 : 1;
        *(s16 *)(s0 + 0x140) = t;
        s0[0x1E6] = t;
    }
    func_001757E0(s0, 0x15, 6);
}
