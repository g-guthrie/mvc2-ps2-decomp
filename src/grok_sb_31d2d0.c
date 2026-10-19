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


extern void func_0031D380(u8 *);
void residual_0031D2D0(u8 *p)
{
    f32 vx, vy;
    *(u32 *)&vx = 0xC3555555;
    *(u32 *)&vy = 0x40555555;
    p[7]++;
    p[0x20D] = 2;
    *(s16 *)(p + 0x1C) = 32;
    *(u32 *)(p + 0x60) = 0x41AB6DB6;
    *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
    if (p[2]) {
        vx = -vx;
        vy = -vy;
    }
    *(f32 *)(p + 0x34) += vx;
    *(f32 *)(p + 0x5C) = vy;
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 18, 0);
    func_0031D380(p);
}
