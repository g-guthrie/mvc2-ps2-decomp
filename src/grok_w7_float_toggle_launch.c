typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef float f32;
typedef union FloatPairBits {
    f32 values[2];
    u32 bits[2];
} FloatPairBits;

extern void func_001266A0(u8 *, int, int);
extern void func_0015D010(u8 *, f32 *);
extern void func_0018C6E0(void *);
extern int func_001757E0(u8 *, int, int);
extern u8 *func_001DA7F0(u8 *, int);
extern void func_00185960(u8 *, u8 *);
extern void func_001843A0(u8 *);

void func_003083A0(u8 *p)
{
    struct {
        FloatPairBits position;
        u32 padding[2];
    } local;
    u8 *context = p + 0x2B8;
    u8 *result;

    if ((*(u16 *)(p + 0x20E) & 0x0400) != 0) {
        *(s8 *)(p + 0x1E6) ^= 1;
        *(s16 *)(p + 0x140) ^= 1;
    }

    p[0x1B4] = 10;
    p[7] = 0;
    p[6] = 0;
    *(f32 *)(p + 0x5C) = 0.0f;
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    func_001266A0(p, 5, 5);

    local.position.bits[0] = 0xC2F00000;
    local.position.bits[1] = 0x42CDB6DB;
    func_0015D010(p, local.position.values);
    context[4] = 0;
    func_0018C6E0(p);
    func_001757E0(p, 21, 0);
    p[0x1B7] = 1;
    result = func_001DA7F0(p, 1);
    if (result != 0)
        func_00185960(p, result);
    else
        func_001843A0(p);
}
