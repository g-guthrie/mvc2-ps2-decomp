typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s16 D_004C27A4;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_001D24A0(u8 *);
extern void func_001D2680(u8 *);

s32 func_001D2390(u8 *owner, u8 mode)
{
    u8 *root;
    u8 *p;
    s32 i;
    if (D_004C27A4 < 0xE)
        return 0;
    root = func_003DA750(0, 3, 1);
    *(s16 *)(root + 0x26) = 0x2B03;
    root[0x21] = mode;
    *(u8 **)(root + 0x18) = owner;
    *(void (**)(u8 *))(root + 0x10) = func_001D24A0;
    i = 0;
    do {
        p = func_003DA750(0, 3, 1);
        *(s16 *)(p + 0x26) = 0x2B03;
        p[0x23] = i;
        p[0x20] = 0;
        p[0x21] = mode;
        *(u8 **)(p + 0x14) = root;
        *(void (**)(u8 *))(p + 0x10) = func_001D2680;
        i++;
    } while (i < 6);
    i = 0;
    do {
        p = func_003DA750(0, 3, 1);
        *(s16 *)(p + 0x26) = 0x2B03;
        p[0x23] = i;
        p[0x20] = 1;
        p[0x21] = mode;
        *(u8 **)(p + 0x14) = root;
        *(void (**)(u8 *))(p + 0x10) = func_001D2680;
        i++;
    } while (i < 6);
    return 1;
}
