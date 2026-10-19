typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void residual_0030D400(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[6]++;
        if (p[0x210] != 0) {
            p[0x210] = 0;
            *(unsigned int *)(p + 0x5C) = 0x3FD55555;
            *(unsigned int *)(p + 0x60) = 0xC0892492;
        }
        *(f32 *)(p + 0x5C) += 6.666666507720947f;
        *(f32 *)(p + 0x60) += -17.14285659790039f;
        if (p[0x1E6] == 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
}
