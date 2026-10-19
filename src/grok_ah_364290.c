typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DA750(u8 *, s32, s32);
extern void func_00363CB0(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_00364350(u8 *, u8 *);

void residual_00364290(u8 *p, u8 *q)
{
    s32 i;
    u8 *o;
    p[6]++;
    p[0x13C] = 1;
    *(s16 *)(p + 0x1E) = 10;
    *(f32 *)(p + 0x50) = 0.1f;
    *(f32 *)(p + 0x54) = 0.1f;
    for (i = 0; i < 4; i++) {
        o = func_003DA750(p, 1, 2);
        if (o) {
            *(void **)(o + 0x10) = func_00363CB0;
            *(u8 **)(o + 0x18) = q;
            *(u8 **)(o + 0x14) = p;
            o[0x20] = 1;
            o[0x23] = (u8)i;
        }
    }
    func_001E3210(q, 0x2E);
    func_00364350(p, q);
}
