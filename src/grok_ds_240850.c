typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00240850(u8 *p)
{
    unsigned int offset;
    int extra;
    int cmd;

    p[6]++;
    *(s16 *)(p + 0x1C) = 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00185490(p);
    func_0018C4B0(p, 5);
    extra = 2;
    cmd = 0x2D;
    if (p[0x20D] != 2) {
        extra = 0;
        cmd = 0x28;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183D10(p);
    }
    p[0x1B5] = cmd;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_001757E0(p, 0x15, (extra + p[0x1B7]) & 0xFF);
}
