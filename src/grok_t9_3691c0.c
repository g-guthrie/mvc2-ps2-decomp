typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef float f32;

extern u16 *D_004C29B4;
extern void func_0036A8B0(u8 *);
extern int func_0036A5F0(u8 *);
extern void func_001AD1E0(u8 *, int, int);
extern void func_001757E0(u8 *, int, int);

void residual_003691C0(u8 *p)
{
    u8 *parent;
    f32 add;

    parent = *(u8 **)(p + 0x18);
    if (*D_004C29B4 != *(u16 *)(p + 0x168)) {
        func_0036A8B0(p);
        return;
    }
    if (func_0036A5F0(p) != 0) {
        func_0036A8B0(p);
        return;
    }
    if ((s8)p[0x151] == 0)
        return;
    p[5]++;
    p[0x13C] = 1;
    p[0x24] = 0xC;
    p[0x31] = (u8)(0xFFFF - ((s8)p[2] * 4));
    if (*(s16 *)(p + 0x140))
        add = 226.666656494140625f;
    else
        add = -226.666656494140625f;
    *(f32 *)(p + 0x34) += add;
    *(f32 *)(p + 0x38) = *(f32 *)(parent + 0x430);
    func_001AD1E0(p, 0x12, 0);
    func_001AD1E0(p, 0x12, 1);
    func_001757E0(p, 0x17, 0x17);
}
