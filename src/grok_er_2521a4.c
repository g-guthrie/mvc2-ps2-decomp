typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern s16 D_004C27A4 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001843A0(u8 *);
extern void func_00368FD0(u8 *);
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_002521B0(u8 *p, u8 *q)
{
    unsigned int offset;
    f32 *a, *b, *c, *d;

    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    p[0x1B5] = 0x42;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_00185490(p);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x60);
    c = (f32 *)(p + 0x68);
    d = (f32 *)(p + 0x6C);
    q[0xA] = 0;
    q[0xB] = 0;
    q[0xC] = 0;
    func_00183D10(p);
    if (D_004C27A4 < 2) {
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_001843A0(p);
        return;
    }
    func_00368FD0(p);
    func_00175C00(p, 0);
    func_001757E0(p, 0x16, 9);
}
