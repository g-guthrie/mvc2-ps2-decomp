typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_00380A40(u8 *);
extern int func_00182C90(u8 *);
extern void func_001843A0(u8 *);
extern void func_001845F0(u8 *);

void func_00380850(u8 *p)
{
    u8 *q;
    u8 *chain = *(u8 **)(p + 0x1E0);
    u8 st;
    chain = *(u8 **)(chain + 0x1E0);
    q = *(u8 **)(p + 0xD4);
    st = q[5];
    if (chain != p || st != 2) {
        p[5]++;
        p[6] = 0;
        return;
    }
    if (*(s8 *)(q + 0x1B3)) {
        if (st == 3) {
            p[5]++;
            p[6] = 0;
            return;
        }
    }
    func_00380A40(p);
    if (func_00182C90(q))
        *(s16 *)(p + 0x1C) -= 3;
    *(s16 *)(p + 0x1C) -= 1;
    if (*(s16 *)(p + 0x1C) < 0) {
        q[0x20A] = 0;
        q[0x203] = 8;
        if (*(s16 *)(q + 0x434) == 0)
            q[0x20A] = 7;
        else if (q[0x20D] == 2)
            func_001845F0(q);
        else
            func_001843A0(q);
        p[4]++;
        p[0x13C] = 0;
    }
}
