typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_00186A20(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern void func_002202B0(u8 *);

void func_00220140(u8 *p)
{
    unsigned int offset;

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_00185490(p);
    func_001E3210(p, 34);
    p[0x2C7] = 0;
    p[0x2C0] = 2;
    {
        u8 cmd = 54;
        *(u16 *)(p + 0x2DE) = 15;
        *(u16 *)(p + 0x2D4) = 8;
        *(u16 *)(p + 0x2E2) = 0x800;
        *(int *)(p + 0x5C) = 0;
        *(int *)(p + 0x60) = 0;
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x6C) = 0;
        p[0x1B5] = cmd;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(int *)(p + 0x1D8) = 0;
    }
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7C);
    func_00186A20(p);
    if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430))
        func_001757E0(p, 21, 31);
    else {
        func_001757E0(p, 21, 32);
        func_00183D10(p);
    }
    func_002202B0(p);
}
