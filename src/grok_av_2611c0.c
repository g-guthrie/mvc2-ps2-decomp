typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern void func_00176160(u8 *, int, int, int);

typedef struct { f32 a, b, c, d; } F4;
extern F4 D_00453BA0[];

void func_002611C0(u8 *p)
{
    u8 *s1;
    F4 *s0;
    int i;

    s1 = p;
    s1[6]++;
    s1[0x1B5] = 0x47;
    s1[0x1B2] = *(u16 *)(s1 + 0x1C0) = 0;
    *(u32 *)(s1 + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[s1[2]]++;
    func_00185490(s1);
    func_00175C00(s1, 0);
    s0 = D_00453BA0;
    func_001757E0(s1, 0x16, 0);
    s1[0x23] = *(s16 *)(s1 + 0x140) != 0 ? 1 : 2;
    i = *(s16 *)(s1 + 0x140) != 0 ? 7 : 0xE;
    s0 = (F4 *)((u8 *)s0 + i * 4);
    if (s1[0x20D] != 2)
        func_00183D10(s1);
    func_00176160(s1, 4, 7, 1);
    *(f32 *)(s1 + 0x5C) = s0->a;
    *(f32 *)(s1 + 0x68) = s0->b;
    *(f32 *)(s1 + 0x60) = s0->c;
    *(f32 *)(s1 + 0x6C) = s0->d;
    *(s16 *)(s1 + 0x1C) = 0x5A;
    s1[0x2C2] = 0;
    *(s16 *)(s1 + 0x2C4) = 0;
}
