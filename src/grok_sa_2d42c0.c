typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_002D3230(u8 *);

void residual_002D42C0(u8 *p)
{
    p[6]++;
    if (p[0x269] == 6) {
        p[0x404] = 255;
        p[0x405] = 16;
    }
    func_002D3230(p);
    p[0x1B5] = 64;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    *(s16 *)(p + 0x1C) = 0;
    p[0x22] = 0;
    p[0x21] = 0;
    p[0x1B7] = 1;
    func_001757E0(p, 22, 0);
    func_00183D10(p);
}
