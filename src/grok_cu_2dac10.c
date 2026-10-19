/* Unary callback at 0045AAD0; direction selection is bounded by 0xF. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00183D10(u8 *);
extern void func_00186A20(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2794;
extern u8 D_0045A830[];

void func_002DAC10(u8 *p)
{
    u32 a0;
    u32 v;

    p[6]++;
    if (p[0x20D] != 2) {
        *(f32 *)(p + 0x38) = 2.142857074737548828125f + *(f32 *)(p + 0x430);
        func_00183D10(p);
    }
    func_00186A20(p);
    func_0018C4B0(p, 5);
    v = *(u16 *)(p + 0x354) >> 10;
    if (*(s8 *)(p + 0x539))
        v = *(u32 *)(p + 0x2FC);
    a0 = 0x18;
    if (*(s16 *)(p + 0x140))
        a0 = 8;
    v &= 0xF;
    if (v)
        a0 = D_0045A830[v];
    *(u32 *)(p + 0x2F0) = a0;
    p[0x22] = (u8)a0;
    p[0x1B5] = *(s8 *)(p + 0x2BC) + 0x54;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    {
        int strength = 0;
        if (*(u32 *)(p + 0x2F4)) strength = 10;
        func_001757E0(p, 22, (u8)strength);
    }
}
