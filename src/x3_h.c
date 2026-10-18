typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0022E360(u8 *p) {
    extern void func_00175700();
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(u32 *)(p + 0x60) = 0x411A4924;
        *(u32 *)(p + 0x6C) = 0xC0092492;
        if (p[0x1E6] != 0) {
            *(u32 *)(p + 0x5C) = 0xC1555555;
            *(u32 *)(p + 0x68) = 0x3F555555;
        } else {
            *(u32 *)(p + 0x5C) = 0x41555555;
            *(u32 *)(p + 0x68) = 0xBF555555;
        }
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}
