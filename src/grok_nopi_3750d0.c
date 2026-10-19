/* Metrowerks 3.0: ./try.sh src/grok_nopi_3750d0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;

extern int func_00175700(u8 *);
extern void func_00375220(u8 *, u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_003750D0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    u8 *slot = p + 0xD0;

    func_00175700(p);
    if (q[0x1E4] != 29) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (q[0x168] < 38) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (q[0x1FD] == 7 && q[6] == 4) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (q[0x1FD] == 12 && q[6] == 8) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    func_00375220(q, p);
    if (slot[0] != q[0x168]) {
        slot[0] = q[0x168];
        func_001757E0(p, 22, slot[0] + 7);
    }
}
