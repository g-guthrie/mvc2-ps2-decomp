typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0015F150(u8 *p) {
    extern void func_001E3CE0();
    extern void func_0015F240();
    s16 h = *(s16 *)(p + 0x1E);
    if (h != 0) {
        *(s16 *)(p + 0x1E) = h - 1;
    } else {
        if (p[0x23] == 0) {
            switch (p[0x20]) {
            case 0: func_001E3CE0(0x1D); break;
            case 1: func_001E3CE0(0x1C); break;
            case 2: func_001E3CE0(0x1B); break;
            case 3: func_001E3CE0(0x1E); break;
            case 4: func_001E3CE0(0x1A); break;
            case 5: func_001E3CE0(0x1D); break;
            }
        }
        p[0x13C] = 1;
        *(s16 *)(p + 0x1E) = 10;
        *(u32 *)(p + 0x50) = 0x3F800000;
        {
            u32 t = p[4];
            p[4] = t + 1;
        }
        func_0015F240(p);
    }
}
