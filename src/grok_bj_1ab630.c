typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern f32 func_001AC390(u8 *, s32);
extern void func_001AB6E0(u8 *, u8 *);
extern void func_001AB840(u8 *, u8 *);

void residual_001AB630(u8 *p, u8 *q)
{
    f32 d = *(f32 *)(p + 0x34) - func_001AC390(q, 0x38);
    if (d < -13.333333015441895f) {
        p[7] = 1;
        func_001AB6E0(p, q);
        return;
    }
    if (13.333333015441895f < d) {
        p[7] = 1;
        func_001AB6E0(p, q);
        return;
    }
    p[7] = 3;
    func_001AB840(p, q);
}
