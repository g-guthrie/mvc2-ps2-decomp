typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_00299280(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_00299010(u8 *);
    f32 z = 0.0f;
    f32 c;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x68) * *(f32 *)(p + 0x5C) <= z)) {
        *(f32 *)(p + 0x5C) = z;
        *(f32 *)(p + 0x68) = z;
    }
    func_00175700(p);
    func_00299010(p);
    if (*(s8 *)(p + 0x151) < 0) p[0x151] = 0;
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        if (p[0x1E6] != 0) c = 16.66666603088379f; else c = -16.66666603088379f;
        *(f32 *)(p + 0x5C) = c;
        if (p[0x1E6] != 0) c = -0.625f; else c = 0.625f;
        *(f32 *)(p + 0x68) = c;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0) c = 20.0f; else c = -20.0f;
        *(f32 *)(p + 0x5C) = c;
        if (p[0x1E6] != 0) c = -0.625f; else c = 0.625f;
        *(f32 *)(p + 0x68) = c;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
    }
}
typedef struct { s16 a, b, c; } T6;
extern T6 D_004B573A[], D_004B573C[], D_004B573E[];
void func_001B3C10(u8 *p) {
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_001B3D90(u8 *, u8 *);
    u8 *q;
    s32 x;
    s32 v;
    q = *(u8 **)(p + 0x18);
    v = *(s8 *)(q + 0x151);
    if (v == 0) {
        p[6] = 0;
        p[5] = 0;
        p[4] = 0;
        p[0x13C] = 0;
        *(s32 *)(p + 0x48) = 0;
        return;
    }
    func_001754A0(p, 0x1B, (u8)((s8)v + 0x23));
    func_001B3D90(q, p);
    if (*(s16 *)(q + 0x140) != 0) {
        x = D_004B573A[*(s8 *)(q + 0x151)].a;
    } else {
        x = -D_004B573A[*(s8 *)(q + 0x151)].a;
    }
    *(f32 *)(p + 0x34) += (f32)x;
    *(f32 *)(p + 0x38) += (f32)D_004B573C[*(s8 *)(q + 0x151)].a;
    *(s32 *)(p + 0x48) = D_004B573E[*(s8 *)(q + 0x151)].a;
    if (*(s8 *)(q + 0x151) > 2) {
        p[0x24] = *(s8 *)(q + 0x24);
        *(s8 *)(p + 0x31) = 1;
    } else {
        *(s8 *)(p + 0x31) = -1;
    }
}
