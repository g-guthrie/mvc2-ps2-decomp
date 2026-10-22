typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_00183d50(u8 *);
extern void func_002E67D0(u8 *, u8 *);

void func_002E6440(u8 *p, u8 *q) {
    f32 *a, *b, *c, *d;
    s32 fl;
    s32 r;
    fl = *(s8 *)(p + 0x1B2);
    if (fl != 0 && ((s8)fl & 1) != 0) {
        p[7]++;
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C) / 4.0f;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF9A4924;
        func_001757E0(p, 0x15, 7);
        return;
    }
    if (p[0x1FD] == 1) func_002E67D0(p, q);
    if (*(s8 *)(p + 0x151) == 0) {
        a = (f32 *)(p + 0x5C);
        c = (f32 *)(p + 0x68);
        b = (f32 *)(p + 0x60);
        d = (f32 *)(p + 0x6C);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            p[6]++;
            p[7] = 0;
            p[0x20D] = 0;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            *(u32 *)a = 0;
            *(u32 *)b = 0;
            *(u32 *)c = 0;
            *(u32 *)d = 0;
            func_00183d50(p);
            func_001757E0(p, 0x15, 0xB);
        } else {
            fl = *(s8 *)(p + 0x211);
            if (fl != 0 && ((s8)fl & (1 << p[0x1E6])) == 0) {
                p[7]++;
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C) / 4.0f;
                *(u32 *)(p + 0x60) = 0x414DB6DB;
                *(u32 *)(p + 0x6C) = 0xBF9A4924;
                func_001757E0(p, 0x15, 7);
            } else {
                func_00175700(p);
            }
        }
    } else {
        r = func_00175700(p);
        if ((s8)r < 0) {
            q[5] = 0;
            func_001757E0(p, 0x15, 9);
        }
    }
}
