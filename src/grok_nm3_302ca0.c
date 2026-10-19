typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00302D80(u8 *, u8 *);
extern u8 *D_004C2794;

void residual_00302CA0(u8 *p, u8 *q)
{
    p[7]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00183D10(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    q[0] = 0;
    p[0x1B5] = (s8)p[0x1B7] + 48;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, p[0x1B7]);
    *(s16 *)(p + 0x1E) = (s8)p[0x151];
    p[0x151] = 0;
    func_00302D80(p, q);
}
