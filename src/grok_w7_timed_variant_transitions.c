typedef unsigned char u8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002B7120(u8 *p)
{
    func_00175700(p);
    --*(s16 *)(p + 0x1C);
    if (*(s16 *)(p + 0x1C) > 0)
        return;

    p[6]++;
    if (p[0x1B7] == 0) {
        if (*(s16 *)(p + 0x140) != 0)
            func_001757E0(p, 21, 31);
        else
            func_001757E0(p, 21, 28);
    } else {
        if (*(s16 *)(p + 0x140) != 0)
            func_001757E0(p, 21, 33);
        else
            func_001757E0(p, 21, 30);
    }
}
