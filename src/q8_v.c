typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002CE990(u8 *p) {
    extern s32 func_00175700();
    f32 v;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        if (p[0x1B7] != 0) {
            if (p[0x1E6] != 0) {
                v = 15.833333015441895f;
            } else {
                v = -15.833333015441895f;
            }
            *(f32 *)(p + 0x5C) = v;
            if (p[0x1E6] != 0) {
                v = -0.390625f;
            } else {
                v = 0.390625f;
            }
            *(f32 *)(p + 0x68) = v;
        } else {
            if (p[0x1E6] != 0) {
                v = 15.833333015441895f;
            } else {
                v = -15.833333015441895f;
            }
            *(f32 *)(p + 0x5C) = v;
            if (p[0x1E6] != 0) {
                v = -0.5208333134651184f;
            } else {
                v = 0.5208333134651184f;
            }
            *(f32 *)(p + 0x68) = v;
        }
    }
}
