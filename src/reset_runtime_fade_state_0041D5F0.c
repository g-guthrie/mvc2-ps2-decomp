typedef unsigned char u8;
typedef unsigned int u32;
typedef union {float value;u32 bits;} FloatBits;

extern u8 *D_006338CC;
extern void func_0041D6C0(void);

void func_0041D5F0(u8 *state)
{
    /* IEEE-754 binary32 encoding of 0.8, written into float state fields. */
    u32 scaleBits = 0x3F4CCCCD;

    state[5] = 0;
    state[0x13C] = 0;
    ((FloatBits *)(D_006338CC + 0x80))->bits = scaleBits;
    ((FloatBits *)(D_006338CC + 0x7C))->bits = scaleBits;
    ((FloatBits *)(D_006338CC + 0x78))->bits = scaleBits;
    *(void (**)(void))(state + 0x10) = func_0041D6C0;
}
