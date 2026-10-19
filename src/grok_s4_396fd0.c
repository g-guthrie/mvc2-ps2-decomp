typedef unsigned char u8;
typedef signed char s8;

extern void func_001757E0(u8 *, int, int);

void func_00396FD0(u8 *p, s8 *a, s8 *b)
{
    unsigned add;
    unsigned v;
    if (*a != *b) {
        *a = *b;
        add = 0;
        v = ((unsigned)(u8)(*a * 3));
        if ((u8)a[6])
            add = (u8)a[1];
        func_001757E0(p, 25, (add + v) & 0xff);
    }
}
