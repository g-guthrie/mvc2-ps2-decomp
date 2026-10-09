typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
typedef union FloatPairBits {
    f32 values[2];
    u32 bits[2];
} FloatPairBits;

extern int func_00175700(u8 *);
extern void *func_001DD470(u8 *, int);
extern void func_0030F650(u8 *);
extern void func_001548D0(u8 *, f32 *, int);
extern void func_001E3710(u8 *, int);
extern void func_00126400(void);

void func_0030F560(u8 *p)
{
    u8 *target;

    if (p[6] == 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x60) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x6C) = 0.0f;
    }

    if ((s8)func_00175700(p) < 0) {
        func_001DD470(p, 0);
        func_0030F650(p);
        return;
    }

    if (*(s8 *)(p + 0x151) == 0)
        return;
    *(s8 *)(p + 0x151) = 0;
    target = *(u8 **)(p + 0x1DC);

    {
        struct {
            FloatPairBits position;
            u32 padding[2];
        } local;

        *(u8 **)(target + 0x1C8) = p;
        target[0x20A] = 1;
        target[0x1E6] = p[0x1E6] ^ 1;
        target[0x1B5] = 33;
        target[0x20D] = 2;
        local.position.bits[0] = 0xC3055555;
        local.position.bits[1] = 0x43809249;
        func_001548D0(p, local.position.values, 2);
    }

    func_001E3710(p, 3);
    func_00126400();
}
