typedef unsigned char u8;
typedef signed short s16;

extern void func_001E3210(u8 *, int);
extern void func_00175700(u8 *);
extern void func_00248320(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00360530(u8 *, int, int);

void func_00246960(u8 *p, u8 *q)
{
    s16 t;
    int i;

    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s16 *)(p + 0x1C) == 0x5A)
        func_001E3210(p, 0x15);
    func_00175700(p);
    func_00248320(p);
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        p[7]++;
        func_001757E0(p, 0x16, 7);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        return;
    }
    t = *(s16 *)(p + 0x1E);
    *(s16 *)(p + 0x1E) = t - 1;
    if (t == 0) {
        *(s16 *)(p + 0x1E) = 0xA;
        if (q[7] != 0) {
            u8 n = q[7];
            q[7] = n - 1;
            i = 0;
            do {
                func_00360530(p, 1, i & 0xFF);
                i++;
            } while (i < 10);
            func_001E3210(p, 0x1F);
        }
    }
}
