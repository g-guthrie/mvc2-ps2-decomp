/* Metrowerks 3.0: ./try.sh src/grok_nopi_3a5ca0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern s16 D_004C1EB0;
extern void func_001E7F60(u8 *);
extern int func_00175700(u8 *);
extern void func_003A5D60(u8 *, u8 *);

void residual_003A5CA0(u8 *p, u8 *q)
{
    p[36] = *(s8 *)(q + 36);
    *(f32 *)(p + 52) = *(f32 *)(q + 52);
    *(f32 *)(p + 56) = *(f32 *)(q + 56);
    *(f32 *)(p + 56) += 2.142857074737549f * (f32)(&D_004C1EB0)[p[33]];
    func_001E7F60(p);
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_003A5D60(p, q);
    }
}
