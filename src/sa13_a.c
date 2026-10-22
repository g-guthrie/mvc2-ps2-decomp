typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_003EE930(u8 *a, u8 *b)
{
    extern u8 *func_003DD030(u8 *);
    extern void func_003DCDC0(u8 *, u8 *, s32);
    u8 *o;
    u8 *q;
    q = func_003DD030(*(u8 **)(a + 0x14));
    o = q;
    q += 0x30;
    func_003DCDC0(b, o, 0x24);
    *(u8 **)(b + 8) = q;
    q += ((*(u32 *)(o + 0x1C) + 0xF) & ~0xF);
    *(u8 **)(b + 0x10) = q;
}
