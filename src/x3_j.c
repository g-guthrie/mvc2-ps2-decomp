typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_002875E0(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_00385A20();
    extern void func_001C09A0();
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    switch (p[0x1FC]) {
    case 2:
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_00385A20(p, 0);
            func_001C09A0(p, 0);
        }
        break;
    case 1:
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            if (*(s16 *)(p + 0x140) == 0) {
                *(u32 *)(p + 0x5C) = 0xC0A00000;
                *(u32 *)(p + 0x68) = 0x3EA00000;
            } else {
                *(u32 *)(p + 0x5C) = 0x40A00000;
                *(u32 *)(p + 0x68) = 0xBEA00000;
            }
        }
        break;
    case 0:
        break;
    }
}
