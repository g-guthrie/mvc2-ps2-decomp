typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s8 func_00175700();
extern void func_001757E0();

void func_001C66E0(u8 *p) {
    u32 t;
    if (func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)(p + 0x5C) = 0xC0E2AAAA;
        } else {
            *(u32 *)(p + 0x5C) = 0x40E2AAAA;
        }
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x19, 5);
    }
}

void func_00350C10(u8 *p) {
    u32 t;
    f32 f;
    if (func_00175700(p) < 0) {
        t = p[5];
        p[5] = t + 1;
        if (*(s16 *)(p + 0x140) != 0) f = -5.0f; else f = 5.0f;
        *(f32 *)(p + 0x5C) = f;
        *(s32 *)(p + 0x68) = 0;
        *(s16 *)(p + 0x1C) = 0x2C;
        func_001757E0(p, 0x17, 4);
    }
}

