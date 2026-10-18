typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, int, int);
void func_002E7700(u8 *p)
{
    unsigned int offset;
    *(volatile u8 *)(p + 0x1B5) = 0x3C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(int *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7C);
    func_001757E0(p, 0x16, 3);
}
