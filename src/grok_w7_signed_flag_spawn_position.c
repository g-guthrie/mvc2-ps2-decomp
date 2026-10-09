typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, f32 *, int);

void func_002B5BB0(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = p[0x269] == 6 ? 2 : 0;
    func_00175700(p);
    if ((s8)p[0x151] < 0) {
        struct { union { f32 values[3]; u32 bits[3]; } position; u32 padding; } offset;
        p[0x404] = 0;
        p[0x405] = 0;
        p[6]++;
        p[0x151] = 0;
        offset.position.bits[0] = 0xC1D55555;
        offset.position.bits[1] = 0x42CDB6DB;
        offset.position.bits[2] = 0;
        func_001830D0(p, offset.position.values, 1);
    }
}

void func_002B6920(u8 *p)
{
    struct { union { f32 values[3]; u32 bits[3]; } position; u32 padding; } offset;

    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = p[0x269] == 6 ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[6]++;
        p[0x151] = 0;
        offset.position.bits[0] = 0xC1D55555;
        offset.position.bits[1] = 0x433A6DB6;
        offset.position.bits[2] = 0;
        func_001830D0(p, offset.position.values, 1);
    }
}
