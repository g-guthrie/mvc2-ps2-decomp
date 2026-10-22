typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern u8 D_004BF514[4];

u8 func_00189CE0(u8 *p, u8 *unused, u8 *q) {
    extern void func_0018A920(u8 *, u8 *);
    s8 t;
    u16 f;
    u32 g;
    t = q[1] - 1;
    q[1] = t;
    if (t <= 0) {
        return q[0] = 0;
    }
    f = (*(u16 *)(p + 0x35E) & 0x3C00) >> 10;
    if (f == 0) return 0;
    g = f & 0xFFFF;
    if (g == D_004BF514[(q[3] + 1) & 3]) {
        q[4] = 1;
    } else if (g == D_004BF514[(q[3] - 1) & 3]) {
        q[4] = -1;
    } else {
        return 0;
    }
    q[0]++;
    q[2]--;
    q[3] = ((s8)q[3] + (s8)q[4]) & 3;
    func_0018A920(p, q);
    return 0;
}
