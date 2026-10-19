typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00314760(u8 *, u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001DD8A0(u8 *, int, int);

void func_003145A0(u8 *p, u8 *q)
{
    f32 *vx;
    f32 *ax;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    vx = (f32 *)(p + 0x5C);
    ax = (f32 *)(p + 0x68);
    func_00314760(p, q);
    if ((s16)(*(s16 *)(p + 0x1C))-- == 0) {
        u8 *o;
        p[7]++;
        o = *(u8 **)(p + 0x1DC);
        *(u8 **)(o + 0x1C8) = p;
        o[0x1B5] = 0x24;
        p[0x1B5] = 0x24;
        o[0x20A] = 0xF;
        o[6] = 0;
        p[0x219] = (q[0x15] / 4) + 32;
        func_001757E0(p, 0x16, 0x1E);
        func_001DD8A0(p, 1, 0);
        q[0x13] = 1;
        *vx = 0;
        *(f32 *)(p + 0x60) = 0;
        *ax = 0;
        *(f32 *)(p + 0x6C) = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}
