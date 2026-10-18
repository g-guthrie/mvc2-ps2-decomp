typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003B9500();

void func_003B9440(u8 *p, s32 a, s32 b)
{
    extern u8 *func_003DA750();
    s16 i;
    u8 *o;
    for (i = 0; i < 8; i++) {
        if ((o = func_003DA750(p, 1, 2)) != 0) {
            *(u32 *)(o + 0x10) = (u32)func_003B9500;
            *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
            *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
            *(u8 **)(o + 0x18) = p;
            *(u32 *)(o + 0x14) = *(u32 *)(p + 0x14);
            o[1] = (*(u8 **)(p + 0x14))[1];
            *(s16 *)(o + 0x26) = 0x3503;
            o[0x20] = a;
            o[0x21] = b;
        }
    }
}
