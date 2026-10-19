typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);

void func_00235400(u8 *p)
{
    f32 v;
    p[0x209] = 2;
    func_00175700(p);
    if ((s8)p[0x151] & 1) {
        p[0x151] = (s8)p[0x151] ^ 1;
        v = -53.3333321f;
        if (p[0x1E6] != 0)
            v = -v;
        *(f32 *)(p + 0x34) += v;
    }
    if ((s8)p[0x151] & 2) {
        u32 t = p[7];
        p[7] = t + 1;
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
