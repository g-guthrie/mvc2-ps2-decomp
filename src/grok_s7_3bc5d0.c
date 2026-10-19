typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_003BD840(u8 *);
extern void func_003BD2D0(u8 *);
extern void func_003BC650(u8 *);

void func_003BC5D0(u8 *p)
{
    p[4]++;
    p[5] = 0;
    func_003BD840(p);
    func_003BD2D0(p);
    p[0x1B5] = 13;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_003BC650(p);
}
