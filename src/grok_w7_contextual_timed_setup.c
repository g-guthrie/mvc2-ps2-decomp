typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef float f32;
typedef union FloatPairBits {
    f32 values[2];
    u32 bits[2];
} FloatPairBits;

extern int func_00175700(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_001830D0(u8 *, f32 *, int);
extern void func_00307AD0(u8 *, void *);

void func_003079F0(u8 *p, void *context)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = p[0x269] == 6 ? 2 : 0;

    if ((s8)func_00175700(p) < 0) {
        struct {
            FloatPairBits position;
            u32 padding[2];
        } local;

        p[0x404] = 0;
        p[0x405] = 0;
        p[6]++;
        *(u16 *)(p + 0x1C) = 1;
        *(u16 *)(p + 0x1E) = 3;
        func_001E3210(p, 21);
        local.position.bits[0] = 0xC3555555;
        local.position.bits[1] = 0x437CDB6D;
        func_001830D0(p, local.position.values, 1);
        func_00307AD0(p, context);
    }
}
