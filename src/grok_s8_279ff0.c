typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_0027A0A0(u8 *);

void func_00279FF0(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(float *)(p + 0x38) = *(float *)(p + 0x430);
    p[0x210] = 0;
    p[0x20D] = 0;
    p[0x1B5] = 51;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 6);
    func_0027A0A0(p);
}
