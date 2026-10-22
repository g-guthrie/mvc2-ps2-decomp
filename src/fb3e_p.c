typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_006207A0[];
extern u8 D_0062BBA0[];
extern u8 D_004BA830[];

s32 func_003E8DF0(u32 h, s32 mode)
{
    extern s32 func_003EBD30(u32 *, s32);
    extern void func_003ED0D0(u8 *);
    extern s32 func_003DD030(s32);
    extern s32 func_003DBD20(s32);
    extern u8 *func_003DD160(s32, s32);
    extern void func_003DBD80(u8 *pkt, s32 a1, u32 addr, u32 total, s16 p4, s16 p5, s16 p6, s16 p7, s16 p8, s16 p9, s16 p10);
    extern void func_003DC2F0(u32, u8 *);
    u8 *e;
    s32 s1;
    u8 *s2;
    e = D_006207A0 + (((u16)h - 1) << 6);
    switch (mode) {
    case 1:
        break;
    case 4:
        break;
    case 5:
    case 2:
    case 3:
    default:
        if (func_003EBD30(&h, 1) == 0) {
            func_003ED0D0(D_004BA830);
            return 0;
        }
        s1 = func_003DD030(*(s32 *)(e + 0x28));
        s2 = func_003DD160(func_003DBD20(*(s32 *)(e + 8)), 0x10);
        if (*(s32 *)(e + 0x20) == 0) {
            func_003DBD80(s2, 1, s1, *(u32 *)(e + 8), *(s16 *)(e + 0x12), *(s16 *)(e + 0x18) / 64, *(u16 *)(e + 0x1C), 0, 0, *(s16 *)(e + 0x18), *(s16 *)(e + 0x1A));
        } else {
            func_003DBD80(s2, 1, s1, *(u32 *)(e + 8), *(s16 *)(e + 0x12), *(s16 *)(e + 0x24) / 64, 0, 0, 0, *(s16 *)(e + 0x24), *(s16 *)(e + 0x26));
        }
        func_003DC2F0(((u32)s2 & 0xFFFFFFF) | 0x10000000, D_0062BBA0);
        break;
    }
    return 1;
}
