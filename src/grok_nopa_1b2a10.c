typedef unsigned char u8;
typedef signed short s16;

extern int func_00175670(u8 *);

void func_001B2A10(u8 *p)
{
    s16 timer = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = timer - 1;
    if (timer < 0) {
        p[5]++;
        *(float *)(p + 56) = *(float *)(*(u8 **)(p + 24) + 56);
        *(int *)(p + 72) = 0;
        func_00175670(p);
    } else {
        *(float *)(p + 52) += *(float *)(p + 92);
        *(int *)(p + 72) += 8192;
    }
}
