/* Format a clamped leading digit and eight hex digits, then encode display bytes. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

extern const char D_004B1138[];
extern const char D_004B1140[];
extern const char D_004B1148[];
extern s32 func_0011F938(char *, const char *, ...);

void func_00136570(u8 *p)
{
    u32 n = *(u32 *)(p + 0x1DC);
    char *s0 = (char *)p + 0x1B0;
    u32 i;
    n = n > 9u ? 9u : n;
    func_0011F938(s0, D_004B1138, n);
    if (n != 0) {
        i = *(u32 *)(p + 0x1E0);
        func_0011F938(s0 + 1, D_004B1140, i);
    } else {
        s0[0] = 0x20;
        i = *(u32 *)(p + 0x1E0);
        func_0011F938(s0 + 1, D_004B1148, i);
    }
    n = 0;
    do {
        s8 v;
        v = (s8)s0[n] - 0x30;
        s0[n] = v;
        if (v < 0)
            s0[n] = -1;
        n++;
    } while (n < 9);
}
