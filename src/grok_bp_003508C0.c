typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern void func_003509A0(u8 *);
extern void func_001E7F60(u8 *);
extern void func_00350A60(u8 *);
extern void func_00175700(u8 *);

void residual_003508C0(u8 *p)
{
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x1B2)) {
        func_003509A0(p);
        func_001E7F60(p);
        return;
    }
    if (*(s8 *)(p + 0x1B3)) {
        func_00350A60(p);
        return;
    }
    {
        u8 *o = *(u8 **)(p + 0x18);
        if (*(f32 *)(p + 0x38) < *(f32 *)(o + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(o + 0x430);
            func_003509A0(p);
            func_001E7F60(p);
            return;
        }
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        *(u32 *)(p + 0x60) = 0xC0892492;
        *(u32 *)(p + 0x6C) = 0;
    }
    func_001E7F60(p);
}
