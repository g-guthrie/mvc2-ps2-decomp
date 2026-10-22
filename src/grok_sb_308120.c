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
extern int func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_0018C6E0(void *);
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


void func_00308120(u8 *p)
{
    func_00175C00(p, 0);
    p[6]++;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0x41F00000;
    *(u32 *)(p + 0x68) = 0;
    if (!p[0x1E6]) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *(u32 *)(p + 0x60) = 0x40892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 54;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 29);
}
