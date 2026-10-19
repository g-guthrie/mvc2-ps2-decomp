typedef unsigned char u8;
typedef float f32;

extern f32 func_001AC390(u8 *, int);
extern void func_001AB6E0(u8 *, u8 *);
extern void func_001AB840(u8 *, u8 *);

void func_001AB630(u8 *p, u8 *q)
{
    f32 x = *(f32 *)(p + 0x34) - func_001AC390(q, 0x38);
    if (x < -13.333333015441895f || 13.333333015441895f < x) {
        p[7] = 1;
        func_001AB6E0(p, q);
        return;
    }
    p[7] = 3;
    func_001AB840(p, q);
}
