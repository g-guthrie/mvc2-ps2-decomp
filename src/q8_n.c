typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001F84D0(u8 *p) {
    extern void func_001F8860();
    extern void func_001F8690();
    extern void func_001F8650();
    extern void func_001F8610();
    extern void func_001F85D0();
    extern void func_001863F0();
    u32 k = p[0x1FC];
    if (k == 0x60) {
        *(s16 *)(p + 0x1C) = 0;
        func_001F8860(p);
        return;
    }
    if (k == 0x61) {
        *(s16 *)(p + 0x1C) = 1;
        func_001F8860(p);
        return;
    }
    if (p[0x212] == 1) {
        if (p[0x20D] == 1) {
            func_001F8690();
        } else {
            func_001F8650();
        }
    } else {
        if (p[0x20D] == 1) {
            func_001F8610();
        } else {
            func_001F85D0();
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
}
