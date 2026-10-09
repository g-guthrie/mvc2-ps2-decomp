typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef union { u32 bits; f32 value; } FloatBits;
extern int func_00175700(u8 *);
void func_00301ED0(u8 *p)
{
    func_00175700(p);
    if (*(signed char *)(p + 0x151) != 0)
        return;
    p[0x151] = 0;
    p[7]++;
    ((FloatBits *)(p + 0x5C))->bits = 0xC0555555;
    ((FloatBits *)(p + 0x68))->bits = 0;
    ((FloatBits *)(p + 0x60))->bits = 0xC0092492;
    ((FloatBits *)(p + 0x6C))->bits = 0xBE892492;
    if (*(s16 *)(p + 0x140) != 0) {
        ((FloatBits *)(p + 0x5C))->value = -((FloatBits *)(p + 0x5C))->value;
        ((FloatBits *)(p + 0x68))->value = -((FloatBits *)(p + 0x68))->value;
    }
}
