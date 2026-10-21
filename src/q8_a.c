typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0016B240();
extern void func_0016B0C0();
extern s32 func_00164E90();
s32 func_00164E10(u8 *p, s32 b) {
    if (func_0016B240(p, 0) == 0) return 0;
    func_0016B0C0(p, b, 0);
    func_0016B0C0(p, b, 3);
    *(f32 *)(p + 0x460) = *(f32 *)(p + 0x4C8);
    return func_00164E90(p, b);
}
extern s32 D_004D17CC;
extern s32 D_004D1788;
extern void func_001E3CE0(s32);
void func_00131550(u16 a) {
    s32 c = D_004D17CC;
    if (c != -1 && (a & 0x3000) != 0) {
        func_001E3CE0(1);
        c = (c + 1) & 1;
    }
    if ((D_004D1788 & (1 << c)) == 0 && c != -1) {
        c = (c + 1) & 1;
    }
    D_004D17CC = c;
}

extern s32 func_00175700();
extern void func_001757E0();
void func_001F3320(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0x40BAAAAA;
        *(u32 *)(p + 0x68) = 0xBD555555;
        *(u32 *)(p + 0x60) = 0x41F89249;
        *(u32 *)(p + 0x6C) = 0xBFAB6DB6;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 0xF, 0x29);
    }
}

extern s32 func_00174170();
extern f32 D_0044EBB0[];
extern f32 D_0044EBB4[];
extern f32 D_0044EBF0[];
extern f32 D_0044EBF4[];
void func_001DBFB0(u8 *p) {
    u32 t = p[7] - 1;
    p[7] = t;
    if ((t & 0xFF) == 0) {
        u32 u = p[6];
        s32 i;
        p[6] = u + 1;
        i = func_00174170() & 7;
        *(f32 *)(p + 0x5C) = *(f32 *)((u8 *)D_0044EBB0 + i * 8);
        *(f32 *)(p + 0x68) = *(f32 *)((u8 *)D_0044EBB4 + i * 8);
        i = func_00174170() & 7;
        *(f32 *)(p + 0x60) = *(f32 *)((u8 *)D_0044EBF0 + i * 8);
        *(f32 *)(p + 0x6C) = *(f32 *)((u8 *)D_0044EBF4 + i * 8);
    }
}

void func_002AD770(u8 *p) {
    u8 *q = p + 0x2B8;
    u16 *r = (u16 *)(q + 4);
    u16 st = *(u16 *)(p + 0x2BC);
    switch (st) {
    case 0:
        if (*(u16 *)(p + 0x4F4) & 0x2000) *r = st + 1;
        break;
    case 1:
        if (*(u16 *)(p + 0x4F0) & 0x3C00) *r = st + 1;
        break;
    case 2:
        if (*(u16 *)(p + 0x4F4) & 0x1000) *r = st + 1;
        break;
    case 3:
        if (*(u16 *)(p + 0x4F0) & 0x3C00) {
            *r = 0;
            *(u16 *)(q + 8) = 1;
        }
        break;
    }
}

extern s32 func_00175700();
extern void func_00184540();
void func_0020BB80(u8 *p) {
    f32 *a = (f32 *)(p + 0x60);
    f32 *b = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)a = 0;
        *(u32 *)b = 0;
    }
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
    }
}

extern s32 func_00175700();
extern void func_001D0500();
extern void func_001757E0();
void func_002D80F0(u8 *p) {
    u32 *a = (u32 *)(p + 0x5C);
    u32 *b = (u32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001D0500(p, 2);
        *a = 0;
        *(u32 *)(p + 0x60) = 0;
        *b = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] * 2 + 8));
    }
}

extern s32 func_00175700();
extern void func_001843A0();
void func_002348F0(u8 *p) {
    u32 *a = (u32 *)(p + 0x5C);
    u32 *b = (u32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *a = 0;
        *b = 0;
    }
}

extern s32 func_0016B250();
extern s32 func_0016B360();
extern void func_0016B0C0();
s32 func_00167310(u8 *p, s32 b) {
    u16 m;
    s16 v;
    if (func_0016B250(p, 2) == 0) {
        return 0;
    }
    if (func_0016B360(p, b) == 0) {
        return 0;
    }
    func_0016B0C0(p, b, 0);
    func_0016B0C0(p, b, 1);
    m = (*(s32 *)(p + 0x4C8) != 0) ? 0x100 : 0x200;
    v = *(s16 *)(p + 0x4C2);
    if ((v & m) != 0) {
        *(s16 *)(p + 0x4C2) = v ^ (s16)m;
    } else {
        *(u16 *)(p + 0x4F0) = m;
    }
    return 0;
}

typedef struct { f32 x; f32 y; f32 z; } T7F30;
extern T7F30 D_004B7F30[];
void func_003363F0(u8 *p) {
    T7F30 *t = D_004B7F30;
    u8 i = p[0x23];
    f32 v;
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(f32 *)(p + 0x60);
    t += i;
    *(f32 *)(p + 0x38) = v;
    if (v <= t->y) {
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = t->y;
        p[7] = 0;
        p[5] = 0;
    }
}
