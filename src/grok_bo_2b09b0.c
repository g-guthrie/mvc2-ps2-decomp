typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00175700(u8 *);
extern f32 func_002ADC20(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002B09B0(u8 *p)
{
    func_00175700(p);
    if (p[0x15B] != 0) {
        p[0x1B5] = p[0x15B];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        p[0x15B] = 0;
    }
    if (func_002ADC20(p) < 0.0f) {
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
    }
    if (*(f32 *)(p + 0x60) < 0.0f) {
        p[6]++;
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        func_001757E0(p, 22, 7);
    }
}
