typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;

void func_00219AD0(u8 *p)
{
    extern void func_00183D90(void);
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    s16 v;
    u32 t;
    if (p[0x1B7] != 0) {
        if ((*(u32 *)(D_004C2840 + 0x1C) & 1) != 0) {
            func_00183D90();
        }
    }
    p[0x206] = 3;
    p[0x209] = 2;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[7];
        p[7] = t + 1;
        p[0x209] = 0;
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x5C) / 8.0f;
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / 2.0f;
        func_001757E0(p, 0x15, 0x28);
        func_001E3210(p, 0x20);
    }
}
