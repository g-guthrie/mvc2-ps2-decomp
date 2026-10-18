typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700();
extern void func_001757E0();
extern void func_003AF9F0();
extern void func_001E3210();
void func_002FA5F0(u8 *a, u8 *b) {
    s32 i;
    u32 t;
    if (func_00175700(a) < 0) {
        t = a[6];
        a[6] = t + 1;
        func_001757E0(a, 0x15, 0xB);
        return;
    }
    if (*(s8 *)(a + 0x151) != 0) {
        a[0x151] = 0;
        for (i = 0; i < 6; i++) {
            if (b[i] == 0) {
                b[i] = 1;
                func_003AF9F0(a, 0, (u8)i);
            }
        }
        func_001E3210(a, 0x22);
    }
}

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s8 D_004550D0[];
extern void func_00380FE0();
s32 func_0027C570(u8 *p) {
    s8 r;
    s16 v;
    r = 0;
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        do {
            r = D_004550D0[*(s16 *)(p + 0x1C) * 2];
            if (r == -1) break;
            func_00380FE0(p, 0, (u8)r);
            *(s16 *)(p + 0x1E) = D_004550D0[*(s16 *)(p + 0x1C) * 2 + 1];
            *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        } while (*(s16 *)(p + 0x1E) == 0);
    }
    return r;
}
