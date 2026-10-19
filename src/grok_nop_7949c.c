typedef unsigned char u8;

extern void func_001757E0(u8 *, int, int);

void residual_001794A0(u8 *p)
{
    void (**vt)(u8 *);

    p[433] = 0;
    vt = *(void (***)(u8 *))(p + 1084);
    vt[6](p);
    if (p[5]) {
        p[5] = 1;
        func_001757E0(p, 0, 0);
    }
}
