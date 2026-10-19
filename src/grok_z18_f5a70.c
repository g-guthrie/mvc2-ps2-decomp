typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void func_001F0420(u8 *);
extern void func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;

void residual_001F5A70(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_001F0420(p);
    p[0x1B5] = 0x28;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 0x15, 0xB);
}
