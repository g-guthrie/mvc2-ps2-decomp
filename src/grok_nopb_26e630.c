/* Metrowerks 3.0: ./try.sh src/grok_nopb_26e630.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

extern void func_001757E0(u8 *, int, int);

void residual_0026E630(u8 *p)
{
    p[6]++;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_001757E0(p, 20, 2);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
}
