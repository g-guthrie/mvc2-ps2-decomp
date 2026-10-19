typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00230020(u8 *, u8 *);

void func_002301C0(u8 *p, u8 *q)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    } else {
        {
            int t;
            t = p[7];
            t = t + 1;
            p[7] = t;
        }
        q[0x15] = 0;
        func_00230020(p, q);
    }
}
