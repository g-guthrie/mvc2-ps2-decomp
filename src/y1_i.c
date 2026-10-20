typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_0033F470(u8 *p)
{
    extern f32 func_00417440();
    extern double func_00119058(f32);
    u16 a;
    f32 c;
    switch (p[4]) {
    default: return;
    case 0:
        *(s16 *)(p + 0x1C) += 2;
        if (*(s16 *)(p + 0x1C) >= 360) *(s16 *)(p + 0x1C) = 0;
        a = (u16)((u32)(s32)(0.5 + 65536.0 * (double)*(s16 *)(p + 0x1C) / 360.0));
        c = 45.0f * func_00417440(a);
        *(u32 *)(p + 0x40) = (u16)((u32)(s32)(0.5 + 65536.0 * func_00119058(c) / 360.0));
    }
}

void func_0033F630(u8 *p)
{
    extern f32 func_00417440();
    extern double func_00119058(f32);
    u16 a;
    f32 c;
    switch (p[4]) {
    default: return;
    case 0:
        *(s16 *)(p + 0x1C) += 3;
        if (*(s16 *)(p + 0x1C) >= 360) *(s16 *)(p + 0x1C) = 0;
        a = (u16)((u32)(s32)(0.5 + 65536.0 * (double)*(s16 *)(p + 0x1C) / 360.0));
        c = 20.0f * func_00417440(a);
        *(u32 *)(p + 0x40) = (u16)((u32)(s32)(0.5 + 65536.0 * func_00119058(c) / 360.0));
    }
}
