typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x; s32 pad[3]; } E16;
typedef struct { u8 pad[0x44]; s32 v; u8 pad2[4]; } E4C;
extern E16 D_004D1820[];
extern void func_00396F90();

extern void func_0016B0C0();
extern void func_00166C80();
void func_001669F0(u8 *a0, s32 a1) {
    func_0016B0C0(a0, a1, 0);
    func_0016B0C0(a0, a1, 1);
    func_00166C80(a0, a1, *(s32 *)(a0 + 0x4C8) < *(s8 *)(a0 + 0x4BD));
}

typedef struct { s16 a; s16 b; s32 c; } Ent8;
extern u8 D_004CAB5C;
extern u8 D_004CAB5B;
extern Ent8 D_004CA6F0[];
void func_0012E5E0(s16 a0, s16 a1, s32 a2) {
    u32 t;
    Ent8 *e;
    u32 u;
    u = D_004CAB5C;
    D_004CAB5C = u + 1;
    t = D_004CAB5B;
    D_004CAB5B = t + 1;
    e = &D_004CA6F0[t];
    u = D_004CAB5B;
    D_004CAB5B = u & 0x7F;
    e->a = a0;
    e->c = a2;
    e->b = a1;
}

extern u8 *func_003DA750();
extern void func_00395A00();
void func_003958B0(u8 *a0, u8 a1) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_00395A00;
        *(u8 **)(r + 0x18) = a0;
        *(u32 *)(r + 0xD0) = *(u16 *)(a0 + 0x168);
        r[0x20] = a1;
        *(s16 *)(r + 0x26) = 0x2200;
    }
}

extern void func_00135150();
void func_003D8230(u8 *a0) {
    *(u8 *)(*(u8 **)(a0 + 0x24) + 0x209) = 1;
    *(u8 *)(*(u8 **)(a0 + 0x18) + 0x209) = 1;
    {
        s16 v = *(s16 *)(a0 + 0x12) - 1;
        *(s16 *)(a0 + 0x12) = v;
        if (v <= 0) {
            *(s16 *)(a0 + 0x12) = 0x5A;
            *(s16 *)(a0 + 0x12) = 0xFA;
            a0[0] = 3;
            a0[1] = 4;
            func_00135150(0);
        }
    }
}

extern s8 func_00175700();
extern void func_001820A0();
extern void func_00183d50();
extern void func_001757E0();
void func_002BC580(u8 *s) {
    func_00175700(s);
    func_001820A0(s);
    if (*(f32 *)(s + 0x38) <= *(f32 *)(s + 0x430)) {
        u32 t = s[6];
        s[6] = t + 1;
        s[0x20D] = 0;
        *(f32 *)(s + 0x38) = *(f32 *)(s + 0x430);
        func_00183d50(s);
        func_001757E0(s, 1, 3);
    }
}

extern s8 func_00175670();
void func_001C9DD0(u8 *a) {
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (func_00175670(a) < 0) {
        a[4] = 2;
    }
}

typedef void (*Fn)(u8 *);
extern Fn D_00472710[];
extern Fn D_00472720[];
extern void func_0039C5A0();
void func_0039BC90(u8 *a) {
    func_0039C5A0(a);
    if (a[0x20] == 0) {
        D_00472710[a[4]](a);
    } else {
        D_00472720[a[4]](a);
    }
}

extern s32 func_00174470();
extern void func_00350FD0();
extern s32 func_00174240();
extern void func_003C80A0();
void func_003C76C0(u8 *a, s32 b) {
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (!func_00174240(a)) {
        func_003C80A0(a, b);
    }
}

extern void func_0015DCA0();
extern void func_0015DBE0();
extern void func_0015DB20();
extern void func_0015DA50(u8 *, s32);
extern void func_0015D970();
void func_0015D8F0(u8 *a, s32 b) {
    s32 i = 0;
    do {
        func_0015DCA0(a, b);
        func_0015DBE0(a, b);
        func_0015DB20(a, b);
        func_0015DA50(a, b);
        func_0015D970(a, b);
        i++;
    } while (i < 1);
}

extern void func_00183DF0();
void func_00209A00(u8 *a) {
    func_00175700(a);
    if (*(s8 *)(a + 0x151) == 0) {
        func_00183DF0(a, 3);
    }
    {
        s16 v = *(s16 *)(a + 0x1C) - 1;
        *(s16 *)(a + 0x1C) = v;
        if (v == 0) {
            u32 t = a[6];
            a[6] = t + 1;
            *(s32 *)(a + 0x5C) = 0;
            *(s32 *)(a + 0x60) = 0;
            *(s32 *)(a + 0x68) = 0;
            *(s32 *)(a + 0x6C) = 0;
            func_001757E0(a, 0xA, 4);
        }
    }
}

extern void func_00388780();
extern void func_001E7F60();
void func_003884D0(u8 *a, u8 *b) {
    if (*(s8 *)(a + 0x1B2) != 0 || *(s8 *)(a + 0x1B3) != 0) {
        u32 t = a[4];
        a[4] = t + 1;
        a[5] = 0;
        *(u32 *)(b + 0xD0) &= ~(1 << a[0x20]);
    } else {
        func_00388780();
        func_00175700(a);
        func_001E7F60(a);
    }
}


void func_00197F70(u8 *a) {
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    func_00175700(a);
    if (!func_00174240(a)) {
        u32 t;
        a[0x13C] = 0;
        t = a[4];
        a[4] = t + 1;
    }
}

extern void func_00146040();
void func_00146BF0(void) {
    s32 i;
    func_00146040(3, 0, 0);
    func_00146040(4, 0, 0);
    func_00146040(4, 1, 0);
    func_00146040(4, 2, 0);
    i = 0;
    do {
        func_00146040(0, (s8)i, 0);
        i++;
    } while (i < 9);
}

extern void func_00248310();
extern void func_00360980();
void func_00245E80(u8 *a) {
    if (func_00175700(a) < 0) {
        func_001843A0(a);
    } else {
        func_00248310(a);
        if (*(s8 *)(a + 0x151) != 0) {
            a[0x151] = 0;
            func_00360980(a, 0, 0);
            func_00360980(a, 1, 0);
            a[0x28E] = 0x10;
            a[0x28F] = 0;
        }
    }
}

void func_0020E200(u8 *a) {
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x1FE] = 1;
    a[0x201] = 2;
    a[0x209] = 2;
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        u32 t = a[6];
        a[6] = t + 1;
        *(u32 *)(a + 0x5C) = 0;
        *(u32 *)(a + 0x68) = 0;
        *(s16 *)(a + 0x1C) = 0xC;
        *(u32 *)(a + 0x60) = 0x42092492;
        *(u32 *)(a + 0x6C) = 0xBECDB6DB;
    }
}
