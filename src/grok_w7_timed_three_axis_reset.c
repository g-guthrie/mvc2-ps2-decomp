typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
extern int func_00175700(u8 *);
extern void func_003092C0(u8 *);
extern void func_001830D0(u8 *, f32 *, int);
void func_0030B500(u8 *p)
{
    struct { union { f32 values[3]; u32 bits[3]; } position; u32 padding; } position __attribute__((aligned(16)));
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = p[0x269] == 6 ? 2 : 0;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) == 0)
        goto no_flag;
    p[6]++;
    p[0x151] = 0;
    func_003092C0(p);
    position.position.bits[0] = 0xC13AAAAA;
    position.position.bits[1] = 0x43452492;
    position.position.bits[2] = 0;
    func_001830D0(p, position.position.values, 1);
    return;
no_flag:
    func_00175700(p);
}
