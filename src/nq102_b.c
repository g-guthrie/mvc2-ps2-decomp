typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
extern u32 D_004B83D8[];

void func_00375570(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00375760(u8 *, u8 *);
    u8 *q = *(u8 **)(p + 0x18);
    u8 *r = p + 0xD0;
    u32 s;
    func_00175700(p);
    if (q[0x1E4] != 0x1D) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    s = q[0x1FD];
    if (s == 7) {
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
    if (s == 0xC) {
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
    if (q[0x168] < 0x26) {
        p[5]++;
        func_001757E0(p, 0x16, 0x3C);
        return;
    }
    *r = q[0x168];
    *(u32 *)(p + 0x48) = D_004B83D8[q[0x168]];
    func_00375760(q, p);
}
