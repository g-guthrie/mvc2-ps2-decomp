typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00235400(u8 *p) {
    extern void func_00175700();
    s8 t;
    f32 c;
    p[0x209] = 2;
    func_00175700(p);
    t = *(s8 *)(p + 0x151);
    if (t & 1) {
        p[0x151] = t ^ 1;
        c = -53.33333206176758f;
        if (p[0x1E6] != 0) c = -c;
        *(f32 *)(p + 0x34) += c;
    }
    if (*(s8 *)(p + 0x151) & 2) {
        u32 u = p[7];
        p[7] = u + 1;
        p[0x20D] = 2;
        *(u32 *)(p + 0x5C) = 0xC1855555;
        *(u32 *)(p + 0x68) = 0x3F055555;
        *(u32 *)(p + 0x60) = 0x40AB6DB6;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}
