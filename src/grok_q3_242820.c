/* Metrowerks 3.0: ./try.sh src/grok_q3_242820.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00175C00(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void residual_00242820(u8 *p)
{
    p[6]++;
    p[525] = 2;
    func_00175C00(p, 0);
    *(u32 *)(p + 92) = 0xC1F00000;
    *(u32 *)(p + 96) = 0x3E555555;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0xBF4DB6DB;
    if (p[486])
        *(f32 *)(p + 92) = -*(f32 *)(p + 92);
    p[437] = 37;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 0);
}
