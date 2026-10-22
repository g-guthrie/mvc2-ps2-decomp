typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_d;
extern H_d *D_004C2794;

void func_002C9220(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_00185490(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *s0, *s1, *s2, *s3;
    s8 a;
    u32 t;
    f32 v;

    s3 = (f32 *)(p + 0x6C);
    s2 = (f32 *)(p + 0x68);
    s1 = (f32 *)(p + 0x60);
    s0 = (f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) - *(f32 *)(p + 0x430) > 137.14285278320312f) {
        a = *(s8 *)(p + 0x539);
        if ((a != 0 && p[0x212] != 0) || (a == 0 && (*(u16 *)(p + 0x354) & 0x300) != 0)) {
            t = p[6];
            p[6] = t + 1;
            p[0x1B5] = 0x3B;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]] += 1;
            func_00185490(p);
            if (p[0x1E6] != 0) {
                v = -13.333333015441895f;
            } else {
                v = 13.333333015441895f;
            }
            *(f32 *)(p + 0x5C) = v;
            if (p[0x1E6] != 0) {
                v = 0.625f;
            } else {
                v = -0.625f;
            }
            *(f32 *)(p + 0x68) = v;
            *(u32 *)(p + 0x60) = 0x414DB6DB;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
            func_001757E0(p, 0x15, 0xE);
        }
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        p[6] = 4;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0xF);
    }
}
