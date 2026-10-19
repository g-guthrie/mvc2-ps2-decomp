typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2794;
extern void func_003BD840(u8 *);
extern void func_003BD2D0(u8 *);
extern void func_003BC650(u8 *);

void residual_003BC5D0(u8 *p)
{
    u16 z = 0;
    s16 *slot;
    p[4]++;
    p[5] = 0;
    func_003BD840(p);
    func_003BD2D0(p);
    p[0x1b5] = 13;
    *(s16 *)(p + 0x1c0) = z;
    p[0x1b2] = (u8)z;
    *(s32 *)(p + 0x1d8) = 0;
    slot = (s16 *)(D_004C2794 + (p[2] * 2));
    slot[62]++;
    func_003BC650(p);
}
