typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00183920(u8 *, f32 *);
extern void func_003BA230(u8 *, int, int);
extern void func_001E3710(u8 *, int);
void func_0030B7B0(u8 *p)
{
    struct { union { f32 values[2]; u32 bits[2]; } pair; u32 padding[2]; } position __attribute__((aligned(16)));
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        position.pair.bits[0] = 0x43055555;
        position.pair.bits[1] = 0x42AB6DB6;
        func_00183920(p, position.pair.values);
    }
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        func_003BA230(p, 7, 1);
        func_001E3710(p, 22);
    }
}
