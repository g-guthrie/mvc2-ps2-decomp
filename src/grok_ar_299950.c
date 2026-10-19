typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern int func_001757E0(u8 *, s32, s32);
extern void func_00296FB0(u8 *);

void func_00299950(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_0018C4B0(p, 0xA);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B5] = 0x15;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    {
        f32 d;
        if (p[0x1E6])
            d = 13.333333015441895f;
        else
            d = -13.333333015441895f;
        *(f32 *)(p + 0x5C) = d;
        *(u32 *)(p + 0x60) = 0xC1892492;
    }
    func_001757E0(p, 0x15, (p[0x1B7] + 0x19) & 0xFF);
    func_00296FB0(p);
}
