typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004C2A80;
extern f32 D_004C2A84;
extern f32 D_004C2A90;
extern f32 D_004C2A94;
extern f32 D_0061BDE0[];
extern f32 D_0061BDF4[];
extern void func_003DE3A0(f32 *a, u8 *b);

void func_003DD440(u8 *p) {
    f32 a, b;
    func_003DE3A0(D_0061BDE0, p);
    a = D_004C2A80 / (0.5f * D_004C2A90);
    b = D_004C2A84 / (0.5f * D_004C2A94);
    D_0061BDE0[0] = (2.0f * D_0061BDE0[0]) / b;
    D_0061BDF4[0] = (2.0f * D_0061BDF4[0]) / a;
    D_0061BDE0[0] /= 1.333333015f;
}
