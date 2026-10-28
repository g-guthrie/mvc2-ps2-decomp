typedef signed int s32;

extern s32 func_0010BB98(s32, s32, s32);

s32 func_00420070(s32 a, s32 b, s32 c, s32 n)
{
    s32 i;
    s32 r;
    if (n == 0) {
        goto test;
    body:
        __asm__("nop;nop;nop;nop;nop;nop;nop");
    test:
        if ((r = func_0010BB98(a, b, c)) < 0) goto body;
    } else {
        i = 0;
        goto t2;
    l2:
        r = func_0010BB98(a, b, c);
        if (!(0 > r)) return r;
        i++;
    t2:
        if (i < n) goto l2;
    }
    return r;
}
