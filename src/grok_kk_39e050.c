typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004727E0[];

void func_0039E050(u8 *p)
{
    float *q = *(float **)(p + 24);
    *(float *)(p + 52) = q[52 / 4];
    jtbl_004727E0[p[5]](p);
}
