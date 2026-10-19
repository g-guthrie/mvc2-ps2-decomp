typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001863F0(u8 *);
extern void func_0022FFB0(u8 *, u8 *);
extern void func_00231D70(u8 *, u8 *);

void func_00232020(u8 *p, u8 *q)
{
    u8 *t = p;
    p = q;
    q = t;
    func_00175700(q);
    if (*(s8 *)(q + 0x151) == 0) {
        *(f32 *)(q + 0x34) += *(f32 *)(q + 0x5C);
        *(f32 *)(q + 0x5C) += *(f32 *)(q + 0x68);
        *(f32 *)(q + 0x38) += *(f32 *)(q + 0x60);
        *(f32 *)(q + 0x60) += *(f32 *)(q + 0x6C);
        func_001863F0(q);
    } else {
        *(s16 *)(q + 0x1C) = 0x20;
        q[7]++;
        func_0022FFB0(q, p);
        func_00231D70(q, p);
    }
}
