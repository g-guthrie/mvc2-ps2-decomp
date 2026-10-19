typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
#define F(p,n) (*(f32 *)((p)+(n)))
void func_00201150(u8 *p)
{
    f32 old = F(p,0x5C);
    u8 *q = p + 0x2B8;
    F(p,0x34) += old;
    F(p,0x5C) += F(p,0x68);
    F(p,0x38) += F(p,0x60);
    F(p,0x60) += F(p,0x6C);
    if ((F(p,0x5C) < 0.0f && old > 0.0f) ||
        (F(p,0x5C) > 0.0f && old < 0.0f)) {
        F(p,0x5C) = 0;
        F(p,0x68) = 0;
    }
    if (func_00175700(p) < 0) {
        q[12] = 0;
        func_001843A0(p);
    }
}

void func_00201CC0(u8 *p)
{
    f32 old = F(p,0x5C);
    u8 *q = p + 0x2B8;
    F(p,0x34) += old;
    F(p,0x5C) += F(p,0x68);
    F(p,0x38) += F(p,0x60);
    F(p,0x60) += F(p,0x6C);
    if ((F(p,0x5C) < 0.0f && old > 0.0f) ||
        (F(p,0x5C) > 0.0f && old < 0.0f)) {
        F(p,0x5C) = 0;
        F(p,0x68) = 0;
    }
    if (func_00175700(p) < 0) {
        q[12] = 0;
        func_001843A0(p);
    }
}

extern void (*jtbl_004501A0[])(u8 *);
extern void (*jtbl_004501D0[])(u8 *);
void func_00201110(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    jtbl_004501A0[p[7]](p);
}
void func_00201C80(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    jtbl_004501D0[p[7]](p);
}
