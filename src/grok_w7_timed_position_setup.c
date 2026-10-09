typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern int func_00175700(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_001830D0(u8 *, f32 *, int);
void func_0030E5A0(u8 *p)
{
    struct { union { f32 values[2]; u32 bits[2]; } pair; u32 padding[2]; } position __attribute__((aligned(16)));
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = p[0x269] == 6 ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0)
        return;
    p[0x404] = 0;
    p[0x405] = 0;
    p[6]++;
    p[0x151] = 0;
    *(s16 *)(p + 0x1C) = 185;
    *(s16 *)(p + 0x1E) = 0;
    func_001E3210(p, 23);
    position.pair.bits[0] = 0x42200000;
    position.pair.bits[1] = 0x43AB6DB6;
    func_001830D0(p, position.pair.values, 1);
}
