/* Metrowerks 3.0: ./try.sh src/grok_nopa_1b0cf0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;

extern int func_00175670(u8 *);

void residual_001B0CF0(u8 *p)
{
    float f;
    func_00175670(p);
    f = *(float *)(p + 280) - 0.02f;
    *(float *)(p + 280) = f;
    if (f < 0.0f)
        *(float *)(p + 280) = 0.0f;
    if ((s8)p[339] < 0) {
        p[4]++;
        p[316] = 0;
    }
}
