typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_00451690[];
extern s32 func_00189B90(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
s32 func_002266C0(u8 *p)
{
    if (!func_00189B90(p, D_00451690, p + 0x3B0)) {
        return 0;
    }
    if (*(s32 *)(p + 0x2BC) != 1) {
        return 0;
    } else {
        func_0018A990(p, p + 0x3B0);
        p[0x1FD] = 0xC;
        p[5] = 0;
        p[7] = 0;
        p[6] = 0;
        func_00186A60(p, 0x15);
        return 1;
    }
}
