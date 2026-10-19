typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern u8 *D_004C2794;
extern s16 D_004C27A4;
extern u8 D_0046B110[];
extern u8 D_004C2090[];
extern f32 D_004C1768[];
extern int func_00174170(void);
extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_0018C6E0(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_001E3C40(u8 *);
extern u8 *func_001E7FD0(void);
extern void func_001266A0(u8 *, int, int);
extern void func_00185770(u8 *, u8 *);
extern void func_0015D010(u8 *, f32 *);
extern void func_00175910(u8 *, int, int, int);
extern void func_001D91E0(u8 *, int, int);
extern void func_00182C30(u8 *, int);
extern void func_00182DB0(u8 *, int);
extern void func_003BD840(u8 *);
extern void func_003BD2D0(u8 *);
extern void func_003BD290(u8 *);
extern void func_003BD2E0(u8 *);
extern void func_001E7F60(u8 *);
extern void func_003C80C0(u8 *, int, int);


extern void func_003A8B10(u8 *);
extern void func_002F01E0(u8 *);
void residual_002F0110(u8 *p)
{
    p[6]++;
    p[0x1B5] = 53;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00183D10(p);
    p[0x20D] = 0;
    p[0x20] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    {
        u32 bits = 0xC0D55555;
        f32 v = *(f32 *)&bits;
        if (p[0x1E6])
            v = -v;
        *(f32 *)(p + 0x5C) = v;
    }
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 21, 11);
    *(u32 *)(p + 0x2EC) = (s8)p[0x152];
    func_003A8B10(p);
    func_0018C4B0(p, 10);
    func_002F01E0(p);
}
