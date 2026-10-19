/* Metrowerks 3.0: ./try.sh src/grok_nopk_23d3b0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_0023D490(u8 *, u8 *);

void func_0023D3B0(u8 *p, u8 *q)
{
    p[6]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[437] = 81;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    p[361] = 21;
    p[360] = *(s8 *)(p + 439) + 22;
    func_001757E0(p, p[361], p[360]);
    func_0023D490(p, q);
}
