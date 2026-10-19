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
    u8 *chain;
    u8 st;
    s16 t;

    chain = *(u8 **)(p + 0x1E0);
    chain = *(u8 **)(chain + 0x1E0);
    q = *(u8 **)(p + 0xD4);
    if (chain != p)
        goto bump;
    st = q[5];
    if (st != 2)
        goto bump;
    if (*(s8 *)(q + 0x1B3) && st == 3)
        goto bump;
    func_00380A40(p);
    if (func_00182C90(q)) {
        t = *(s16 *)(p + 0x1C);
        t -= 3;
        *(s16 *)(p + 0x1C) = t;
    }
    t = *(s16 *)(p + 0x1C);
    t -= 1;
    *(s16 *)(p + 0x1C) = t;
    if ((s16)t < 0) {
        q[0x20A] = 0;
        q[0x203] = 8;
        if (*(s16 *)(q + 0x434) == 0)
            q[0x20A] = 7;
        else if (q[0x20D] != 2)
            func_001843A0(q);
        else
            func_001845F0(q);
        {
            u8 m = p[4];
            p[4] = m + 1;
            p[0x13C] = 0;
        }
    }
    return;
bump:
    p[5]++;
    p[6] = 0;
}
