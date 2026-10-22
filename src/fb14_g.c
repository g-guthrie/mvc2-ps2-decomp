typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* 0x00168C10 */
extern u8 *D_004C2840;
extern u8 D_004D18D8[];
extern u8 D_004D18A0[];
extern u8 D_004D18A1[];
extern void func_00169C30(u8 *);
extern s32 func_00168D90(u8 *);
extern void func_00168E80(u8 *);
extern void func_001695A0(u8 *);
extern s32 func_00169600(u8 *);
void func_00168C10(u8 *p) {
    s32 mask;
    s32 x;
    p[0x45E] = 0;
    p[0x471] = 0;
    if (*(s8 *)(D_004C2840 + 0x2E) != 0) p[0x470] = 7;
    *(s16 *)(p + 0x4F0) = 0;
    if (*(s8 *)(p + 0x4B9) != 0) p[0x4B9] = *(s8 *)(p + 0x4B9) - 1;
    if (p[0x425] != 0) return;
    if (D_004D18D8[0] & (1 << p[2])) return;
    if (*(s8 *)(p + 0x1B4) != 0) return;
    if (*(s8 *)(p + 0x4B8) != 0) p[0x4B8] = *(s8 *)(p + 0x4B8) - 1;
    if (D_004D18A0[0] > 4) {
        func_00169C30(p);
        return;
    }
    if (D_004D18A1[0] & 2) return;
    if ((*(u8 **)(p + 0x220))[0x249] != 0) return;
    do {
        if (func_00168D90(p) == 2) func_00168E80(p);
        func_001695A0(p);
    } while (func_00169600(p) == 1);
    x = *(s8 *)(p + 0x45A);
    if (x != 0) {
        mask = 0x1000;
        if ((s8)x == *(s8 *)(p + 0x45B)) {
            u32 t = p[0x1E4];
            if (t != 5 && t != 6 && t != 9 && t != 0x14) {
                p[0x45A] = 0;
                mask = 0;
            }
        }
        *(u16 *)(p + 0x4F0) |= (u16)mask;
    }
    p[0x45B] = *(s8 *)(p + 0x45A);
    p[0x497] = p[5];
}
