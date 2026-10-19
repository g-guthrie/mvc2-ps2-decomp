typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_004000D0(s32 a0) { return a0 + 0x58; }

s32 func_001044C8(s32 descriptor) { return -1; }

s32 func_001044D0(void) { return -1; }

u8 *func_0034B5A0(u8 *a, s32 b) {
    extern u8 *func_003DA750();
    extern void func_0034B670();
    u8 *o;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(void **)(o + 0x10) = func_0034B670;
        *(u8 **)(o + 0x18) = a;
        o[0x20] = b;
        *(s16 *)(o + 0x26) = 0x401;
        if (b == 0) {
            *(u32 *)(o + 0x34) = 0x43200000;
            *(u32 *)(o + 0x38) = 0x431A4924;
        } else {
            *(u32 *)(o + 0x34) = 0x43200000;
            *(u32 *)(o + 0x38) = 0x434DB6DB;
        }
        if (*(s16 *)(a + 0x140) == 0) *(f32 *)(o + 0x34) = -*(f32 *)(o + 0x34);
        *(f32 *)(o + 0x34) += *(f32 *)(a + 0x34);
        *(f32 *)(o + 0x38) += *(f32 *)(a + 0x38);
    }
    return o;
}

void func_0039F650(u8 *a) {
    extern s8 func_00175700();
    extern void func_001E7F60();
    if (a[1] != (*(u8 **)(a + 0x18))[1]) {
        a[4]++;
        a[0x13C] = 0;
    } else if (a[6] == 0) {
        s16 v = *(s16 *)(a + 0x1C) - 1;
        *(s16 *)(a + 0x1C) = v;
        if (v == 0) {
            u32 t = a[6];
            a[6] = t + 1;
            *(s16 *)(a + 0x1C) = 0x1C;
        }
    } else {
        a[0x13C] = 1;
        if (*(s8 *)(a + 0x1B3) != 0 || func_00175700() < 0) {
            a[4]++;
            a[0x13C] = 0;
        } else {
            func_001E7F60(a);
        }
    }
}
