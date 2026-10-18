typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_002B2510(u8 *p) {
    extern void func_001757E0();
    f32 v;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (*(s32 *)(p + 0xD0) == 0) {
        func_001757E0(p, 2, 0);
        if (p[0x1E6] != 0) v = 13.33333302f;
        else v = -13.33333302f;
        *(f32 *)(p + 0x5C) = v;
    } else {
        func_001757E0(p, 2, 4);
        if (p[0x1E6] != 0) v = 16.66666603f;
        else v = -16.66666603f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) v = -0.4166666567f;
        else v = 0.4166666567f;
        *(f32 *)(p + 0x68) = v;
    }
}
