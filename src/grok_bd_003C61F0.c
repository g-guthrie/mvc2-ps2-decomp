typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern void func_003C64C0(u8 *);
extern int func_00175700(u8 *);
extern void func_001E3710(u8 *, int);
extern void func_001E7F60(u8 *);

void residual_003C61F0(u8 *p, u8 *q)
{
    if (*(s8 *)(p + 0x1B3)) {
        func_003C64C0(p);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(q + 0x430) > *(f32 *)(p + 0x38)) {
        p[5]++;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_00175700(p);
        func_001E3710(q, 0x34);
    }
    func_001E7F60(p);
}
