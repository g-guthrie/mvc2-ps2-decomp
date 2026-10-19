typedef unsigned char u8;
typedef signed short s16;

extern void func_001E3240(u8 *, int);
extern void func_00389170(u8 *, u8 *);
extern void func_00389230(u8 *, u8 *);
extern int func_00175700(u8 *);

void func_00388B30(u8 *p, u8 *q)
{
    u8 *r = q + 0x2B8;
    if (*(s16 *)(q + 0x2D6) == 0) {
        func_001E3240(p, 30);
        p[5]++;
        p[6] = 0;
        p[0x13C] = 1;
        func_00389170(p, q);
        return;
    }
    p[0x13C] = 1;
    if (r[0x19])
        p[0x13C] = 0;
    func_00389230(p, q);
    func_00175700(p);
}
