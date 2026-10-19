typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern int func_0018AB10(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002BE060(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_0018AB10(p))
        p[0x152] = 1;
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) <= 4.285714149475098f) {
        p[6]++;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *(u32 *)(p + 0x6C) = 0xBD892492;
        *(s16 *)(p + 0x1C) = 0;
        p[0x1B5] = 0x64;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        *(u16 *)(p + 0x1C0) = 0;
        func_001757E0(p, 22, 0x10);
        return;
    }
    if (p[0x15B]) {
        p[0x15B] = 0;
        p[0x1B5] = 0x63;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        *(u16 *)(p + 0x1C0) = 0x10;
    }
}
