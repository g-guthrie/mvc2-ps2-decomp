typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern void func_00156480(u8 *);

void func_00156280(u8 *p)
{
    if (p[5] == 0) {
        s16 n = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = n;
        if (n <= 0) {
            p[5] = p[5] + 1;
            p[0x13C] = 1;
        }
    }
    if (p[5]) {
        func_00156480(p);
        *(f32 *)(p + 0x50) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x54) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x58) += *(f32 *)(p + 0x64);
        if (p[6] == 0) {
            s16 n = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = n;
            if (n <= 0)
                p[6] = 1;
        }
        if (p[6]) {
            *(f32 *)(p + 0x78) -= 0.1f;
            *(f32 *)(p + 0x7C) -= 0.1f;
            *(f32 *)(p + 0x80) -= 0.1f;
            if (*(f32 *)(p + 0x80) < 0.0f) {
                p[4] = p[4] + 1;
                p[0x13C] = 0;
            }
        }
    }
}
