typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00332AB0(u8 *p) {
    u32 a;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    a = (u32)((double)*(f32 *)(p + 0x50) * 65536.0 / 360.0 + 0.5);
    *(s32 *)(p + 0x40) += (u16)a;
    if (*(s16 *)(p + 0x1C) > *(s32 *)(p + 0xD4)) {
        f32 m = -1.0f;
        if (m == *(f32 *)(p + 0x50)) {
            *(s32 *)(p + 0xDC) ^= 1;
        }
        *(s16 *)(p + 0x1C) = 0;
        p[5] = 1;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
    }
}
