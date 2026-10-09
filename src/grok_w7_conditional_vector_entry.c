typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, f32 *, int);
void func_0030AB60(u8 *p)
{
    struct { union { f32 values[3]; u32 bits[3]; } vector; u32 padding; } position __attribute__((aligned(16)));
    int mode;
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
        *(s16 *)(p + 0x1C) = 0x80;
        *(s16 *)(p + 0x1E) = 6;
        p[0x151] = 0;
        position.vector.bits[0] = 0xC13AAAAA;
        position.vector.bits[1] = 0x43452492;
        position.vector.bits[2] = 0;
        func_001830D0(p, position.vector.values, 1);
    } else {
        func_00175700(p);
    }
}
