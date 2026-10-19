/* Metrowerks 3.0: ./try.sh src/grok_nopd_30b740.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_00175C00(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void residual_0030B740(u8 *p)
{
    p[6]++;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 0x430);
    func_00175C00(p, 0);
    func_00185490(p);
    func_00183D10(p);
    func_001757E0(p, 21, 26);
}
