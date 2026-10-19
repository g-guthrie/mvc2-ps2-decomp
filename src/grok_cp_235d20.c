typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern u8 *D_004C2794;

void residual_00235D20(u8 *p)
{
    volatile s32 a2;
    s32 a3;

    p[6]++;
    if (p[0x20D] != 2) {
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x210] = 0;
        func_00185490(p);
        func_00183D10(p);
        a2 = 0x36;
        a3 = 7;
    } else {
        *(s8 *)(p + 0x1E8) = (s8)(*(s8 *)(p + 0x1E8) + 1);
        *(u32 *)(p + 0x5C) = 0x3FD55555;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
        *(s16 *)(p + 0x140) = p[0x1E6];
        a2 = 57;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
            a2 = 0x36 + 3;
        }
        a3 = 9;
    }
    p[0x1B5] = (u8)(a2 + (s8)p[0x1B7]);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_001757E0(p, 0x15, (a3 + p[0x1B7]) & 0xFF);
}
