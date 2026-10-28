/* MW 3.0.3: MWWARM@src/dp5_a.c "-O3 -Op -fp off -sdatathreshold 8"; func_002C8730 is the warm predecessor of func_002C9000 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* see header */
void func_002C8730(u8 *p, u8 *q) {
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    u8 *t;
    f32 v;
    u32 u;
    f32 c;
    u = p[6];
    p[6] = u + 1;
    func_0018C4B0(p, 10);
    func_00185490(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    t = *(u8 **)(p + 0x220);
    *(f32 *)(p + 0x5C) = *(f32 *)(t + 0x34) - *(f32 *)(p + 0x34);
    *(f32 *)(p + 0x5C) /= 32.0f;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x414DB6DB;
    *(u32 *)(p + 0x6C) = 0xBF9A4924;
    *(s16 *)(p + 0x1C) = 0;
    if (q[3] != 0) {
        *(s16 *)(p + 0x1C) = 5;
        *(u32 *)(p + 0x6C) = 0xBF892492;
    }
    t = *(u8 **)(p + 0x220);
    c = 0.0f;
    v = 205.7142791748047f;
    if (t[0x20D] == 2) v = 274.28570556640625f;
    if (t[0x20D] == 1) v = 102.85713958740234f;
    v += *(f32 *)(t + 0x38);
    v -= *(f32 *)(p + 0x38);
    if (v > c) {
        f32 m = 308.5714111328125f;
        if (v < m) v = m;
    }
    *(f32 *)(p + 0x60) += (f32)((f64)v / 32.0);
    if (p[0x20D] != 2) func_00183D10(p);
    func_001757E0(p, 0x15, 7);
    func_00175700(p);
}

void func_002C9000(u8 *p, u8 *q) {
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *t;
    f32 v;
    u32 u;
    f32 c;
    f32 m;
    f32 d, z;
    u = p[6];
    p[6] = u + 1;
    func_0018C4B0(p, 5);
    func_00185490(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    z = 0.0f;
    t = *(u8 **)(p + 0x220);
    d = *(f32 *)(t + 0x34) - *(f32 *)(p + 0x34);
    *(f32 *)(p + 0x5C) = d;
    if (d < z) c = -20.0f; else c = 20.0f;
    *(f32 *)(p + 0x5C) += c;
    *(f32 *)(p + 0x5C) /= 32.0f;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x414DB6DB;
    *(u32 *)(p + 0x6C) = 0xBF700000;
    *(s16 *)(p + 0x1C) = q[3] ? 5 : 0;
    t = *(u8 **)(p + 0x220);
    c = 0.0f;
    v = 205.7142791748047f;
    if (t[0x20D] == 2) v = 274.28570556640625f;
    if (t[0x20D] == 1) v = 102.85713958740234f;
    v += *(f32 *)(t + 0x38);
    v -= *(f32 *)(p + 0x38);
    if (v > c) {
        m = 308.5714111328125f;
        if (v < m) v = m;
    }
    *(f32 *)(p + 0x60) += (f32)((f64)v / 32.0);
    if (p[0x20D] != 2) func_00183D10(p);
    func_001757E0(p, 0x15, 0xD);
}
