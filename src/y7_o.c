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

void func_002DE680(u8 *a) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    f32 z = 0.0f;
    f32 *v1, *a3, *t0, *t1;
    a[0x206] = 3;
    a[0x1FE] = 1;
    func_00175700(a);
    v1 = (f32 *)(a + 0x5C);
    t0 = (f32 *)(a + 0x68);
    a3 = (f32 *)(a + 0x60);
    t1 = (f32 *)(a + 0x6C);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (*(f32 *)(a + 0x60) < z && *(f32 *)(a + 0x38) < *(f32 *)(a + 0x430)) {
        u32 t = a[7];
        a[7] = t + 1;
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        a[0x20D] = 0;
        *v1 = z;
        *a3 = z;
        *t0 = z;
        *t1 = z;
        func_001757E0(a, 0xF, 6);
        func_00183d50(a);
    }
}

extern u8 *D_004C2714;

void func_001CE8F0(u8 *a) {
    extern s8 func_00175670();
    extern f32 func_00417440();
    a[0x13C] = 1;
    if (a[5] == 0) {
        if (func_00175670(a) < 0) {
            u32 t = a[5];
            a[5] = t + 1;
            D_004C2714[0xF] = 1;
            *(s16 *)(a + 0x1E) = 1;
            *(s16 *)(a + 0x1C) = 1;
            a[0x22] = 0;
        } else if (*(s8 *)(a + 0x151) == 0) {
            return;
        }
    } else {
        s16 v;
        func_00175670(a);
        *(f32 *)(a + 0x38) += 4.285714149475098f * func_00417440(((0x28 - a[0x22]) & 0x1F) << 11);
        v = *(s16 *)(a + 0x1C) - 1;
        *(s16 *)(a + 0x1C) = v;
        if (v == 0) {
            u32 t = a[0x22];
            a[0x22] = t + 1;
            *(s16 *)(a + 0x1C) = *(s16 *)(a + 0x1E);
        }
    }
}
