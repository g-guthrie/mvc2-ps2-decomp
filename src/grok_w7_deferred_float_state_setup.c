typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001830D0(u8 *, f32 *, int);
extern u8 *func_003B8080(u8 *);
void func_0030AE90(u8 *p)
{
    struct { union { f32 values[3]; u32 bits[3]; } vector; u32 padding; } position __attribute__((aligned(16)));
    int mode;
    u8 *result;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (p[0x269] == 6)
        mode = 2;
    else
        mode = 0;
    p[0x405] = mode;
    p[0x33C] = 5;
    if ((s8)p[0x151] != 0) {
        p[6]++;
        p[0x151] = 0;
        result = func_003B8080(p);
        if (result == 0) {
            func_001843A0(p);
            return;
        }
        position.vector.bits[0] = 0xC13AAAAA;
        position.vector.bits[1] = 0x43452492;
        position.vector.bits[2] = 0;
        func_001830D0(p, position.vector.values, 1);
    } else {
        func_00175700(p);
    }
}
