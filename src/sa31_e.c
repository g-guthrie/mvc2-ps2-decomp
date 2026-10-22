typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *func_003DA750(u8 *, s32, s32);
extern void func_0037BF40(void);

u8 *func_0037BE60(u8 *a) {
    u8 *o;
    u8 *prev;
    s32 i;
    o = 0;
    i = 0;
    do {
        if (i == 0) {
            o = func_003DA750(0, 1, 0);
            if (o != 0) {
                *(s32 *)(o + 0x14) = 0;
                prev = 0;
            } else {
                return 0;
            }
        } else {
            o = func_003DA750(o, 1, 2);
            if (o == 0) {
                return 0;
            }
        }
        *(void **)(o + 0x10) = func_0037BF40;
        *(u8 **)(o + 0x18) = a;
        *(s16 *)(o + 0x26) = 0x1703;
        o[0x23] = i;
        *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
        i++;
        *(u8 **)(o + 0x14) = prev;
        *(u16 *)(o + 0xD0) = *(u16 *)(*(u8 **)(o + 0x18) + 0x168);
        prev = o;
    } while (i < 16);
    return o;
}
