typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f32 D_004B1900[3];
extern f32 D_004B190C[3];
extern f32 D_004B1920[3];
extern f32 D_004B192C[3];

void func_0013E0F0(u8 *p)
{
    f32 *b = (f32 *)&D_004B190C;
    f32 *c = (f32 *)&D_004B192C;
    f32 q0, a0;
    f32 q1, a1;
    f32 q2, a2;
    f32 q3, a3;
    f32 q4, a4;
    f32 q5, a5;
    q0 = (b[0] - D_004B1900[0]) / 60.0f;
    *(f32 *)(p + 0x34) = D_004B1900[0] + (f32)*(s16 *)(p + 0x1C) * q0;
    q1 = (b[1] - D_004B1900[1]) / 60.0f;
    *(f32 *)(p + 0x38) = D_004B1900[1] + (f32)*(s16 *)(p + 0x1C) * q1;
    q2 = (b[2] - D_004B1900[2]) / 60.0f;
    *(f32 *)(p + 0x3C) = D_004B1900[2] + (f32)*(s16 *)(p + 0x1C) * q2;
    q3 = (c[0] - D_004B1920[0]) / 60.0f;
    *(u32 *)(p + 0x40) = (u32)(s32)(0.5 + 65536.0 * (f64)(D_004B1920[0] + (f32)*(s16 *)(p + 0x1C) * q3) / 360.0) & 0xFFFF;
    a4 = D_004B1920[1];
    q4 = (c[1] - a4) / 60.0f;
    *(u32 *)(p + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)(a4 + (f32)*(s16 *)(p + 0x1C) * q4) / 360.0) & 0xFFFF;
    q5 = (c[2] - D_004B1920[2]) / 60.0f;
    *(u32 *)(p + 0x48) = (u32)(s32)(0.5 + 65536.0 * (f64)(D_004B1920[2] + (f32)*(s16 *)(p + 0x1C) * q5) / 360.0) & 0xFFFF;
}
