typedef unsigned char u8;
typedef signed short s16;

extern int func_00175670(u8 *);

void func_001B0C50(u8 *p)
{
    s16 timer;
    u8 *q;

    func_00175670(p);
    q = *(u8 **)(p + 24);
    *(float *)(p + 52) += (float)(*(s16 *)(q + 0x140) != 0 ? 0x12 : -0x12);
    *(int *)(p + 72) += 0x2000;
    timer = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = timer - 1;
    if (timer == 0) {
        p[4]++;
        p[316] = 0;
    }
}
