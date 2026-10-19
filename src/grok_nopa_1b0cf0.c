typedef unsigned char u8;
typedef signed char s8;

extern int func_00175670(u8 *);

void func_001B0CF0(u8 *p)
{
    float timer;

    func_00175670(p);
    timer = *(float *)(p + 280) - 0.02f;
    *(float *)(p + 280) = timer;
    if (timer < 0.0f)
        *(float *)(p + 280) = 0.0f;
    if ((s8)p[339] < 0) {
        p[4]++;
        p[316] = 0;
    }
}
