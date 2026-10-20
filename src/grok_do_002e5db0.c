typedef unsigned char u8;
typedef signed char s8;

extern int func_003D92F0(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_001843A0(u8 *);
extern int func_00175700(u8 *);
extern void func_00176160(u8 *, int, int, int);

void func_002E5DB0(u8 *p)
{
    u8 *q = p + 0x2B8;
    if (p[0x1E4] == 22) {
        if (func_003D92F0(p)) {
            func_00175C00(p, 0);
            func_001843A0(p);
            return;
        }
    }
    switch (p[0x20]) {
    case 0:
        if (q[1] == 0) {
            func_00175700(p);
            return;
        }
        func_00175700(p);
        if (*(s8 *)(p + 0x151)) {
            int a2 = ((p[0x25] * 3) << 4) + 0x23;
            if (*(s8 *)(p + 0x151) & 1)
                a2++;
            func_00176160(p, 0, a2, 1);
        }
        break;
    case 2: case 1: case 3: case 4:
        func_00175700(p);
        break;
    }
}
