/* Metrowerks 3.0: ./try.sh src/grok_nopb_258d20.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_00258D20(u8 *p)
{
    p[7]++;
    func_00175C00(p, 0);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[528] = 0;
    p[525] = 0;
    func_001757E0(p, 19, 4);
}
