typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern int func_00175700(u8 *);
extern int func_0018AB10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 D_004D18A0;

void func_002A5410(u8 *p, u8 *q)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (p[0x22] != 0 && func_0018AB10(p) != 0) {
        ++*(s16 *)(p + 0x1E);
        if (*(s16 *)(p + 0x1E) <= 4)
            goto after_reset;
        *(s16 *)(p + 0x1E) = 0;
        *(s16 *)(p + 0x1C) += 4;
        --p[0x22];
    after_reset:;
    }
    if (D_004D18A0 < 5) {
        if (--*(s16 *)(p + 0x1C) != 0)
            return;
    }
    ++p[7];
    q[9] = 2;
    *(s16 *)(p + 0x1C) = 0x18;
    func_001757E0(p, 0x16, 6);
}
