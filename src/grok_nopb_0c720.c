/* Metrowerks 3.0: ./try.sh src/grok_nopb_0c720.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern void func_0020C7B0(u8 *, u8 *);

void residual_0020C720(u8 *p, u8 *q)
{
    p[7]++;
    p[437] = 63;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 9);
    func_001E3210(p, 30);
    func_0020C7B0(p, q);
}
