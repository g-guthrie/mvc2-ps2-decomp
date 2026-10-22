typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x38]; f32 f38; u8 pad1[0x430-0x3C]; f32 f430; } SB;

void func_002FE1C0(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *v0, *v1, *a1, *a2;
    s32 s0;
    f32 z, t;
    SB *sa;

    z = 0.0f;
    v0 = (f32 *)(p + 0x5C);
    a1 = (f32 *)(p + 0x68);
    v1 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a2 = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) > z) {
        *v0 = z;
        *a1 = z;
    }
    sa = (SB *)p;
    if (sa->f430 >= sa->f38) {
        sa->f38 = sa->f430;
        p[0x20D] = 0;
        *(u32 *)v1 = 0;
        *(u32 *)a2 = 0;
    }
    s0 = 0;
    if (p[0x1E6] == 0) {
        if (*(s8 *)(p + 0x211) == 2) s0 = 1;
    } else {
        if (*(s8 *)(p + 0x211) == 1) s0 = 1;
    }
    if (func_00175700(p) < 0 || s0 == 1) {
        u32 t6 = p[6];
        p[6] = t6 + 1;
        *(f32 *)(p + 0x5C) /= 4.0f;
        *(f32 *)(p + 0x68) /= 4.0f;
        if (p[0x20D] != 2) {
            p[0x168] = 2;
        } else {
            p[0x168] = 3;
            *(f32 *)(p + 0x60) /= 4.0f;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        }
        func_001757E0(p, 0x15, p[0x168]);
        q[0xA] = 0;
    }
}
