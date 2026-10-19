typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0029D5E0(u8 *);
extern void func_00176160(u8 *, int, int, int);
extern int func_001757E0(u8 *, int, int);
extern void func_001C9420(u8 *, int, int);

void func_0029E0E0(u8 *p)
{
    unsigned int offset;

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    *(s16 *)(p + 0x1C) = 0x80;
    func_0029D5E0(p);
    func_00176160(p, 7, p[0x25] + 3, 1);
    {
        u8 cmd = 56;
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
    }
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7C);
    func_001757E0(p, 22, 8);
    func_001C9420(p, 5, 0);
}
