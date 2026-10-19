typedef unsigned char u8;
typedef signed char s8;

extern int func_003D92F0(void);
extern void func_00175C00(u8 *, int);
extern void func_001843A0(u8 *);
extern int func_00175700(u8 *);
extern int func_00176160(u8 *, int, int, int);

void func_002E5DB0(u8 *p)
{
    u8 *q = p + 696;
    u8 m;
    if (p[0x1E4] == 22 && func_003D92F0()) {
        func_00175C00(p, 0);
        func_001843A0(p);
        return;
    }
    m = p[32];
    if (m == 4 || m == 3 || m == 1 || m == 2)
        func_00175700(p);
    else if (m == 0) {
        if (q[1] == 0)
            func_00175700(p);
        else {
            func_00175700(p);
            if (*(s8 *)(p + 337)) {
                int a2 = (p[37] * 3) << 4;
                a2 += 35;
                if (*(s8 *)(p + 337) & 1)
                    a2++;
                func_00176160(p, 0, a2, 1);
            }
        }
    }
}
