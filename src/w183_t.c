typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002719C0(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_00185980(u8 *);
    extern void func_00185640(u8 *, u32);
    extern void func_001B8DC0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183D50(u8 *);
    f32 *a3, *t0, *t1, *t2;
    f32 eight;
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    a3 = (f32 *)(p + 0x5C);
    t1 = (f32 *)(p + 0x68);
    t0 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t2 = (f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (func_00185980(p)) {
            t = p[7];
            p[7] = t + 1;
            p[0x20B] = 0xC2;
            func_00185640(p, *(u32 *)(p + 0x1C4));
            func_001B8DC0(p);
        } else {
            t = p[7];
            eight = 8.0f;
            p[7] = t + 1;
            *(f32 *)(p + 0x5C) = -(*(f32 *)(p + 0x5C) / eight);
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x60) = 0x41092492;
            *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
            func_001757E0(p, 0x15, 0x16);
        }
        return;
    } else {
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            t = p[7];
            p[7] = t + 2;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            *(u32 *)a3 = 0;
            *(u32 *)t0 = 0;
            *(u32 *)t1 = 0;
            *(u32 *)t2 = 0;
            func_001757E0(p, 1, 3);
            func_00183D50(p);
        }
    }
}
