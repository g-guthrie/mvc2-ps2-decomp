typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_0024FD00(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_00183d50(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) { p[0x20D] = 2; *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C); *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68); *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60); *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C); } else {}
    if (*(s8 *)(p + 0x151) != 0 || !(*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430))) return; { u32 t = p[6]; p[6] = t + 1; *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430); p[0x20D] = 0; func_00183d50(p); func_001757E0(p, 0x15, 3); }
}
