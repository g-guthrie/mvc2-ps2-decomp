typedef unsigned char u8;
extern int func_00188690(u8 *);
extern int func_00188ED0(u8 *);
extern int func_00188C70(u8 *);
extern int func_00189130(u8 *);
extern int func_002D1490(u8 *);
extern int func_002D1510(u8 *);
extern int func_002D1600(u8 *);
extern int func_002D1590(u8 *);
extern int func_002D1670(u8 *);
extern int func_002D16F0(u8 *);
extern int func_002D1780(u8 *);
extern int func_002D1800(u8 *);
extern int func_002D18B0(u8 *);
extern int func_002D1920(u8 *);
extern int func_002D1B10(u8 *);
extern int func_001891F0(u8 *, int);
extern void func_00186A60(u8 *, int);
extern void func_00187BB0(u8 *);
extern void func_00188330(u8 *);

void func_002D1330(u8 *p)
{
    if (func_00188690(p)) return;
    if (func_00188ED0(p)) return;
    if (func_00188C70(p)) return;
    if (func_00189130(p)) return;
    if (func_002D1490(p)) return;
    if (func_002D1510(p)) return;
    if (func_002D1600(p)) return;
    if (func_002D1590(p)) return;
    if (func_002D1670(p)) return;
    if (func_002D16F0(p)) return;
    if (func_002D1780(p)) return;
    if (func_002D1800(p)) return;
    if (func_002D18B0(p)) return;
    if (func_002D1920(p)) return;
    if (func_002D1B10(p)) return;

    if (func_001891F0(p, 6)) {
        p[0x1FD] = 6;
        p[5] = 0;
        p[7] = 0;
        p[6] = 0;
        func_00186A60(p, 21);
        return;
    }

    func_00187BB0(p);
    func_00188330(p);
}
