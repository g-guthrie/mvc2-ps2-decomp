typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
typedef union { u32 bits; f32 value; } FloatBits;
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_003B38F0(u8 *, u8, u8);
void func_00301AC0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if ((*(s8 *)(p + 0x151) & 2) != 0) {
        *(s8 *)(p + 0x151) &= ~2;
        func_003B38F0(p, 1, 1);
    }
    if ((*(s8 *)(p + 0x151) & 1) != 0) {
        *(s8 *)(p + 0x151) &= ~1;
        ((FloatBits *)(p + 0x5C))->bits = 0xC0D55555;
        ((FloatBits *)(p + 0x68))->bits = 0x3ED55555;
        if (p[0x1E6] != 0) {
            ((FloatBits *)(p + 0x5C))->value = -((FloatBits *)(p + 0x5C))->value;
            ((FloatBits *)(p + 0x68))->value = -((FloatBits *)(p + 0x68))->value;
        }
    }
}

extern void func_003A6DC0(u8 *, u8, u8);
void func_002EA440(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if ((*(s8 *)(p + 0x151) & 2) != 0) {
        *(s8 *)(p + 0x151) &= ~2;
        func_003A6DC0(p, 1, 1);
    }
    if ((*(s8 *)(p + 0x151) & 1) != 0) {
        *(s8 *)(p + 0x151) &= ~1;
        ((FloatBits *)(p + 0x5C))->bits = 0xC0D55555;
        ((FloatBits *)(p + 0x68))->bits = 0x3ED55555;
        if (p[0x1E6] != 0) {
            ((FloatBits *)(p + 0x5C))->value = -((FloatBits *)(p + 0x5C))->value;
            ((FloatBits *)(p + 0x68))->value = -((FloatBits *)(p + 0x68))->value;
        }
    }
}
