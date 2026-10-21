typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

void func_00337D50(u8 *p)
{
    u32 nextPhase = (u32)p[4] + 1u;
    u32 phase;
    s16 direction;
    p[4] = (u8)nextPhase;
    phase = (u32)p[4] % 40u;
    p[4] = (u8)phase;
    if ((u8)phase == 0) {
        if (*(s16 *)(p + 0x1E) == 1) {
            *(f32 *)(p + 0x78) = 1.0f;
            *(f32 *)(p + 0x7C) = 1.0f;
            *(f32 *)(p + 0x80) = 1.0f;
        }
        if (*(s16 *)(p + 0x1E) == -1) {
            *(u32 *)(p + 0x78) = 0;
            *(u32 *)(p + 0x7C) = 0;
            *(u32 *)(p + 0x80) = 0;
        }
        direction = *(s16 *)(p + 0x1E);
        *(s16 *)(p + 0x1E) = (s16)(-direction);
    } else {
        *(f32 *)(p + 0x78) += (f32)*(s16 *)(p + 0x1E) / 40.0f;
        *(f32 *)(p + 0x7C) += (f32)*(s16 *)(p + 0x1E) / 40.0f;
        *(f32 *)(p + 0x80) += (f32)*(s16 *)(p + 0x1E) / 40.0f;
    }

    *(s16 *)(p + 0x1C) = (s16)(*(s16 *)(p + 0x1C) + 3);
    *(s16 *)(p + 0x1C) = (s16)(*(s16 *)(p + 0x1C) % 360);
    *(u32 *)(p + 0x44) = (u16)(s32)(0.5 + 65536.0 * (f64)*(s16 *)(p + 0x1C) / 360.0);
}
