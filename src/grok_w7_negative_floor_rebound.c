typedef unsigned char u8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00183D50(u8 *);
extern void func_001E3710(u8 *, int);

void func_002E5660(u8 *p)
{
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430) + (-120.0f)) {
        p[6]++;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(f32 *)(p + 0x60) = -(*(f32 *)(p + 0x60) / 8.0f);
        func_00175700(p);
        func_00183D50(p);
        func_001E3710(p, 48);
    }
}
