typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00270B10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00271790(u8 *p)
{
    unsigned int offset;

    p[7]++;
    {
        u8 cmd = 71;
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
    }
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7C);
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00270B10(p);
    func_001757E0(p, 21, 20);
}
