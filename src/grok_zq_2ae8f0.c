typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 D_004C0C88[] __attribute__((section(".sdata")));
extern u16 D_004C0C38[] __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void residual_002AE8F0(u8 *p)
{
    unsigned int offset;

    p[6]++;
    p[0x2C6] = 0;
    p[0x2C7] = 0;
    p[0x20D] = 0;
    {
        u8 cmd = D_004C0C88[p[0x1B7] * 2];
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
    }
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7C);
    func_0018C4B0(p, 10);
    func_00185490(p);
    func_00175C00(p, 0);
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    *(u16 *)(p + 0x1C) = D_004C0C38[p[0x1B7]];
    *(unsigned *)(p + 0x5C) = 0x413AAAAA;
    if (!p[0x1E6])
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    func_00183D10(p);
    func_001E3210(p, 20);
    func_001757E0(p, 21, p[0x1B7]);
}
