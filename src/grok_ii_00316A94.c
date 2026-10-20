/* ./try.sh src/grok_ii_00316A94.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern void func_00186A60(u8 *, s32);

void residual_00316AA0(u8 *p)
{
    s32 n;
    s8 v;
    s32 arg;

    p[5] = 0;
    n = 2;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    if (v == n)
        goto c2;
    if (v == 1)
        goto c1;
    if (v == 0)
        goto c0;
    arg = 0x1D;
    goto call;
c0:
    p[0x1FD] = 4;
    goto join;
c1:
    p[0x1FD] = 3;
    goto join;
c2:
    p[0x1FD] = 3;
join:
    arg = 0x1D;
call:
    func_00186A60(p, arg);
}
