typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern int func_00175700(u8 *);
extern void func_001E3210(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_002FEC20(u8 *p, u8 *q)
{
    s16 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s16 *)(p + 0x1C) == 0x32)
        func_001E3210(p, 0x1F);
    if (*(f32 *)(p + 0x430) + 411.428558f <= *(f32 *)(p + 0x38)
        && (*(u16 *)(p + 0x35E) & 0x1000)
        && (*(u16 *)(p + 0x362) & 0x360))
        *(s16 *)(p + 0x1C) = 0;
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        p[6]++;
        q[7] = 1;
        func_001757E0(p, 0x16, 1);
        p[0x1B5] = 0x34;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        *(u32 *)(p + 0x5C) = 0xC1555555;
        *(u32 *)(p + 0x60) = 0xC1CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        if (*(s16 *)(p + 0x140))
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_001E3210(p, 0x2B);
        func_001E3210(p, 4);
    }
}
