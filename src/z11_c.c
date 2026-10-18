typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003A9E60(u8 *p, s32 a) {
    extern f32 func_00417500(s16);
    f32 s = func_00417500((s16)(((40 - p[0x22]) & 0x1F) << 11));
    f32 k = 256.0f;
    f32 r = 1000.0f * s;
    f32 u = k * (f32)a;
    r = u * r;
    r = r / 100000.0f / k;
    r = 1.6666666269302368f * r;
    if (*(s16 *)(p + 0x140) != 0) r = -r;
    *(f32 *)(p + 0x34) = r + *(f32 *)(p + 0x64);
}

typedef struct { f32 x, y, z; } V3;

void func_00269170(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00183920(u8 *, V3 *);
    V3 v;
    s8 a;
    f32 d;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    a = *(s8 *)(p + 0x151);
    if (a != 0) {
        if (p[0x1E6] != 0) {
            d = 1.6666666269302368f * (f32)a;
        } else {
            d = -(1.6666666269302368f * (f32)a);
        }
        *(f32 *)(p + 0x34) += d;
        p[0x151] = 0;
    }
    if (*(s8 *)(p + 0x150) == 1) {
        v = *(V3 *)(p + 0x34);
        p[0x150] = 0;
        v.x = 0;
        v.y += 102.85713958740234f;
        func_00183920(p, &v);
    }
}

void func_002A2530(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s16 c;
    u32 t;
    f32 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    c = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = c;
    if (c == 0) {
        t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0) {
            v = -0.7291666269302368f;
        } else {
            v = -0.7291666269302368f;
        }
        *(f32 *)(p + 0x68) = v;
        *(u32 *)(p + 0x6C) = 0xBF809249;
        func_001757E0(p, 2, 2);
    }
}
