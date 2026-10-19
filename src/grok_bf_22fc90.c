typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_0022FC90(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x220);
    if ((s8)func_00175700(p) >= 0) {
        p[0x209] = 1;
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        return;
    }
    p[0x24B] = 5;
    p[0x1E6] ^= 1;
    if ((s8)p[0x211] == (s8)q[0x211]) {
        if ((s8)q[0x211] == 1)
            *(f32 *)(q + 0x34) = *(f32 *)(p + 0x34) - 1.0f;
        if ((s8)q[0x211] == 2)
            *(f32 *)(q + 0x34) = 1.0f + *(f32 *)(p + 0x34);
    }
    func_001843A0(p);
}
