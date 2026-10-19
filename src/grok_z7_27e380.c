typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, int, int);

void residual_0027E380(u8 *p)
{
    unsigned int offset;

    p[0x20D] = 0;
    p[6]++;
    func_001757E0(p, 21, 3);
    {
        u8 cmd = 52;
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
    }
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7C);
}
