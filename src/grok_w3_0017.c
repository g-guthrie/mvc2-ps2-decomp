typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef void (*DispatchFn)(u8 *);

extern s32 func_00175700(u8 *);
extern void func_00173650(u8 *);
extern void func_00173590(u8 *);
extern void func_001734F0(u8 *);
extern void func_0018CEA0(u8 *);
extern void func_00178DA0(u8 *);
extern void func_00186CE0(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0018F320(u8 *);
extern void func_001E3A10(u8 *);
extern void func_00158C70(u8 *, s32);
extern void func_00177EE0(u8 *);
extern void func_00172320(s32);
extern s32 func_00417700(f32, f32);

extern DispatchFn jtbl_00448B20[];
extern DispatchFn jtbl_00448920[];

void func_00173C30(u8 *p) {
    if (*(s8 *)(p + 1312)) {
        func_00173650(p);
    } else {
        func_00173590(p);
    }
    func_001734F0(p);
}

void func_0017B4B0(u8 *p) {
    func_0018CEA0(p);
    jtbl_00448B20[p[6]](p);
}

void func_00177550(u8 *p) {
    p[520] = 2;
    func_00178DA0(p);
    jtbl_00448920[p[6]](p);
}

void func_0017DD40(u8 *p) {
    p[511] = 2;
    if ((s8)func_00175700(p) < 0) {
        func_00186CE0(p, 0);
    }
}

void func_0017E460(u8 *p) {
    p[511] = 2;
    if ((s8)func_00175700(p) < 0) {
        func_00186CE0(p, 23);
    }
}

void func_0017C450(u8 *p) {
    p[520] = 2;
    if ((s8)func_00175700(p) < 0) {
        p[618] = 2;
        p[7] = 0;
        p[6] = 0;
    }
}

void func_00177B40(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 13, 34);
    }
}

void func_00177EE0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 13, 31);
    }
}

void func_00177F30(u8 *p) {
    s16 t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if ((s16)(t - 1) < 0) {
        p[6]++;
        func_001757E0(p, 17, 0);
    }
}

void func_00176E20(u8 *p) {
    func_0018F320(p);
    func_00175700(p);
    if (*(f32 *)(p + 96) < 0.0f) {
        func_00186CE0(p, 15);
    }
}

void residual_00177E90(u8 *p) {
    p[6]++;
    *(s16 *)(p + 28) = 16;
    func_001E3A10(p);
    func_00158C70(p + 52, p[2]);
    func_00177EE0(p);
}

void func_00172370(s32 a0) {
    if (a0 & 1)
        func_00172320(0);
    if (a0 & 2)
        func_00172320(1);
}

s32 func_001748C0(u8 *a0, u8 *a1) {
    s32 v0 = func_00417700(*(f32 *)(a1 + 4) - *(f32 *)(a0 + 4),
                           *(f32 *)(a1 + 0) - *(f32 *)(a0 + 0));
    return (320 - (s8)(v0 & 0xFF)) & 0xFF;
}
