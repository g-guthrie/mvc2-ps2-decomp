typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static s32 func_00275A40(u8 *p) {
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        return 1;
    }
    return 0;
}

void func_00275C20(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001BA2F0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0037BE60(u8 *);
    extern void func_001830D0(u8 *, u32 *, s32);
    u32 v[4];
    u32 t;
    s8 r;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00275A40(p);
    r = func_00175700(p);
    if (r < 0) {
        t = p[6];
        p[6] = t + 1;
        if (p[0x20D] == 2) {
            p[0x168] = 4;
            func_001BA2F0(p, 1);
        } else {
            p[0x20D] = 0;
            p[0x168] = 1;
            func_001BA2F0(p, 0);
        }
        func_001757E0(p, 0x16, p[0x168]);
        func_0037BE60(p);
        *(s16 *)(p + 0x1E) = 0x87;
    } else if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        v[0] = 0xC2D00000;
        v[1] = 0x437F0000;
        func_001830D0(p, v, 1);
    }
}

void func_00275E30(u8 *p) {

    extern int func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    extern void func_00184540(void *);
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (p[0x20D] != 2) {
        func_00275A40(p);
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            *(s32 *)(p + 0xD8) = 0;
        }
    } else {
        func_00175700(p);
        if (func_00275A40(p) != 0) {
            func_00184540(p);
            *(s32 *)(p + 0xD8) = 0;
        }
    }
}

typedef struct O_00276C50 {
    u8 p0[0x34]; f32 f34; f32 f38; u8 p3[0x20]; f32 f5c; f32 f60; u8 p4[4]; f32 f68; f32 f6c;
    u8 p5[0x68]; u32 wD8;
} O_00276C50;

extern void func_00184540(void *);
void func_00276C50(u8 *actor) {
    O_00276C50 *p = (O_00276C50 *)actor;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00275A40((u8 *)p);
    if ((s8)func_00175700((u8 *)p) < 0) {
        if (*((u8 *)p + 0x20D) != 2) {
            func_001843A0(p);
            p->wD8 = 0;
        } else {
            func_00184540(p);
            p->wD8 = 0;
        }
    }
}
