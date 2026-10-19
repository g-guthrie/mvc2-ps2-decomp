/* Metrowerks 3.0: ./try.sh src/grok_q4_307490.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00175C00(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00307490(u8 *p, u8 *q)
{
    p[6]++;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[525] = 0;
    func_00175C00(p, 0);
    func_00185490(p);
    func_00183D10(p);
    p[437] = 52;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 27);
    *(u16 *)(q + 18) = *(u16 *)(p + 360);
}
