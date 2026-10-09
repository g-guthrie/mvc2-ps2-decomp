typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
typedef union FloatPairBits {
    f32 values[2];
    u32 bits[2];
} FloatPairBits;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00183920(u8 *, f32 *);

void func_00307540(u8 *p, u8 *context)
{
    struct {
        FloatPairBits position;
        u32 padding[2];
    } local;

    context[0x10] = 8;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }

    if (p[0x15B] != 0) {
        p[0x15B] = 0;
        local.position.bits[0] = 0xC2A00000;
        local.position.bits[1] = 0x43092492;
        func_00183920(p, local.position.values);
    }
}
