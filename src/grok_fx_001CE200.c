typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern void func_00175700(u8 *);

void func_001CE200(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(*(u8 **)(p + 0x18) + 0x430) <= *(f32 *)(p + 0x38))) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        *(s16 *)(p + 0x1C) = 0x3C;
        *(f32 *)(p + 0x60) = -*(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) = *(f32 *)(p + 0x60) / 2.0f;
    }
    func_00175700(p);
}
