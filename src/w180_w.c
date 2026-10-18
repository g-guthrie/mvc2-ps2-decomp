typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00156100(u8 *p) {
    f32 f;
    f32 z;
    u32 c;
    extern void func_00156480();
    extern void func_0016CE60();
    extern void func_00155540(s32);
    extern void func_001E3520(u8 *, s32);
    func_00156480(p);
    *(s32 *)(p + 0x40) = *(s32 *)(p + 0x40) + (*(volatile s32 *)(p + 0x5C));
    *(s32 *)(p + 0x44) = *(s32 *)(p + 0x44) + (*(volatile s32 *)(p + 0x5C));
    *(s32 *)(p + 0x48) = *(s32 *)(p + 0x48) + (*(volatile s32 *)(p + 0x5C));
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (p[5] == 0) {
        if (100.0f == (f32)*(s16 *)(p + 0x1C)) {
            p[5] = 1;
        }
    }
    if (p[6] == 0) {
        if (160.0f == (f32)*(s16 *)(p + 0x1C)) {
            p[6] = 1;
        }
    }
    if (p[5] != 0) {
        *(f32 *)(p + 0x50) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x54) += *(f32 *)(p + 0x6C);
        *(f32 *)(p + 0x58) += *(f32 *)(p + 0x70);
    }
    if (p[6] != 0) {
        z = 0.0f;
        f = *(f32 *)(p + 0x78) - 0.05000000074505806f;
        *(f32 *)(p + 0x78) = f;
        if (f <= z) {
            c = p[4];
            p[4] = c + 1;
            p[0x13C] = 0;
            if (p[0x21] == 0) {
                func_0016CE60();
                func_00155540(*(s32 *)(p + 0x18));
                func_001E3520(p, 0x11);
            }
        }
    }
}
