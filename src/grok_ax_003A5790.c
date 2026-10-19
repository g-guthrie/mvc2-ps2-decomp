typedef unsigned char u8;
typedef float f32;

extern void func_003A5930(u8 *, u8 *);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern void func_001757E0(u8 *, int, int);
extern int func_00174470(u8 *);
extern void func_003A5900(u8 *, u8 *);

void func_003A5790(u8 *p, u8 *q)
{
    {
        u8 *cb = *(u8 **)(p + 0x14);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        func_003A5930(p, cb);
    }
    func_00175700(p);
    func_001E7F60(p);
    if (q[0x2B8]) {
        p[5]++;
        if (p[0x20] == 2)
            func_001757E0(p, 0x17, 1);
        else
            func_001757E0(p, 0x17, 4);
    } else if (!func_00174470(p)) {
        p[4]++;
        func_003A5900(p, q);
    }
}
