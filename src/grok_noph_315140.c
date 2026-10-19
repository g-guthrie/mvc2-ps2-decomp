/* Metrowerks 3.0: ./try.sh src/grok_noph_315140.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern void func_003151F0(u8 *, void *);

void func_00315140(u8 *p, void *context)
{
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    p[437] = 1;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 7, 1);
    func_001E3710(p, 21);
    func_003151F0(p, context);
}
