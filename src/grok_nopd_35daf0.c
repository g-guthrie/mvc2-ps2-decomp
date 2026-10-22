typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern void func_0035D3F0(u8 *, int, int);
extern int func_00174470(const void *);
extern void func_0035DE40(u8 *, u8 *);

void func_0035DAF0(u8 *p, u8 *q)
{
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    if (--*(s16 *)(p + 28) == 0) {
        *(s16 *)(p + 28) = 10;
        func_0035D3F0(p, 3, 0);
    }
    if (func_00174470(p) == 0) {
        p[4]++;
        func_0035DE40(p, q);
    }
}
