typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G42;
typedef struct { f32 a, b; } T42;
extern G42 *D_004C2794;
extern f32 D_004F1F4C[];
extern T42 D_004548E0[];
extern T42 D_004548E4[];

void func_00271280(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001B8200(u8 *, s32);
    f32 g;
    f64 r;
    f64 k;
    u32 t;

    if (p[0x1E6] != 0) {
        g = D_004F1F4C[0];
        r = (f64)g - 320.0;
    } else {
        g = D_004F1F4C[0];
        k = 320.0;
        r = k + (f64)g;
    }
    *(f32 *)(p + 0x34) = (f32)r;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = p[0x1B7] ? 3 : 3;
        *(s16 *)(p + 0x1E) = 0;
        p[0x22] = 0;
        p[0x1B5] = p[0x1B7] ? 0x39 : 0x36;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = (p[0x1E6] != 0) ? D_004548E0[p[0x1B7]].a : -D_004548E0[p[0x1B7]].a;
        *(f32 *)(p + 0x60) = D_004548E4[p[0x1B7]].a;
        if (p[0x1B7] != 0)
            *(s32 *)(p + 0x48) = 0xF200;
        func_001B8200(p, 0);
    }
}
