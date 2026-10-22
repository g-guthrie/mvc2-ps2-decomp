typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2d7;
extern G2d7 *D_004C2794;
extern u8 D_004D18EC[], D_004F1F45[], D_004F1F46[];

void func_002D72A0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002D7260(u8 *);
    u8 sw = p[7];
    switch (sw) {
    case 0:
        p[7] = sw + 1;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x5C) = 0xC0555555;
        if (*(s16 *)(p + 0x140) != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_001757E0(p, 0, 2);
        break;
    case 1:
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        func_00175700(p);
        if (D_004D18EC[0] != 0) {
            p[0x1B5] = 4;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            {
                u32 t = p[7];
                p[7] = t + 1;
            }
            func_001757E0(p, 8, 1);
        }
        break;
    case 2:
        if ((s8)func_00175700(p) < 0) {
            u32 t = p[7];
            p[7] = t + 1;
            func_001757E0(p, 0x13, 1);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            D_004F1F45[0] = 1;
            D_004F1F46[0] = 1;
        }
        break;
    case 3:
        func_00175700(p);
        break;
    default:
        break;
    }
    func_002D7260(p);
}
