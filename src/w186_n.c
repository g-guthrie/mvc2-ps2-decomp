typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern u8 D_004F7D10[];
extern u8 D_004F7D20[];
extern u8 D_004B8F38[];
extern u16 D_004F4480[];
extern u16 D_004F4494[];

void func_003D5090(u8 *p) {
    extern void func_003D4C10();
    extern void func_003D7350();
    extern void func_003D7310();
    extern void func_003D4950();
    extern void func_003D4920();
    extern void func_003D47E0();
    s32 t;
    s32 h;
    D_004C2840[0x91] = 1;
    p[0x18] = 1;
    t = *(s8 *)(p + 0x1A);
    if (t == 0) {
        h = *(s16 *)(p + 0xA);
        if (h != 0) {
            *(s16 *)(p + 0xA) = h - 1;
        } else {
            p[0x1A] = t + 1;
        }
    } else {
        func_003D4C10(p, D_004F7D10);
        func_003D4C10(p, D_004F7D20);
        if (*(s8 *)(p + 0x1A) != 0) {
            func_003D7350(0x3C, 0x1E, 0x33, D_004B8F38);
            func_003D7310(func_003D4950);
        }
        if (D_004F4480[0] != 0 || D_004F4494[0] != 0) {
            p[2] = 0;
            *(s16 *)(p + 8) = 0x4650;
        }
        h = *(s16 *)(p + 8);
        if (h != 0) {
            *(s16 *)(p + 8) = h - 1;
        } else {
            u32 c = p[2];
            if (c != 0x60) {
                p[2] = c + 1;
            }
        }
    }
    func_003D7310(func_003D4920);
    if (*(s8 *)(p + 0x19) == 0) {
        p[2] = 0;
        p[3] = 0;
        p[0xC] = 0;
        *(s16 *)(p + 8) = 0x4650;
        *(s16 *)(p + 0xA) = 10;
        *(u32 *)(p + 0x10) = 0x42A00000;
        *(u32 *)(p + 0x14) = 0x42B00000;
        func_003D47E0();
    }
}
