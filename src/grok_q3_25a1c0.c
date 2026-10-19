/* Metrowerks 3.0: ./try.sh src/grok_q3_25a1c0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_0025A260(u8 *);

void residual_0025A1C0(u8 *p)
{
    p[6]++;
    p[437] = 54;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00185490(p);
    if (p[525] != 2)
        p[525] = 0, func_00183D10(p);
    func_001757E0(p, 22, 2);
    func_0025A260(p);
}
