typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    s16 x;
    s16 y;
    s16 len;
    s16 ang;
    f32 rad;
} Q;

void func_003EE530(Q *p, s16 lim)
{
    extern double func_001173A0(double, double);
    extern double func_001173D0(double);
    extern s16 func_00118FA8(f32);
    extern double litodp(s32);
    extern double dpadd(double, double);
    extern u32 dptoul(double);
    extern f32 dptofp(double);
    s16 y = p->y;
    s16 x = p->x;
    f32 a;
    if ((y | x) == 0) {
        a = 0.0f;
    } else {
        a = (f32)func_001173A0((double)(-y), (double)x);
        if (a < 0.0f) {
            a += 6.2831855f;
        }
    }
    p->rad = a;
    p->ang = func_00118FA8(360.0f * (p->rad / 6.2831855f));
    p->len = (u32)(s32)func_001173D0((double)(p->x * p->x) + (double)(p->y * p->y));
    if (p->len > 0x7F) {
        p->len = 0x7F;
    }
    if (p->len < lim) {
        p->x = 0;
        p->y = 0;
        p->rad = 0.0f;
        p->ang = 0;
        p->len = 0;
    }
}
