/* sLa2_b: MW 3.0.3 (./try.sh src/sLa2_b.c "-O3 -Op -sdatathreshold 0").
 * func_003BE900: opt_lifetimes off + opt_propagation off, parameter copy q, named float k,
 * declaration order searched; k *= f and a-first negation give retail f-register order. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef float f32;
typedef int s32;


#pragma push
#pragma opt_lifetimes off
#pragma opt_propagation off
s32 func_003BE900(u8 *p)
{
    extern u32 func_00174170(u8 *);
    extern void func_001DC0F0(u8 *, int, f32, f32);
    extern int func_00175700(u8 *);
    extern s32 func_001E7F60(u8 *);
    f32 x;
    u8 *q;
    f32 b;
    f32 a;
    f32 k;
    f32 f;
    u32 t;
    q = p;
    f = (f32)((func_00174170(q) & 0x3E) - 0x20);
    k = 1.6666666269302368f;
    k *= f;
    x = *(f32 *)(q + 0x34);
    func_001DC0F0(q, 0x100, x + k, *(f32 *)(q + 0x38));
    if ((s8)func_00175700(q) < 0) {
        t = q[5];
        q[5] = t + 1;
        *(s16 *)(q + 0x1C) = 20;
        a = -7.5f;
        b = -0.2083333283662796f;
        if (*(s16 *)(q + 0x140) != 0) { a = -a; b = -b; }
        *(f32 *)(q + 0x5C) = a;
        *(f32 *)(q + 0x68) = b;
    } else if (*(s8 *)(q + 0x151) != 0) {
        q[0x151] = 0;
        q[0x1B2] = 0;
    }
    return func_001E7F60(q);
}
#pragma pop
