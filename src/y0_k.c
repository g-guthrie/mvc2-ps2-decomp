typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00154F10(u8 *p, u8 k)
{
    extern u8 *func_003DA750();
    extern void func_00154FF0();
    extern s32 func_00417A40();
    u8 *o;
    u8 t;
    t = (k == 9) ? 0x17 : 0x3B;
    if ((o = func_003DA750(0, t, 1)) != 0) {
        o[0x13C] = 0;
        *(u32 *)(o + 0x10) = (u32)func_00154FF0;
        *(u32 *)(o + 0x48) = (u16)(65536.0 * (double)(func_00417A40() % 90) / 360.0 + 0.5);
        *(u32 *)(o + 0xD0) = 0x800408;
        *(u8 **)(o + 0xC8) = p + 0x88;
    }
}
