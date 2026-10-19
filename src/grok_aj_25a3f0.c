typedef unsigned char u8;
typedef float f32;

extern void func_00255620(u8 *);
extern void func_00183D50(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00175700(u8 *);

void func_0025A3F0(u8 *p)
{
    func_00255620(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        p[0x20D] = 0;
        *(int *)(p + 0x5C) = 0;
        *(int *)(p + 0x60) = 0;
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
        func_001757E0(p, 0x16, 5);
    }
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
}
