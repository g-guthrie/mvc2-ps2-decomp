typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;
extern void func_001757E0();
extern void func_003C76C0();

void func_003C7570(u8 *a, s32 b) {
    u8 *t;
    if ((t = *(u8 **)(a + 0x14))[5] != 2) {
        f32 v;
        a[5] = 2;
        func_001757E0(a, 0x14, 9);
        v = 3.3333332538604736f;
        *(f32 *)(a + 0x60) = 60.0f;
        *(f32 *)(a + 0x6C) = 0.0f;
        if (*(s16 *)(a + 0x140) != 0) v = -v;
        *(f32 *)(a + 0x5C) = v;
        func_003C76C0(a, b);
    } else {
        if (t[0x20A] != 0 && !(*(f32 *)(t + 0x38) < 274.28570556640625f)) {
            f32 v;
            a[5] = 3;
            *(f32 *)(a + 0x34) = *(f32 *)(t + 0x34);
            a[0x1B0] = 0x44;
            a[0x1B1] = 0;
            a[0x1B5] = 0x26;
            a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
            *(u32 *)(a + 0x1D8) = 0;
            D_004C2794->f7c[a[2]]++;
            *(s16 *)(a + 0x1C) = 2;
            *(f32 *)(a + 0x60) = 25.714284896850586f;
            v = -0.0520833320915699f;
            if (*(s16 *)(a + 0x140) != 0) v = -v;
            *(f32 *)(a + 0x5C) = v;
            func_001757E0(a, 0x14, 0x1A);
        }
    }
}
