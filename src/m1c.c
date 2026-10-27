typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern f32 D_004F1FC8, D_004F1FCC, D_004F1FD0;
extern s32 func_00175700(void *);
extern void func_001757E0(void *, s32, s32);

/* Provisional: callback-table ABI and state bounds remain unresolved. */
void func_003C3690(u8 *p, void *q) {
    func_00175700(p);
    if (p[0x21] == 0) {
        *(f32 *)(p + 0x34) = D_004F1FCC;
    } else {
        *(f32 *)(p + 0x34) = D_004F1FC8;
    }
    *(f32 *)(p + 0x38) = D_004F1FD0 - 102.85713959f;
}

void func_002A6610(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        {
            s16 v = p[0x1E6] ^ 1;
            *(s16 *)(p + 0x140) = v;
            p[0x1E6] = v;
        }
        func_001757E0(p, 15, 3);
    }
}

void func_00381650(u8 *p) {
    f32 t;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    t = 1.6666666269f * (f32)(p[0x23] << 5);
    if (*(s16 *)(p + 0x140) == 0) {
        t = -t;
    }
    *(f32 *)(p + 0x34) += t;
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
}

static void func_00396DD0(u8 *p, u8 *a) {
    f32 t;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    t = 1.6666666269f * (f32)(a[6] << 5);
    if (*(s16 *)(p + 0x140) == 0) {
        t = -t;
    }
    *(f32 *)(p + 0x34) += t;
}

typedef void (*CB3)(u8 *, u8 *, u8 *);
extern CB3 D_00472490[], D_004724A0[];

void func_00396E30(u8 *p) {
    u8 *a = p + 0x88;
    if (p[0x20] == 0) {
        D_00472490[p[4]](p, *(u8 **)(p + 0x18), a);
    } else {
        u8 *r = *(u8 **)(p + 0x18) + 0x88;
        func_00396DD0(p, a);
        *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
        D_004724A0[p[4]](p, a, r);
    }
}

static f32 func_002ADC20(u8 *p) {
    f32 a = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += a;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    return *(f32 *)(p + 0x5C) * a;
}
extern void func_00183DF0(void *, s32);
extern void func_001757E0(void *, s32, s32);

void func_002B0B40(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (func_002ADC20(p) < 0.0f) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[6] = 9;
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        func_001757E0(p, 0x16, 3);
    } else {
        func_00183DF0(p, 3);
    }
}
