typedef unsigned char u8;
typedef signed short s16;

extern int func_00175670(u8 *);
extern u8 *D_004C2840;

void func_001B0B80(u8 *p)
{
    s16 timer;
    u8 *q;

    func_00175670(p);
    q = *(u8 **)(p + 24);
    *(float *)(p + 52) += (float)(*(s16 *)(q + 0x140) != 0 ? 0x12 : -0x12);
    *(float *)(p + 56) = *(float *)(p + 96);
    if (!(*(int *)(D_004C2840 + 0x1C) & 1))
        *(float *)(p + 56) += 3.0f;
    timer = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = timer - 1;
    if (timer == 0) {
        p[4]++;
        p[316] = 0;
    }
}
