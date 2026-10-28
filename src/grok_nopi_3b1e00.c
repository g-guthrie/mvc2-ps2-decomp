/* Provisional: table selector, owner lifetime and callee signature need proof. */
/* Metrowerks 3.0: ./try.sh src/grok_nopi_3b1e00.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern s16 data_u32_004C1FA0[10] __attribute__((section(".sdata")));
extern void func_001E7F60(u8 *);
extern int func_00175700(u8 *);
extern void func_003B1EC0(u8 *, u8 *);

void func_003B1E00(u8 *p, u8 *q)
{
    p[36] = *(s8 *)(q + 36);
    *(f32 *)(p + 52) = *(f32 *)(q + 52);
    *(f32 *)(p + 56) = *(f32 *)(q + 56);
    *(f32 *)(p + 56) += 2.142857074737549f * (f32)data_u32_004C1FA0[p[33]];
    func_001E7F60(p);
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_003B1EC0(p, q);
    }
}
