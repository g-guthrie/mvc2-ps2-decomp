typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { u8 pad[0x1C]; s16 h1C; s16 h1E; u8 pad2[0x30]; f32 f50; f32 f54; } PK;
extern f64 func_00119B08(s32);
extern s32 dptoli(f64);

void func_0036DF50(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0018C4B0(u8 *, s32);
    extern f32 func_00417440(u32);
    u8 *o;
    f32 k;
    f32 c;
    f32 x;
    s16 t;
    s16 v;
    u8 *r;
    PK *sa = (PK *)p;

    o = *(u8 **)(q + 0x220);
    p[0x13C] = 1;
    p[0x24] = 9;
    func_00175700(p);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x1B3) != 0) {
        p[5] = 1;
        sa->h1C = 0x1E;
        func_001757E0(p, 0x17, 0x1D);
        return;
    }
    t = sa->h1C;
    sa->h1C = t - 1;
    if (t == 0) {
        p[5] = 1;
        sa->h1C = 0x1E;
        func_001757E0(p, 0x17, 0x1D);
    } else if (*(u8 *)((r = *(u8 **)(p + 0x1C4)) + 0x425) != 0) {
        p[5] = 1;
        sa->h1C = 0x1E;
        func_001757E0(p, 0x17, 0x1D);
    } else if (*(s16 *)(r + 0x434) == 0) {
        p[5] = 1;
        sa->h1C = 0x1E;
        func_001757E0(p, 0x17, 0x1D);
    } else if (*(s16 *)(q + 0x434) == 0) {
        p[5] = 1;
        sa->h1C = 0x1E;
        func_001757E0(p, 0x17, 0x1D);
    } else {
        x = sa->f50;
        if (x > 1.0f) {
            k = 1.0f;
            sa->f50 = k;
            sa->f54 = k;
        } else {
            k = 0.03999999910593033f;
            sa->f50 += k;
            sa->f54 += k;
        }
        if (sa->h1C % 10 == 0) {
            func_0018C4B0(o, -2);
        }
        *(s16 *)(p + 0x140) = *(s16 *)(o + 0x140);
        *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
        if (*(s16 *)(p + 0x140) != 0) {
            k = -53.33333206176758f;
        } else {
            k = 53.33333206176758f;
        }
        *(f32 *)(p + 0x34) += k;
        c = 68.57142639160156f;
        *(f32 *)(p + 0x38) = c + *(f32 *)(o + 0x38);
        *(f32 *)(p + 0x3C) = *(f32 *)(o + 0x3C);
        { f32 r = func_00417440((u32)dptoli(0.5 + 65536.0 * func_00119B08(sa->h1E) / 360.0) & 0xFFFF); f32 a = 20.0f; f32 b = 2.142857074737549f; r = b * (a * r); *(f32 *)(p + 0x38) += r; }
        v = sa->h1E - 3;
        sa->h1E = v;
        if (v == 0) {
            sa->h1E = 0x168;
        }
    }
}
