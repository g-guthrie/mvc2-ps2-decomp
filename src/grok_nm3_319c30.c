typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_00175C00(u8 *, int);
extern void func_00318500(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern u8 *D_004C2794;

void func_00319C30(u8 *p)
{
    p[6]++;
    func_00175C00(p, 0);
    func_00318500(p);
    func_0018C4B0(p, 10);
    p[0x1B5] = p[0x1B7] ? 83 : 81;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, (u8)((p[0x1B7] << 1) + 32));
    func_00183D10(p);
}
