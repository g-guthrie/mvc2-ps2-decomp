typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001843A0(u8 *);

void func_002E6B40(u8 *p)
{
    u8 *q = p + 0x2B8;
    p[0x1FE] = 1;
    p[0x206] = 3;
    if (*(s8 *)(p + 0x2BF) < 0) goto negative_state;

    func_00175700(p);
    /* The retail c.lt.s + bc1t path updates on unordered (NaN) values. */
    if (!(*(f32 *)(p + 0x60) < 0.0f)) {
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (*(s8 *)(q + 7) > 0) {
        p[7]++;
        func_001757E0(p, 21, 14);
        return;
    }
    return;

negative_state:
    p[0x20D] = 0;
    p[0x1FE] = 0;
    func_001843A0(p);
}
