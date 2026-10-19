/* Metrowerks 3.0: ./try.sh src/grok_q4_3068e0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern u8 D_004D18A0;
extern void func_001E3210(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void residual_003068E0(u8 *p)
{
    if (D_004D18A0 < 2)
        p[316] = 0;
    else {
        p[6]++;
        p[316] = 1;
        *(f32 *)(p + 56) += 548.571411f;
        *(u32 *)(p + 92) = 0;
        *(u32 *)(p + 96) = 0;
        *(u32 *)(p + 104) = 0;
        *(u32 *)(p + 108) = 0;
        *(u32 *)(p + 96) = 0xC0892492;
        func_001E3210(p, 47);
        func_001757E0(p, 26, 6);
    }
}
