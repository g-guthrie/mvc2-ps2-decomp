typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;

void func_00346C50(u8 *a, u8 *b) {
    extern void func_00346DC0(u8 *, u8 *);
    extern s32 func_00175700();
    extern void func_001E7F60();
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    s16 v;
    if (*(s16 *)(a + 0x1E) != *(u16 *)(b + 0x168) || b[0x1E4] != 0x15) {
        t = a[4];
        a[4] = t + 1;
        return;
    }
    *(s8 *)(a + 0x31) = -2;
    func_00346DC0(a, b);
    if (a[5] != 0) {
        if ((s8)func_00175700(a) < 0) {
            a[0x13C] = 0;
            t = a[4];
            a[4] = t + 1;
        }
        return;
    }
    if (*(s8 *)(a + 0x151) != 0) {
        a[0x151] = 0;
        a[0x1B5] = 0x2B;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(s32 *)(a + 0x1D8) = 0;
        D_004C2794->f7c[a[2]]++;
    }
    if (*(s8 *)(a + 0x1B3) == 0) {
        func_00175700(a);
        v = *(s16 *)(a + 0x1C);
        *(s16 *)(a + 0x1C) = v - 1;
        if (v != 0) {
            func_001E7F60(a);
            return;
        }
        *(s16 *)(a + 0x1C) = 1;
        if (*(s8 *)(a + 0x151) == 0) return;
    }
    t = a[5];
    a[5] = t + 1;
    func_001757E0(a, 0x14, 2);
}
