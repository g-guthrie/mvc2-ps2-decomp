typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
typedef union { u32 bits; f32 value; } FloatBits;

extern void func_00175C00(u8 *, int);
extern void func_00184540(u8 *);
extern void func_001E3240(u8 *, int);

void func_00307760(u8 *p, void *context)
{
    u8 *q = context;

    p[0x215] = 0;
    *(f32 *)(p + 0x5C) = 0.0f;
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    ((FloatBits *)(p + 0x6C))->bits = 0xBF4DB6DB;

    if (q[8] != 0) {
        q[8] = 0;
        func_00175C00(p, 0);
    }
    func_00184540(p);
    func_001E3240(p, 48);
}
