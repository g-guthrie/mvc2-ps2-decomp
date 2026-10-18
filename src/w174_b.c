typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_00315F10(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001DD8A0(u8 *, s32, s32);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
    if (*(s16 *)(p + 0x140) != 0) {
        if (*(s8 *)(p + 0x211) != 2) return;
    } else {
        if (*(s8 *)(p + 0x211) != 1) return;
    }
    p[6]++;
    p[0x208] = 3;
    *(u32 *)(p + 0x60) = 0xC1F00000;
    func_001757E0(p, 0xF, 0xD);
    D_004F1F45 = 3;
    D_004F1F46 = 1;
    func_001E3710(p, 0x2F);
    func_001DD8A0(p, 8, 3);
}
