typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003A3050();
void func_003A2FB0(u8 *p) {
    s32 i = 0;
    u8 *o;
    do {
        if ((o = func_003DA750(0, 1, 0)) == 0) break;
        *(void **)(o + 0x10) = func_003A3050;
        o[0x21] = i;
        *(s32 *)(o + 0xD8) = (u8)i;
        o[0x20] = i;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        *(s16 *)(o + 0x26) = 0x2C03;
        *(s8 *)(p + 0x2C6) |= 1 << i;
        i++;
    } while (i < 4);
}

