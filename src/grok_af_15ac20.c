typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003DAA40(u8 *);

void func_0015AC20(u8 *p)
{
    if (*(s32 *)(p + 0xD4) != 0) {
        *(s32 *)(p + 0xD4) = *(s32 *)(p + 0xD4) - 1;
        return;
    }
    p[0x13C] = 1;
    *(f32 *)(p + 0x50) += (7.0f / 15.0f) * (f32) *(s32 *)(p + 0xD8);
    *(f32 *)(p + 0x54) += (7.0f / 15.0f) * (f32) *(s32 *)(p + 0xD8);
    if (*(s16 *)(p + 0x1C) == 0) {
        *(s16 *)(p + 0x1C) = 1;
        *(f32 *)(p + 0x74) -= 1.0f / 24.0f;
        if (*(f32 *)(p + 0x74) < 0.0f)
            *(f32 *)(p + 0x74) = 0.0f;
        *(f32 *)(p + 0x78) -= 1.0f / 24.0f;
        if (*(f32 *)(p + 0x78) < 0.0f)
            *(f32 *)(p + 0x78) = 0.0f;
        *(f32 *)(p + 0x7C) -= 1.0f / 24.0f;
        if (*(f32 *)(p + 0x7C) < 0.0f)
            *(f32 *)(p + 0x7C) = 0.0f;
        *(f32 *)(p + 0x80) -= 1.0f / 24.0f;
        if (*(f32 *)(p + 0x80) < 0.0f)
            *(f32 *)(p + 0x80) = 0.0f;
    }
    *(s16 *)(p + 0x1E) = (s16)(*(s16 *)(p + 0x1E) - 1);
    if (*(s16 *)(p + 0x1E) == 0)
        func_003DAA40(p);
}
