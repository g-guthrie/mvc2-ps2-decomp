typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
#define F(p, n) (*(f32 *)((p) + (n)))

void func_002833D0(u8 *p)
{
    u32 counterOffset;
    p[6]++;
    p[0x1B5] = 48;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    counterOffset = p[2] * 2;
    counterOffset += (u32)D_004C2794;
    counterOffset += 0x7C;
    ++*(s16 *)counterOffset;
    func_0018C4B0(p, 5);
    func_00185490(p);
    p[0x20D] = 0;
    F(p, 0x38) = F(p, 0x430);
    F(p, 0x5C) = 0;
    F(p, 0x60) = 0;
    F(p, 0x68) = 0;
    F(p, 0x6C) = 0;
    func_00183D10(p);
    func_001757E0(p, 21, 0);
}
