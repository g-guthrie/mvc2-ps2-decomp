typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_00183D90(u8 *);
extern void func_001843A0(u8 *);

void func_0024EDA0(u8 *p)
{
    if (p[6] == 0) {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) == 0)
            return;
        p[6]++;
        {
            u32 bits;
            f32 f;
            if (p[0x1E6] != 0)
                bits = 0x4162AAAA;
            else
                bits = 0xC162AAAA;
            f = *(f32 *)&bits;
            *(f32 *)(p + 0x5C) = f;
            if (p[0x1E6] != 0)
                bits = 0xBF3AAAAA;
            else
                bits = 0x3F3AAAAA;
            f = *(f32 *)&bits;
            *(f32 *)(p + 0x68) = f;
        }
        return;
    }
    func_00183D90(p);
    if (*(s8 *)(p + 0x151) != 0)
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (func_00175700(p) < 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}
