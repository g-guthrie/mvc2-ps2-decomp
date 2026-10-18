typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DA750(u8 *, s32, s32);
extern void func_0038E570();
extern u8 *D_004C29C4;

s32 func_0038E450(u8 *p)
{
    s8 j = 0;
    s8 i = 0;
    u8 *o;
    for (; j < 12; j++) {
        if ((o = func_003DA750(p, 1, 2)) != 0) {
            *(void **)(o + 0x10) = (void *)func_0038E570;
            o[0x20] = 1;
            *(u8 **)(o + 0x18) = p;
            *(s16 *)(o + 0x26) = 1;
            o[0x8E] = i;
            i++;
            o[0x98] = D_004C29C4[0x10];
        }
    }
    return 0;
}
