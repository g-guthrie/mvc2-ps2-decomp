typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_003041B0(u8 *, void *);
extern u8 *D_004C2794;

void func_00304110(u8 *p, void *context)
{
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    p[0x1B5] = 5;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 8, 2);
    func_003041B0(p, context);
}
