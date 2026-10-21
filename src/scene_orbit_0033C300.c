typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
extern f32 D_0045ECD0[3];
extern double func_00119B08(s32);
extern s32 dptoli(double);
extern f32 func_00417440(u32);
extern f32 func_00417500(u32);
void func_0033C300(u8 *p) {
    u32 angle;
    if (*(s16 *)(p + 0x1C) >= 300)
        *(s16 *)(p + 0x1C) = 180;
    angle = (u32)dptoli(0.5 + 65536.0 * func_00119B08((s32)*(s16 *)(p + 0x1C) + 90) / 360.0) & 0xFFFFu;
    *(u32 *)(p + 0x44) = angle;
    angle = (u32)dptoli(0.5 + 65536.0 * func_00119B08((s32)*(s16 *)(p + 0x1C)) / 360.0) & 0xFFFFu;
    *(f32 *)(p + 0x34) = D_0045ECD0[0] + 850.0f * func_00417440(angle);
    angle = (u32)dptoli(0.5 + 65536.0 * func_00119B08((s32)*(s16 *)(p + 0x1C)) / 360.0) & 0xFFFFu;
    *(f32 *)(p + 0x3C) = D_0045ECD0[2] + 850.0f * func_00417500(angle);
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
}
