typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G15e;
extern G15e *D_004C2794;

void func_002185D0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_002189D0(u8 *);
    extern void func_00218A30(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 z = 0.0f;
    f32 *a, *b;
    s8 r;
    s16 t;
    u8 x;
    u32 w;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
        *a = z;
        *b = z;
    }
    r = func_00175700(p);
    if (r < 0) {
        func_001E3210(p, 0x1F);
        if (*(s16 *)(p + 0x1C) != 0) {
            *(s16 *)(p + 0x1C) = 0;
            t = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = t;
            if (t > 0) {
                *(f32 *)(p + 0x60) += 10.714284896850586f;
                w = p[0x20];
                x = w ^ 1;
                p[0x20] = x;
                func_001757E0(p, 0x15, (u8)(x + 1));
                return;
            }
        }
        p[7] = 3;
        p[0x1B5] = 0x4B;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x15, 3);
    } else {
        func_002189D0(p);
        func_00218A30(p);
    }
}
