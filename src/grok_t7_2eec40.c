typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001E3710(u8 *, int);
extern void func_002F1DF0(u8 *);

void func_002EEC40(u8 *p)
{
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        p[0x20D] = 2;
        p[0x1E8] = 0;
        p[0x1EA] = 0;
        {
            f32 vx = -6.666666507720947f;
            f32 vz = 0.1041666641831398f;
            if (p[0x1E6]) {
                vx = -vx;
                vz = -vz;
            }
            *(f32 *)(p + 0x5C) = vx;
            *(f32 *)(p + 0x68) = vz;
            *(f32 *)(p + 0x60) += 10.714284896850586f;
            *(f32 *)(p + 0x6C) += -0.8035714030265808f;
        }
    } else if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x60) = 0;
        func_001E3710(p, 0x34);
    }
    if ((s8)func_00175700(p) < 0) {
        func_002F1DF0(p);
    }
}
