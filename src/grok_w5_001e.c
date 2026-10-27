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
extern u8 *func_00416180(void *, int);
extern void func_00176230(short *, short *);
extern void func_001E5F40(s32, u8 *);
extern void func_001E56C0(u8);
extern void func_00402BC0(s32);
extern void func_001E85F0(void);
extern void func_001E7720(void);
extern void func_001E8530(void);


void func_001E7F40(void)
{
    s8 a = D_004C279C;
    s8 b = D_004C279D;
    D_004C2798 = a;
    D_004C279D = 0;
    D_004C2799 = b;
    D_004C279C = 0;
}


void func_001E3240(u8 *p, s32 a1)
{
    if ((u8)a1 < 0x40)
        func_001E2420(p, a1);
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
