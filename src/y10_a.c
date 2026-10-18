typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_003828D0(u8 *p) {
    extern s8 func_00175700();
    extern void func_00381EC0();
    extern void func_001E7F60();
    s32 i;
    if (func_00175700(p) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        return;
    }
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        i = 0;
        do {
            func_00381EC0(p, 5);
            i++;
        } while (i < 7);
    }
    if (p[0x21] == 0) {
        func_001E7F60(p);
    }
}
