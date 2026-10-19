typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern int func_001757E0(u8 *, int, int);
extern int func_00174470(u8 *);
extern void func_00185490(u8 *);
extern u8 *D_004C2794;

void func_0027DF50(u8 *p)
{
    p[525] = 0;
    p[6]++;
    func_001757E0(p, 21, 1);
    *(s16 *)(p + 28) = 0;
    *(s16 *)(p + 30) = 3;
    p[7] = 0;
    if (func_00174470(p) == 0)
        func_00185490(p);
    p[0x1B5] = 50;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
}
