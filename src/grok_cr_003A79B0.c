typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern int func_00174470(u8 *);
extern void func_003A7B10(u8 *, u8 *);

void func_003A79B0(u8 *p, u8 *q)
{
    s8 t = (s8)q[0x24] + (s8)p[0x31];
    p[0x24] = t;
    if ((s8)p[0x24] >= 8)
        p[0x24] = 7;
    if ((s8)p[0x24] < 0)
        p[0x24] = 0;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (*(s8 *)(p + 0x1B3))
        p[4]++;
    else {
        func_001E7F60(p);
        if (*(s8 *)(p + 0x1B2))
            p[4]++;
        else if (!func_00174470(p))
            func_003A7B10(p, q);
    }
}
