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

void residual_002E69E0(u8 *p)
{
    u8 *q;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 21, 17);
    } else {
        q = func_001E7FD0();
        if (q != 0) {
            p[7]++;
            p[0x206] = 3;
            p[0x1FE] = 1;
            p[0x20B] = 195;
            func_001266A0(p, 5, 5);
            func_00185770(p, q);
            func_001757E0(p, 21, 13);
            q[0x24A] = 0;
            func_001E3C40(p);
        }
    }
}
