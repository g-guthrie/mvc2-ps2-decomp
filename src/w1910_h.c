typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_002C3A00(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00183D50(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        t = p[6];
        p[6] = t + 1;
        func_00183D50(p);
        *(u32 *)(p + 0x5C) = 0x40555555;
        if (p[0x1E6] == 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        func_001266A0(p, 5, 5);
        func_001757E0(p, 0xF, 8);
    }
}
