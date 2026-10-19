typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00375760(u8 *, u8 *);


void residual_00375570(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    u8 *d = p + 0xD0;
    u8 k;
    func_00175700(p);
    if (q[0x1E4] != 0x1D) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (q[0x1FD] == 7) {
        if (q[6] == 3) {
            p[5]++;
            func_001757E0(p, 0x16, 0x3C);
            return;
        }
        if (q[6] == 4) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
    }
    if (q[0x1FD] == 0xC) {
        if (q[6] == 7) {
            p[5]++;
            func_001757E0(p, 0x16, 0x3C);
            return;
        }
        if (q[6] == 8) {
            p[4] = 2;
            p[0x13C] = 0;
            return;
        }
    }
    k = q[0x168];
    if ((s8)k < 0x26) {
        p[5]++;
        func_001757E0(p, 0x16, 0x3C);
        return;
    }
    d[0] = k;
    *(u32 *)(p + 0x48) = ((u32 *)0x004B83D8)[q[0x168]];
    func_00375760(q, p);
}
