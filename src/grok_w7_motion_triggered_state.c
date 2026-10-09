typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_001864A0(u8 *);
extern void func_00183D50(u8 *);

void func_002F1600(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);

    if (func_001864A0(p) != 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 40;
        func_00183D50(p);
        func_001757E0(p, 21, 39);
    }
}
