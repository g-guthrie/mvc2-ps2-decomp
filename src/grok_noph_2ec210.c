/* Metrowerks 3.0: ./try.sh src/grok_noph_2ec210.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_002EC2D0(u8 *, u8 *);

void residual_002EC210(u8 *p, u8 *q)
{
    p[7]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[437] = 50;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 17);
    func_002EC2D0(p, q);
}
