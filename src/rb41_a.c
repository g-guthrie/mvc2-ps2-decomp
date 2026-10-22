typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001D2DD0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s16 h;
    f32 z;
    f32 *a, *b;

    switch (p[5]) {
    case 0:
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) {
            u32 t = p[5];
            p[5] = t + 1;
            *(f32 *)(p + 0x68) = -(*(f32 *)(p + 0x5C) / 4.0f);
            func_001757E0(p, 0x17, 0x1B);
        }
        break;
    case 1:
        z = 0.0f;
        a = (f32 *)(p + 0x5C);
        b = (f32 *)(p + 0x68);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
            u32 t = p[5];
            p[5] = t + 1;
            *a = z;
            *b = z;
        }
        break;
    case 2:
        if ((s8)func_00175700(p) < 0) {
            u32 t = p[5];
            p[5] = t + 1;
        }
        break;
    }
}
