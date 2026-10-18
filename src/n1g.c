typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_00154390(f32 *, s32);
extern void (*D_004C1CA8[2])(u8 *);

void func_0036F630(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    u32 t;
    D_004C1CA8[p[5]](p);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x1B3) != 0) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else if (q[0x1E4] != 0x15 || q[0x1FD] != 6) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

void func_0026E440(u8 *p) {
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v < 0) {
        u32 t = p[7];
        p[7] = t + 1;
    }
}

void func_00275590(u8 *p) {
    u32 *a;
    u32 *b;
    func_00175700(p);
    a = (u32 *)(p + 0x60);
    b = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[0x20];
        p[0x20] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *a = 0;
        *(u32 *)(p + 0x68) = 0;
        *b = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 1, 3);
        func_00154390((f32 *)(p + 0x34), 0);
    }
}
