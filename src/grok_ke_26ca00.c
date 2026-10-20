typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00454600[5];

void residual_0026CA00(unsigned char *p)
{
    p[6]++;
    jtbl_00454600[p[32]](p);
}
