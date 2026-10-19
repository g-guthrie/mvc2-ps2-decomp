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
extern u8 D_004B75A0[];
extern u8 D_004B75A1[];

void residual_002B6430(u8 *p)
{
    p[6]++;
    *(s16 *)(p + 0x1C) = 72;
    func_00185490(p);
    func_0018C4B0(p, D_004B75A1[p[0x20D] * 2]);
    func_001757E0(p, 21, D_004B75A0[p[0x20D] * 2]);
    if (p[0x20D] == 2)
        p[6]++;
    else {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
    }
}
