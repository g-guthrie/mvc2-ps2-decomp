typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

void residual_002EED90(u8 *p)
{
    extern void func_001861B0(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002F1D90(u8 *);
    extern void func_00183D90(u8 *);
    extern void func_001863F0(u8 *);
    extern s32 func_00175700(u8 *);
    extern void func_002F1DF0(u8 *);
    u32 t = p[6];
    if (t == 0) {
        u8 c;
        p[6] = t + 1;
        func_001861B0(p);
        func_0018C4B0(p, 5);
        p[0x20D] = 1;
        c = 0x3D;
        if (*(s32 *)(p + 0x2D4) == 3)
            c = 0x5D;
        p[0x1B5] = c;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 0x14, 8);
        func_002F1D90(p);
    }
    if (p[0x213] == 3)
        func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0)
        func_002F1DF0(p);
}
