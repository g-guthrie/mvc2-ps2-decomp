typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern u8 D_004F2294[];
extern u8 D_004F284C[];

void func_003D31A0(u8 *p) {
    extern void func_003D3080(s32);
    extern void func_001E4140();
    extern void func_001E3CE0(s32);
    extern void func_0016EE50();
    if ((s8)D_004C2840[0xAA] != 0) {
        if (D_004F2294[0] == 0x1D || D_004F284C[0] == 0x1D || (s8)D_004C2840[0x9C] != 0) return;
    }
    p[0x2] = 0;
    p[0x3] = 0;
    p[0xC] = 0;
    p[0xD] = 0;
    p[0xE] = 0;
    p[0xF] = 0;
    p[0x18] = 0;
    p[0x19] = 0;
    p[0x1A] = 0;
    *(u16 *)(p + 0x2A) = 0;
    if ((s8)D_004C2840[0x5C] == 0) {
        func_003D3080(1);
        func_001E4140();
    }
    func_001E3CE0(0x39);
    *(u16 *)(p + 0x8) = 0x4650;
    *(u16 *)(p + 0xA) = 10;
    *(u32 *)(p + 0x10) = 0x42A00000;
    *(u32 *)(p + 0x14) = 0x42B00000;
    func_0016EE50();
    if ((s8)D_004C2840[0x4C] == 2) p[0xD] = 2;
}
