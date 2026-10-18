typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p[0x151]; s8 b151; } PK_00238C30;
extern void (*D_0045DCE0[])(u8 *, u8 *);

void func_00238C30(u8 *a)
{
    extern s8 func_00175700(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_001843A0(u8 *);
    extern u32 func_00174170(void);
    extern void func_001A0B20(u8 *, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    s8 r;
    s8 v;
    u16 h;
    s32 s0;
    r = func_00175700(a);
    if (r < 0) {
        func_00175C00(a, 1);
        func_001843A0(a);
        return;
    }
    v = *(s8 *)(a + 0x151);
    if (v & 1) {
        ((PK_00238C30 *)a)->b151 = v ^ 1;
        h = *(u16 *)(a + 0x35E);
        s0 = -1;
        if (h & 0x800) s0 = 0;
        if (h & 0x400) s0 = 1;
        if (h & 0x1000) s0 = 2;
        if (s0 == -1) s0 = (func_00174170() & 0xF) % 3;
        a[0x20] = s0;
        func_001A0B20(a, 2);
        func_00176160(a, 1, (a[0x25] << 4) + 9 + s0, 1);
    }
}

void func_00321850(u8 *a)
{
    extern s8 func_00175700(u8 *);
    extern void func_001865B0(u8 *);
    extern s32 func_00182E20(u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *s0, *s1;
    s8 v;
    v = *(s8 *)(a + 0x151);
    s1 = *(u8 **)(a + 0x1DC);
    s0 = a + 0x2B8;
    if (v != 8 || *(s8 *)(a + 0x152) == 1) {
        if (*(s8 *)(s0 + 0xD) != 0) {
            a[0x151] = 8;
            a[0x152] = 4;
        }
    }
    s0[0xD] = 0;
    if (func_00175700(a) < 0 && *(s8 *)(s0 + 0xC) < 0) {
        *(s8 *)(a + 0x1B1) = -0x80;
        a[0x201] = 0;
        func_001865B0(a);
        return;
    }
    if (*(s8 *)(s0 + 0xC) > 0) {
        if (func_00182E20(a) != 0) a[0x152] = 1;
        *(s16 *)(s1 + 0x270) = *(s16 *)(s1 + 0x270) - 1;
        if (func_00182D30(s1) != 0) {
            *(s8 *)(s0 + 0xC) = -1;
            func_001757E0(a, 0xF, 3);
        }
    }
    D_0045DCE0[*(s8 *)(a + 0x151) >> 1](a, s1);
}
