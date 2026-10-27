typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern int func_001A0880(void *, void *);
extern void func_001A23D0(u8 *, u8 *);
extern void func_001A2310(u8 *, u8 *);

void func_001A20F0(u8 *p, u8 *q)
{
    u8 *r = q + 0x2B8;

    if (D_004D18DC & (1 << D_004D18DB))
        return;
    func_001A0880(p, q);
    func_001A23D0(p, q);
    func_001A2310(p, q);
    {
        s8 v = r[0x38];
        if (v == 2 || v == -1)
            p[4] = 2;
    }
}
