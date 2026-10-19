typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_00175700(u8 *);
extern s32 func_0018AB10(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002B1740(u8 *p)
{
    s8 *slot;

    p[0x40C] = 2;
    p[0x33C] = 5;
    slot = (s8 *)(p + 0x2B8 + 21);
    if ((s8)p[0x2CD] != 0) {
        if (func_0018AB10(p) != 0) {
            (*slot)--;
            func_00175700(p);
            return;
        }
    }
    {
        s16 t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t <= 0) {
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            p[6]++;
            func_001757E0(p, 22, 14);
        }
    }
    func_00175700(p);
}
