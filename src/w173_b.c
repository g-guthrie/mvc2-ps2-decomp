typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_001865B0(u8 *p)
{
    extern void func_00186A60(u8 *, s32);
    extern void func_00154390(u8 *, s32);
    extern void func_001E3A70(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00186A60(p, 4);
    p[5] = 0;
    p[6] = 2;
    func_00154390(p + 0x34, (s8)(p[0x210] != 0 ? 1 : 0));
    func_001E3A70(p);
    if ((p[0x216] & 0x80) || p[0x21B] > 5) {
        D_004F1F45 = 1;
        D_004F1F46 = 1;
    }
    if (*(s8 *)(p + 0x1E7) == -1) p[0x168] = 3;
    if (*(s8 *)(p + 0x1E7) == 0) p[0x168] = 4;
    if (*(s8 *)(p + 0x1E7) == 1) p[0x168] = 5;
    func_001757E0(p, 1, p[0x168]);
}
