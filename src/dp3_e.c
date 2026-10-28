typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { u8 pad[0x1C]; s16 h1C; s16 h1E; } PK;

void func_0037AB50(u8 *p, u8 *q, s32 *r)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00185980(u8 *);
    extern void func_0037B220(u8 *, u8 *, s32 *);
    extern void func_001E3210(u8 *, s32);
    extern s32 func_0037AAD0(u8 *);
    extern void func_00175700();
    extern void func_001E7F60(u8 *);
    f32 *s0, *s1, *s2, *s3;
    s16 v;
    s32 t;
    s32 d;
    f32 k;
    f32 z;
    PK *sa = (PK *)p;

    if (*(s8 *)(p + 0x1B3) != 0) {
        p[4] = 5;
        p[0x13C] = 0;
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        p[4] = 2;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x17, 0xE);
        *(s32 *)(p + 0xDC) = 0xF;
        if (func_00185980(p) != 0) {
            *r = 1;
            func_0037B220(p, q, r);
        }
        *(s32 *)(p + 0x48) = 0;
        func_001E3210(p, 0x22);
        return;
    }
    if (*(s32 *)(q + 0x2C4) == 0 && *(s32 *)(q + 0x2C8) == 0) goto stop;
    v = sa->h1C - 1;
    sa->h1C = v;
    if (v < 0) {
        sa->h1C = 0;
        if (*(s32 *)(q + 0x2C4) == 0) goto stop;
        t = *(s32 *)(p + 0xD4) + 1;
        *(s32 *)(p + 0xD4) = t;
        if (t > 0x3C) goto stop;
    }
    if (func_0037AAD0(p) != 0) {
        p[4] = 5;
        p[0x13C] = 0;
    } else {
    s0 = (f32 *)(p + 0x5C);
    s2 = (f32 *)(p + 0x68);
    s1 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    s3 = (f32 *)(p + 0x6C);
    if (p[6] == 0) {
        func_00175700();
        d = (*(s16 *)(p + 0x140) != 0) ? 10 : -10;
        sa->h1E += (s16)d;
        if (sa->h1E >= 0x168) {
            sa->h1E = 0;
        } else if (sa->h1E <= 0) {
            sa->h1E = 0x168;
        }
        *(s32 *)(p + 0x48) = (u32)(s32)(0.5 + 65536.0 * (f64)sa->h1E / 360.0) & 0xFFFF;
    }
    if (p[5] < 4) {
        if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
            *(f32 *)(p + 0x38) = 0.0f;
            k = -0.2f;
            z = 0.0f;
            p[5]++;
            *(f32 *)(p + 0x60) *= k;
            if (p[5] > 3) {
                p[5] = 4;
                *s0 = z;
                *s1 = z;
                *s2 = z;
                *s3 = z;
                p[6] = 1;
            }
        }
    }
    func_001E7F60(p);
    }
    return;
stop:
    p[4] = 2;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    func_001E3210(p, 0x22);
    func_001757E0(p, 0x17, 0xE);
    *(s32 *)(p + 0x48) = 0;
    *(s32 *)(p + 0xDC) = 0xF;
}
