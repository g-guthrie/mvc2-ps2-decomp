/* Metrowerks 3.0: ./try.sh src/grok_q4_ed420.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002ED420(u8 *p)
{
    u8 *s1 = *(u8 **)(p + 476);

    func_00175700(p);
    if (*(s8 *)(p + 337) != 0)
        return;
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    if (*(s8 *)(p + 529) == 0 && *(s8 *)(s1 + 529) == 0)
        return;
    p[6]++;
    func_001757E0(p, 15, 1);
    *(s16 *)(p + 28) = 56;
}
