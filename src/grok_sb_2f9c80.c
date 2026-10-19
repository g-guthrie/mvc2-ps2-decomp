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
extern void func_001E3C40();
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


extern void func_002F8D80(u8 *);
extern void func_002F9D60(u8 *, u8 *);
void residual_002F9C80(u8 *p, u8 *q)
{
    p[0x40D] = 0xFF;
    p[0x40C] = 16;
    p[0x33B] = 1;
    D_004C2794[0x76] = ((s8)p[2] << 4) | 1;
    p[0x33C] = 16;
    p[7]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    {
        u8 v = p[0x20D];
        u8 n;
        if (v == 1) {
            n = 8;
        } else {
            if (v == 0)
                n = 7;
            else
                n = 9;
        }
        p[0x168] = n;
    }
    func_001757E0(p, 15, p[0x168]);
    func_002F8D80(p);
    func_001E3C40();
    func_002F9D60(p, q);
}
