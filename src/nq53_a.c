typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef float f32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));

void residual_002EBDF0(u8 *p, u8 *q)
{
    extern void func_0018C4B0(u8 *, int);
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, int);
    extern void func_00183D10(u8 *);
    extern int func_001757E0(u8 *, int, int);
    extern void func_002EBEF0(u8 *, u8 *);
    u8 t;
    ++p[6];
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = 0x3C;
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { u32 a = p[2] * 2; a += (u32)D_004C2794; a += 0x7C; ++*(s16 *)a; }
    func_001757E0(p, 0x15, (u8)(p[0x1B7] + 12));
    *(s16 *)(p + 0x1C) = 4;
    if (p[0x1B7] == 0) *(s16 *)(p + 0x1E) = 8; else *(s16 *)(p + 0x1E) = 12;
    p[0x21] = 0;
    func_002EBEF0(p, q);
}
