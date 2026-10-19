/* Metrowerks: ./try.sh src/grok_r4_2ecdc0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_002ECE40(u8 *, u8 *);

void residual_002ECDC0(u8 *p, u8 *q)
{
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_001757E0(p, 20, 3);
    func_002ECE40(p, q);
}
