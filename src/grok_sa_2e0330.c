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

void residual_002E0330(u8 *p)
{
    p[6]++;
    p[0x20D] = 2;
    func_00175C00(p, 0);
    *(u32 *)(p + 0x5C) = 0xC1F00000;
    *(u32 *)(p + 0x60) = 0xC11A4924;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (p[0x1E6]) {
        *(float *)(p + 0x5C) = -*(float *)(p + 0x5C);
        *(float *)(p + 0x68) = -*(float *)(p + 0x68);
    }
    p[0x1B5] = 66;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 0);
}
