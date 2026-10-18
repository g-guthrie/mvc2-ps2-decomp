typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004B7BE0[];

void func_00331C20(u8 *p)
{
    extern f32 func_00417440(s32);
    f32 base;
    u32 ang;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s32 *)(p + 0xD8) != 0)
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    if (*(s16 *)(p + 0x1E) >= 0x168)
        *(s16 *)(p + 0x1E) = 0;
    base = D_004B7BE0[0];
    ang = (u32)(0.5 + 65536.0 * (double)*(s16 *)(p + 0x1E) / 360.0);
    *(f32 *)(p + 0x34) = base + 10.0f * func_00417440((u16)ang);
    if (*(s16 *)(p + 0x1C) > *(s32 *)(p + 0xD4)) {
        *(s16 *)(p + 0x1C) = 0;
        p[5] = 1;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
    }
}

extern f32 D_004B7C04[];

void func_00331730(u8 *p)
{
    extern f32 func_00417440(s32);
    f32 base;
    u32 ang;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s32 *)(p + 0xD8) != 0)
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    if (*(s16 *)(p + 0x1E) >= 0x168)
        *(s16 *)(p + 0x1E) = 0;
    base = D_004B7C04[0];
    ang = (u32)(0.5 + 65536.0 * (double)*(s16 *)(p + 0x1E) / 360.0);
    *(f32 *)(p + 0x38) = base + 10.0f * func_00417440((u16)ang);
    if (*(s16 *)(p + 0x1C) > *(s32 *)(p + 0xD4)) {
        *(s16 *)(p + 0x1C) = 0;
        p[5] = 1;
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
    }
}
