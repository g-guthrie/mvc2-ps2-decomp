typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern void func_00175700(u8 *);
extern int func_001864A0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001E3A40(int);
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_0022BB10(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_001864A0(p)) {
        f32 f0 = 5.0f;
        f32 f1 = 0.104166664183139801025390625f;
        p[6]++;
        if (p[0x1E6]) {
            f0 = -f0;
            f1 = -f1;
        }
        *(f32 *)(p + 0x5C) = f0;
        *(f32 *)(p + 0x68) = f1;
        *(u32 *)(p + 0x60) = 0x41892492;
        *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
        func_001757E0(p, 0xF, 6);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001E3A40(*(int *)(p + 0x1DC));
    }
}
