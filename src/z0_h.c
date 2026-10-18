typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
extern u8 D_004B84F8[];

u8 *func_00379850(u8 *p)
{
    extern u8 *func_003DA750();
    extern void func_00379940();
    u8 *o = 0;
    u8 *prev;
    s32 i = 0;
    while (i < D_004B84F8[p[0x1B7]]) {
        if (i == 0) {
            if ((o = func_003DA750(0, 1, 0)) != 0) {
                *(u8 **)(o + 0x14) = 0;
                prev = 0;
            } else
                return 0;
        } else {
            if ((o = func_003DA750(o, 1, 2)) == 0)
                return 0;
        }
        *(u32 *)(o + 0x10) = (u32)func_00379940;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x1700;
        o[0x23] = i;
        i++;
        *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
        *(u8 **)(o + 0x14) = prev;
        prev = o;
        *(u16 *)(o + 0xD0) = *(u16 *)(*(u8 **)(o + 0x18) + 0x168);
    }
    return o;
}
