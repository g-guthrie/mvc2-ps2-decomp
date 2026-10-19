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
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_001863F0(p);
    } else {
        *(s16 *)(p + 0x1C) = 0x20;
        p[7]++;
        func_0022FFB0(p, q);
        func_00231D70(p, q);
    }
}
