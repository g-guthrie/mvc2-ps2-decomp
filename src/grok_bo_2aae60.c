typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_002AAE60(u8 *p)
{
    func_00175C00(p, 0);
    p[6]++;
    p[0x20D] = 2;
    *(f32 *)(p + 0x38) += 102.85713958740234f;
    *(u32 *)(p + 0x5C) = 0x41D55555;
    if (p[0x1E6] == 0)
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    p[0x1B5] = 65;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 3);
}
