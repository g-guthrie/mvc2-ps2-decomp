typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 D_0044A380[];
void func_00197D50(u8 *p, u8 *q) {
    extern void func_00175700(); extern void func_00176160();
    func_00175700(p);
    if (*(s8*)(p+0x150) != 0) {
        s16 v;
        *(s8*)(p+0x150) = 0;
        func_00176160(q, 1, p[0x15B] + D_0044A380[q[0x25]], 1);
        v = *(s16*)(p+0x1C) - 1;
        *(s16*)(p+0x1C) = v;
        if (v == 0) { u32 t = p[4]; p[4] = t + 1; }
        *(f32*)(p+0x34) += *(f32*)(p+0x5C);
        *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    }
}

typedef struct { f32 x, y, z; } V3;
void func_001FA520(u8 *p) {
    extern void func_00175700(); extern void func_001830D0();
    V3 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8*)(p+0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s8*)(p+0x151) = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v = *(V3*)(p+0x34);
        *(u32*)&v.x = 0x40555555; *(u32*)&v.y = 0x43160000;
        func_001830D0(p, &v, 1);
    }
}

void func_00246FA0(u8 *p, u8 *q) {
    extern void func_00175700(); extern s32 func_0035F9E0(); extern void func_001843A0(); extern void func_001757E0();
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8*)(p+0x151) != 0) {
        *(s8*)(p+0x151) = 0;
        if (func_0035F9E0(p, 0, 0) == 0) { func_001843A0(p); return; }
    }
    if (q[5] == 0 && *(s8*)(p+0x1B2) != 0) {
        func_001757E0(p, 0x16, 3);
        q[5] = 1;
    }
    if (q[4] != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16*)(p+0x1C) = 0x14;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}

void func_0024A4A0(u8 *p) {
    extern void func_00183D90(); extern s32 func_00175700(); extern void func_001843A0();
    f32 *a, *b;
    func_00183D90(p);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    a = (f32*)(p+0x5C); b = (f32*)(p+0x68);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
    if (*(s8*)(p+0x151) != 0) {
        *(s8*)(p+0x151) = 0;
        *(u32*)a = 0;
        *(u32*)b = 0;
    }
}

void func_002A8B20(u8 *p) {
    extern void func_00175700(); extern void func_001757E0();
    f32 *a, *b;
    a = (f32*)(p+0x60); b = (f32*)(p+0x6C);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    func_00175700(p);
    if (*(f32*)(p+0x38) <= *(f32*)(p+0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32*)(p+0x38) = *(f32*)(p+0x430);
        p[0x20D] = 0;
        *(u32*)a = 0;
        *(u32*)b = 0;
        func_001757E0(p, 2, 3);
    }
}

void func_002AE250(u8 *p) {
    extern void func_00175700(); extern void func_001830D0();
    f32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8*)(p+0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s8*)(p+0x151) = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0; *(u32*)((u8*)v+4) = 0x4322DB6D; v[2] = 0;
        func_001830D0(p, v, 3);
    }
}

extern f32 D_004F1F4C, D_004F1FE8;
void func_002BCE90(u8 *p, f32 *q) {
    extern s32 func_00175700(); extern void func_002BD2D0(); extern void func_002BCF40();
    *(f32*)(p+0x34) = D_004F1F4C - q[1];
    *(f32*)(p+0x38) = D_004F1FE8 - q[2];
    if (*(f32*)(p+0x38) <= *(f32*)(p+0x430)) *(f32*)(p+0x38) = *(f32*)(p+0x430);
    if ((s8)func_00175700(p) < 0) {
        if (*(s16*)(p+0x274) == 0) { func_002BD2D0(p, q); return; }
        func_002BCF40(p, q);
        p[7] = 0;
    }
}

void func_002C18F0(u8 *p) {
    extern void func_00175700(); extern void func_001E3710(); extern void func_001757E0();
    s16 v;
    func_00175700(p);
    if (*(s8*)(p+0x150) != 0) { *(s8*)(p+0x150) = 0; func_001E3710(p, 0x16); }
    v = *(s16*)(p+0x1E) - 1;
    *(s16*)(p+0x1E) = v;
    if (v <= 0 || *(f32*)(p+0x38) <= *(f32*)(p+0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32*)(p+0x5C) = 0; *(u32*)(p+0x60) = 0; *(u32*)(p+0x68) = 0; *(u32*)(p+0x6C) = 0;
        func_001757E0(p, 0xB, 0xA);
    }
}

void func_002ED2C0(u8 *p) {
    extern void func_001757E0(); extern void func_0015D010(); extern void func_0018C6E0(void *);
    f32 v[3];
    if (p[0x22] & 1) {
        { u32 t = p[0x1E6]; p[0x1E6] = t ^ 1; }
        *(s16*)(p+0x140) = p[0x1E6];
    }
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 3);
    *(u32*)(p+0x5C) = 0; *(u32*)(p+0x60) = 0; *(u32*)(p+0x68) = 0; *(u32*)(p+0x6C) = 0;
    *(u32*)&v[0] = 0xC2695555; *(u32*)&v[1] = 0x43070000; v[2] = 0;
    func_0015D010(p, v);
    func_0018C6E0(p);
}

void func_003362A0(u8 *p) {
    s32 v;
    s16 w;
    if (*(s16*)(p+0x1C) % 8 == 0) { u32 t = p[0x20]; p[0x20] = t ^ 1; }
    if (*(s16*)(p+0x140) != 0) {
        *(s32*)(p+0x44) = (*(s16*)(p+0x1E) != 0) ? 0x4000 : -0x4000;
    } else {
        *(s32*)(p+0x44) = (*(s16*)(p+0x1E) != 0) ? -0x4000 : 0x4000;
    }
    w = *(s16*)(p+0x1C) - 1;
    *(s16*)(p+0x1C) = w;
    if (w == 0) {
        u32 t = p[7]; p[7] = t + 1;
        *(s16*)(p+0x1C) = 10;
    } else {
        v = -0x16C;
        if (p[0x20] != 0) v = 0x16C;
        *(s32*)(p+0x44) = *(s32*)(p+0x44) + v;
    }
}

s32 func_003D83C0(u8 *p) {
    extern s32 func_003D8440(); extern s32 func_003D91E0(); extern s32 func_003D8540(); extern void func_003D86F0();
    s16 v = *(s16*)(p+0x12);
    if (v != 0) {
        v = v - 1;
        *(s16*)(p+0x12) = v;
        if (v <= 0) p[1] = 1;
    }
    if (func_003D8440(p) == 0) {
        if (func_003D91E0(p) != 0) return;
        func_003D8540(p);
    }
    func_003D86F0(p);
}

