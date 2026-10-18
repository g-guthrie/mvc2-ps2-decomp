typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static int func_00149E30(int x, int n)
{
    int r = 1;
    int i;
    for (i = 0; i < n; i++)
        r *= x;
    return r;
}

void func_00149EB0(u8 *p, s32 val, s32 n, u8 c, u8 *e) {
    extern u8 *func_00149D70();
    s32 i;
    s32 started = 0;
    u8 *o;
    for (i = 0; i < n; i++) {
        s32 d = val / func_00149E30(10, n - i - 1);
        d %= 10;
        if (i == n - 1) started = 1;
        if (started != 0 || d != 0) {
            started = 1;
            o = func_00149D70(p[0x20], d + 3, e);
            if (o != 0) o[0x21] = c;
        }
        e += 12;
    }
}
