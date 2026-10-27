typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void *func_003DA750(void *p, s32 b, s32 c);
extern void func_003C4A20(u8 *);

u8 *func_003C4990(u8 *p, u8 a, u8 b) {
    u8 *o = func_003DA750(p, 1, 2);
    if (o != 0) {
        *(void (**)(u8 *))(o + 0x10) = func_003C4A20;
        o[0x20] = a;
        o[0x21] = b;
        *(u8 **)(o + 0x18) = *(u8 **)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        *(u16 *)(o + 0x26) = p[0x20] | 0x3800;
        o[1] = p[1];
        *(u16 *)(o + 0xD8) = *(u16 *)(p + 0xD8);
    }
    return p;
}
