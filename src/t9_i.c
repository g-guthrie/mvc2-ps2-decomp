typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18D5;
extern u8 D_004D18D4;
extern u8 D_004D18A0[];
extern u8 D_004F20B0[];
extern u32 D_004D18C4;
extern u32 D_004D18B8;
extern u32 D_004F39B0;
extern u32 D_004F2E40;
extern u32 D_004F22D0;
extern u32 D_004F3F68;
extern u32 D_004F33F8;
extern u32 D_004F2888;

void func_00326A30(void) {
    u8 *e = D_004F20B0;
    s32 i = 0;
    D_004D18D5 = 0;
    D_004D18D4 = 0;
    do {
        *(u8 **)(D_004D18A0 + e[2] * 12 + e[0x425] * 4 + 0x18) = e;
        if (e[0] != 0) {
            u32 t = e[2];
            s8 *c = (s8 *)(D_004D18A0 + t);
            c[0x34] = c[0x34] + 1;
        }
        i++;
        e += 0x5B8;
    } while (i < 6);
    D_004F22D0 = D_004F2E40 = D_004F39B0 = D_004D18C4;
    D_004F2888 = D_004F33F8 = D_004F3F68 = D_004D18B8;
}
