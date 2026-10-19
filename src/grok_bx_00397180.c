typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void func_00396F00(u8 *, u8 *);
extern void func_00396F40(u8 *, u8 *);

void func_00397180(u8 *p, u8 *q, u8 *r)
{
    if (q[0x169] != 0x16) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (q[0x168] != 0xC) {
        p[5]++;
        r[0] = 4;
        *(s16 *)(p + 0x1C) = 2;
        return;
    }
    if ((D_004D18DC & (1 << D_004D18DB)) != 0)
        return;
    r[7] = 0;
    if (*(s16 *)(q + 0x1C) <= 0) {
        p[5]++;
        r[0] = 4;
        *(s16 *)(p + 0x1C) = 2;
    }
    func_00396F00(p, r);
    func_00396F40(p, r);
}
