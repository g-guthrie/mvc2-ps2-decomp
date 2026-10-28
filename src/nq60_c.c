typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

extern long long func_00117B58(long long, long long);
extern long long func_001174C0(long long, long long);
extern u32 func_0011FFA0(u8 *);
extern u8 D_00632340[];

void func_00411438(long long n, u8 *buf, long size) {
    long i;
    long len;
    u8 *q;
    u8 *p;
    for (i = 0; i < 32; i++) {
        p = buf + i;
        *p = func_00117B58(n, 10);
        n = func_001174C0(n, 10);
        if (n == 0) {
            *p = 0;
            break;
        }
    }
    q = D_00632340;
    i = 0;
    len = func_0011FFA0(q);
    if (len >= size - 1) len = size - 1;
    for (; i < len; i++) {
        buf[i] = D_00632340[len - 1 - i];
    }
    buf[i] = 0;
}
