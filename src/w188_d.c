typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w188_d.c "-O3 -Op -sdatathreshold 0" */

void func_0022E430(u8 *p) {
    u32 *s1, *s2, *s3, *s4;
    f32 c;
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s1 = (u32 *)(p + 0x5C);
    s3 = (u32 *)(p + 0x68);
    s2 = (u32 *)(p + 0x60);
    s4 = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 2, 3);
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
        *s4 = 0;
        if (p[0x1E6] != 0) {
            c = -53.33333206176758f;
            *(f32 *)(p + 0x34) += c;
            *(u32 *)(p + 0x5C) = 0xC0BAAAAA;
            *(u32 *)(p + 0x68) = 0x3ED55555;
        } else {
            c = 53.33333206176758f;
            *(f32 *)(p + 0x34) += c;
            *(u32 *)(p + 0x5C) = 0x40BAAAAA;
            *(u32 *)(p + 0x68) = 0xBED55555;
        }
        p[6]++;
    }
}

void func_0025F9E0(u8 *a) {
    u32 buf[4];
    f32 c;
    extern s32 func_00175700(u8 *);
    extern void func_001830D0(u8 *, u32 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0036BFF0(u8 *, s32, s32, s32);
    a[0x40C] = 2;
    a[0x33C] = 5;
    if ((s8)func_00175700(a) >= 0) {
        if (*(s8 *)(a + 0x151) == 1) {
            a[0x151] = 0;
            buf[0] = 0xC1D55555;
            buf[1] = 0x43092492;
            func_001830D0(a, buf, 1);
        }
    }
    if ((s8)a[0x153] < 0) {
        a[6]++;
        if (a[0x20D] != 2) {
            a[0x20D] = 2;
            c = 21.428569793701172f;
            *(f32 *)(a + 0x38) = c + *(f32 *)(a + 0x430);
        }
        a[7] = 0;
        func_001757E0(a, 0x16, 3);
        *(s16 *)(a + 0x366) = 0;
        func_0036BFF0(a, 0xA, 0x13, 0xA);
        func_0036BFF0(a, 9, 0x13, 9);
        func_0036BFF0(a, 0xB, 0x13, 0xB);
    }
    func_00175700(a);
}

extern f32 D_004B8360[];
extern f32 D_004B8364[];
void func_00375760(u8 *a, u8 *b) {
    f32 s;
    f32 t;
    u8 *c;
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    s = -70.0f * func_00417500(*(s32 *)(b + 0x48)) + -8.571428298950195f * func_00417440(*(s32 *)(b + 0x48));
    t = -70.0f * func_00417440(*(s32 *)(b + 0x48)) + -8.571428298950195f * func_00417500(*(s32 *)(b + 0x48));
    c = *(u8 **)(b + 0x14);
    *(f32 *)(b + 0x34) = *(f32 *)(c + 0x34);
    *(f32 *)(b + 0x38) = *(f32 *)(c + 0x38);
    if (a[0x1E6] != 0) s = -s;
    *(f32 *)(b + 0x34) += s;
    *(f32 *)(b + 0x38) += t;
    *(f32 *)(b + 0x50) = D_004B8360[a[0x168] * 2];
    *(f32 *)(b + 0x54) = D_004B8364[a[0x168] * 2];
    *(s8 *)(b + 0x24) = *(s8 *)(a + 0x24);
    *(s8 *)(b + 0x31) = -1;
}

void func_003A9CF0(u8 *a, u8 *b) {
    f32 k;
    u32 t;
    extern void func_003A9E60(u8 *, s32);
    extern void func_003A9AB0(u8 *, u8 *);
    extern s32 func_00174780(u8 *);
    extern void func_003A9E50(u8 *, u8 *);
    extern s32 func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    if (a[0x20] == 0) {
        *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
        *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
        *(f32 *)(a + 0x64) = *(f32 *)(b + 0x34);
        t = a[0x22];
        a[0x22] = t + 3;
        t = a[0x22];
        a[0x22] = t & 0x1F;
        func_003A9E60(a, 0x1F40);
        *(s16 *)(a + 0x1E) = 1;
        t = a[0x22];
        if ((u8)(t - 8) < 0x11) *(s16 *)(a + 0x1E) = -1;
        func_003A9AB0(a, b);
        if (func_00174780(a) == 0) goto err;
        goto done;
    } else {
        *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + *(f32 *)(a + 0x64);
        if ((s8)func_00175700(a) < 0) goto err;
        func_001E7F60(a);
        if (*(s8 *)(a + 0x150) != 0) {
            *(s8 *)(a + 0x150) = 0;
            k = 0.75f;
            *(f32 *)(a + 0x50) *= k;
            *(f32 *)(a + 0x54) *= k;
        }
    }
done:
    return;
err:
    func_003A9E50(a, b);
}
