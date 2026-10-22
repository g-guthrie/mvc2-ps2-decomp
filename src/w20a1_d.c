typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A0;
extern s8 D_004D18D4[];
extern u8 *D_004D18B8[][3];
extern u8 D_00448EF0[];

s32 func_00188F80(u8 *p)
{
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern s32 func_0018AC30(u8 *);
    extern void func_00186A60(u8 *, s32);
    extern void func_001917F0(u8 *, s32, s32);
    u8 k;
    u8 **row;
    u8 *a, *b;

    if (p[0x1E4] != 0x12) return 0;
    if (D_004D18A0 >= 5) return 0;
    if (D_004D18D4[p[2]] != 1) return 0;
    if (func_00189310(p, D_00448EF0, p + 0x3F0) == 0) return 0;
    if (*(s8 *)*(u8 **)(p + 0x420) == 0) return 0;
    if (*(s8 *)(p + 0x1F2) == 0) return 0;
    if (*(s8 *)(p + 0x539) != 0) {
        k = func_0018AC30(p);
    } else {
        k = 2;
        if ((*(u16 *)(p + 0x3F6) & 0x80) != 0) k = 1;
    }
    row = D_004D18B8[p[2]];
    a = row[k];
    if (*(s16 *)(a + 0x434) == 0) {
        k ^= 3;
        b = row[k];
        if (*(s16 *)(b + 0x2B4) != 0) return 0;
        if (*(s16 *)(b + 0x434) == 0) return 0;
    } else {
        if (*(s16 *)(a + 0x2B4) != 0) return 0;
    }
    p[0x1B4] = 0;
    p[0x26B] = k;
    p[0x26A] = 4;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x1C);
    func_001917F0(p, 0, 0x700000);
    return 1;
}
