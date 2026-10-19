/* Metrowerks 3.0: ./try.sh src/grok_nope_1b2e80.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;

extern void func_001B0FA0(u8 *, int);
extern int func_00175670(u8 *);

void residual_001B2E80(u8 *p)
{
    s16 t;
    u8 *q;

    *(float *)(p + 56) += *(float *)(p + 96);
    *(float *)(p + 96) += *(float *)(p + 108);
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t > 0)
        *(float *)(p + 52) += *(float *)(p + 92);
    q = *(u8 **)(p + 24);
    if (!(240.0f + *(float *)(q + 56) <= *(float *)(p + 56))) {
        p[5]++;
        func_001B0FA0(p, 12);
        q = *(u8 **)(p + 24);
        *(float *)(p + 56) = *(float *)(q + 56);
        func_00175670(p);
    }
}
