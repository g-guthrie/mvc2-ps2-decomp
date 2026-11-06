/* SDK big-number normalise: skip leading zero bytes and bits, shift, copy. */
extern void func_0c203d54(int a, unsigned char *buf);
extern void func_0c1fba00(unsigned char *d, int v, int n);
extern void func_0c203d08(unsigned char *p, int a, int b);
extern void func_0c1fb940(unsigned char *d, unsigned char *s, int n);

void func_0c204718(int a, short *e, unsigned char *dst)
{
    unsigned char buf[8];
    unsigned char *p;
    unsigned char m;
    int i, j;
    *e = a + 63;
    func_0c203d54(a, buf);
    func_0c1fba00(dst, 0, 8);
    j = i = 0;
    p = buf;
    while (*p == 0) {
        p++;
        i++;
        *e -= 8;
    }
    m = 0x80;
    while ((m & *p) == 0) {
        m >>= 1;
        j++;
    }
    func_0c203d08(p, 8 - i, j);
    *e -= j;
    func_0c1fb940(dst, p, 8 - i);
}
