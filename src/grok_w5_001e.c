typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 *D_004C2840;
extern volatile s8 D_004C2798;
extern volatile s8 D_004C2799;
extern volatile s8 D_004C279C;
extern volatile s8 D_004C279D;
extern u8 *D_004C2794;
extern u8 D_004BFAE0;
extern u8 *D_004C28B0;
extern u8 D_004B6A68[];

extern void func_001E46C0(s32);
extern void func_001E24E0(u8 *, s32);
extern void func_001E2420(u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern s32 func_00416180(void *, s32);
extern void func_00176230(s32, u8 *);
extern void func_001E5F40(s32, u8 *);
extern void func_001E56C0(u8);
extern void func_00402BC0(s32);
extern void func_001E85F0(void);
extern void func_001E7720(void);
extern void func_001E8530(void);

void func_001E2130(void)
{
    func_001E46C0(*(s8 *)(D_004C2840 + 0x43) == 2 ? 0x5F : 0x7F);
}

void func_001E7F40(void)
{
    s8 a = D_004C279C;
    s8 b = D_004C279D;
    D_004C2798 = a;
    D_004C279D = 0;
    D_004C2799 = b;
    D_004C279C = 0;
}

void func_001E3210(u8 *p, s32 a1)
{
    if ((u8)a1 < 0x40)
        func_001E24E0(p, a1);
}

void func_001E3240(u8 *p, s32 a1)
{
    if ((u8)a1 < 0x40)
        func_001E2420(p, a1);
}

void func_001E31D0(u8 *p)
{
    if (p[1] == 0x2E || p[1] == 0x33)
        func_001E3240(p, 0x22);
}

void func_001E3C00(u8 *p)
{
    func_001E3710(p, 0x32);
    func_001E24E0(p, 0x2B);
}

void func_001E7430(u8 *p)
{
    s32 r = func_00416180(*(void **)(p + 0x194), 0);
    func_00176230(r, D_004C28B0);
    func_001E5F40(0xC99, D_004C28B0);
}

void func_001E4260(u8 *p)
{
    if (p)
        D_004BFAE0 = 1;
    else
        D_004BFAE0 = 0;
    func_001E56C0(D_004BFAE0);
    func_00402BC0(D_004BFAE0 ^ 1);
}

void func_001E3BB0(u8 *p, s32 a1)
{
    func_001E3710(p, D_004B6A68[(u8)a1]);
    func_001E24E0(p, 0x2B);
}

void func_001E76D0(void)
{
    func_001E85F0();
    if (D_004C2794[6] == 0) {
        func_001E7720();
        func_001E8530();
    }
    func_001E7F40();
}
