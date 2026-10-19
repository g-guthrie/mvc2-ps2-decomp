typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_00176160(u8 *, int, int, int);
extern void func_00175C00(u8 *, int);

void func_002C5030(u8 *p)
{
    s16 t;

    func_00176160(p, 3, 4, 1);
    if (p[0x15B] == 0)
        return;
    if ((s8)p[0x15B] > 0) {
        *(s16 *)(p + 0x1C) = (u8)p[0x15B];
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 2;
        t = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = t / 2;
        p[0x15B] = 0;
        func_00176160(p, 0, *(s16 *)(p + 0x1C) + p[0x25] * 5, 1);
    } else {
        p[0x15B] = 0;
        func_00175C00(p, 0);
        return;
    }
}
