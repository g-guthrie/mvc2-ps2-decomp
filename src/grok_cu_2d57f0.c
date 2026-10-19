/* Unary callback at jtbl_0045A5A0[0]. Three native initialized floats;
 * twelve-byte payload aligned to sixteen bytes, with no padding elements. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001548D0(u8 *, f32 *, int);
extern void func_001E3B70(u8 *, int);

void func_002D57F0(u8 *p)
{
    f32 v[3] __attribute__((aligned(16)));

    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (p[0x15B])
        func_00175C00(*(u8 **)(p + 0x1DC), 6);
    if (*(s8 *)(p + 0x150)) {
        p[0x150] = 0;
        func_001E3710(p, 0x4F);
    }
    {
        int c = *(s8 *)(p + 0x151);
        if (c == 0)
            return;
        if ((s8)c > 0) {
            p[0x151] = 0;
            *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
            (*(u8 **)(p + 0x1DC))[0x20A] = 0xE;
            (*(u8 **)(p + 0x1DC))[0x1B5] = 0x20;
        } else {
            p[0x151] = 0;
            v[0] = -161.66665649414062f;
            v[1] = 107.14285278320312f;
            v[2] = 0.0f;
            func_001548D0(p, v, 0);
            func_001E3B70(*(u8 **)(p + 0x1DC), 0);
        }
    }
}
