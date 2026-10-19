/* Metrowerks 3.0: ./try.sh src/grok_nopa_1b2a10.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;

extern int func_00175670(u8 *);

void residual_001B2A10(u8 *p)
{
    s16 t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t < 0) {
        p[5]++;
        *(float *)(p + 56) = *(float *)(*(u8 **)(p + 24) + 56);
        *(int *)(p + 72) = 0;
        func_00175670(p);
    } else {
        *(float *)(p + 52) += *(float *)(p + 92);
        *(int *)(p + 72) += 8192;
    }
}
