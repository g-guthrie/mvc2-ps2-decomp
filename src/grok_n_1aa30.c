typedef unsigned char u8;

extern int func_00175700(u8 *);
extern void func_0031A990(u8 *, u8 *);

void residual_0031AA30(u8 *p, u8 *q)
{
    func_00175700(p);
    if (p[0x15B] != 0) {
        p[0x15B] = 0;
        p[6]++;
        *(u8 **)(q + 0x1C8) = p;
        q[0x1B5] = 0x20;
        q[0x20A] = 0x12;
        func_0031A990(p, q);
    }
}
