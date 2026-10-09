typedef unsigned char u8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00183D50(u8 *);

void func_00302890(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))
        return;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[5]++;
    func_00183D50(p);
}
