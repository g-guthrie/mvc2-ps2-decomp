typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_003141E0(u8 *, u8 *);

void residual_003140F0(u8 *p, u8 *q)
{
    unsigned int offset;

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[7]++;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    q[0x13] = 0;
    q[2] = 0;
    {
        u8 cmd = 57;
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
    }
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7C);
    func_001757E0(p, 22, 11);
    func_003141E0(p, q);
}
