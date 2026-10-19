typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0029D5E0(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);

void func_0029D690(u8 *p)
{
    u32 counterOffset;

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    *(s16 *)(p + 0x1C) = 0xF;
    func_0029D5E0(p);
    p[0x1B5] = 0x39;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    counterOffset = p[2] * 2;
    counterOffset += (u32)D_004C2794;
    counterOffset += 0x7C;
    ++*(s16 *)counterOffset;
    *(u16 *)(p + 0x1C0) |= 0x200;
    func_001757E0(p, 0x16, 0);
}
