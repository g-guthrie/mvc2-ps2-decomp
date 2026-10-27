typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u16 D_004D17D8;
extern u8 D_004D17DA, D_004D17DB, D_004D17DC, D_004D17DD, D_004D17DE, D_004D17DF;
extern u8 D_00584E54[], D_00584E56[], D_00584E57[], D_00584E58[], D_00584E59[], D_00584E5A[], D_00584E5B[];
void func_0038A900(s32 i) {
    D_004D17D8 = *(u16 *)(D_00584E54 + i * 60);
    D_004D17DA = D_00584E56[i * 60];
    D_004D17DB = D_00584E57[i * 60];
    D_004D17DC = D_00584E58[i * 60];
    D_004D17DD = D_00584E59[i * 60];
    D_004D17DE = D_00584E5A[i * 60];
    D_004D17DF = D_00584E5B[i * 60];
}

extern u8 *func_003DA750(s32, s32, s32);
extern void func_0014F0E0();
void func_0014F020(u8 *p, s32 a1, s32 a2, f32 f) {
    u8 *o = func_003DA750(0, 0xD, 1);
    if (o != 0) {
        if (a2 != 0) {
            *(u32 *)(o + 0x34) = 0xC12E6666;
        } else {
            *(u32 *)(o + 0x34) = 0xC121999A;
        }
        *(f32 *)(o + 0x38) = f;
        *(u32 *)(o + 0x3C) = 0x3E051EB8;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0014F0E0;
        *(s32 *)(o + 0xD0) = 0x21;
        *(s16 *)(o + 0x1E) = a1;
        o[0x23] = a2;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}

void func_001F41C0(u8 *p) {
    extern s32 func_00175700();
    extern void func_00185490();
    extern void func_00184540();
    extern void func_001266A0();
    u8 *q;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    p[0x206] = 3;
    if ((s8)func_00175700(p) < 0) {
        func_00185490(p);
        func_00184540(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        if (p[0x269] == 3) {
            q[0x1B5] = 0x3C;
            p[0x1B5] = 0x3C;
        } else {
            q[0x1B5] = *(s8 *)(p + 0x1B7) + 0x3B;
            p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x3B;
        }
    }
}
void func_003C4FB0(u8 *p, u8 *q) {
    extern s32 func_00175700();
    extern void func_003DAA40();
    extern u8 *func_003C4990(u8 *, u8, u8);
    extern void func_001E7F60();
    extern s32 func_00174240();
    p[0x24] = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -1;
    if ((s8)func_00175700(p) < 0) {
        func_003DAA40(p);
        return;
    }
    if (p[0x21] == 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_003C4990(p, 2, 0);
            func_003C4990(p, 2, 1);
        }
    }
    if (*(s8 *)(q + 0x1B2) == 0) {
        func_001E7F60(p);
    }
    if (func_00174240(p) == 0) {
        p[0x13C] = 0;
    } else {
        p[0x13C] = 1;
    }
}

extern u8 D_00456EE0[];
void func_00293C60(u8 *p) {
    extern void func_00294B20();
    extern void func_001757E0();
    extern void func_00175700();
    extern void func_0038D390();
    extern void func_00294080();
    extern void func_00294BC0();
    u32 t;
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[6];
        p[6] = t + 1;
        func_00294B20(p, D_00456EE0);
        func_001757E0(p, 0x16, 4);
        return;
    }
    if (*(s16 *)(p + 0x1C) & 1) {
        p[0x1B5] = 0x4C;
    } else {
        p[0x1B5] = 0x44;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_0038D390(p, 4);
        func_0038D390(p, 3);
    }
    func_00294080(p);
    func_00294BC0(p);
}

typedef struct { u8 pad00[0x1C]; s16 h1c; s16 h1e; u8 pad1[0x131]; s8 b151; } S2D_o;
void func_002DAA30(S2D_o *p) {
    extern void func_002DAB90();
    extern void func_00175700();
    extern void func_00175C00();
    extern void func_001757E0();
    extern void func_0039FC80();
    u32 t;
    s16 v;
    ((u8 *)p)[0x40C] = 2;
    ((u8 *)p)[0x33C] = 5;
    func_002DAB90(p);
    func_00175700(p);
    v = p->h1c - 1;
    p->h1c = v;
    if (v == 0) {
        t = ((u8 *)p)[6];
        ((u8 *)p)[6] = t + 1;
        func_00175C00(p, 1);
        func_001757E0(p, 0x15, 0x1B);
        return;
    }
    if (p->b151 < 0) {
        p->b151 = 0;
        if ((*(u16 *)((u8 *)p + 0x362) & 0x360) != 0) {
            v = p->h1e - 1;
            p->h1e = v;
            if (v >= 0) {
                p->h1c = p->h1c + 1;
            }
        }
        func_0039FC80(p);
    }
}

