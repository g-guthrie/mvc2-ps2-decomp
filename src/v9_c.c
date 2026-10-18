typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;typedef float f32;
typedef struct { u32 a, b; f32 f; s32 c; } E;
extern E D_004771D0[4];
extern u8 D_004F7F52;

void func_002D0280(u8 *p) {
    extern s8 func_00175700(); extern void func_001843A0(); extern void func_00183920();
    f32 v[4];
    if (func_00175700(p) < 0) { func_001843A0(p); return; }
    if (*(s8*)(p+0x151) < 0) {
        p[0x151] = 0;
        *(u32*)&v[0] = 0xC2C15555;
        *(u32*)&v[1] = 0x43009249;
        func_00183920(p, v);
    }
    if (*(s8*)(p+0x150) != 0) {
        *(f32*)(p+0x34) += (p[0x1E6] != 0) ? 3.3333333f : -3.3333333f;
    }
}

void func_003D3A90(void) {
    extern void func_00123090(); extern void func_00417AE0();
    u8 t = D_004F7F52;
    E *e = D_004771D0;
    s32 c = (t + 0x60) << 24;
    f32 f = t ? 0.7 : 0.99;
    e[0].c = c; e[0].f = f;
    e[1].c = c; e[1].f = f;
    e[2].c = c; e[2].f = f;
    e[3].c = c; e[3].f = f;
    func_00123090();
    func_00417AE0(4, e);
}

void func_0027D950(u8 *p) {
    extern void func_00175700();
    f32 *a0, *a1, *a2, *a3;
    func_00175700(p);
    a0 = (f32*)(p+0x5C); a2 = (f32*)(p+0x68); a1 = (f32*)(p+0x60); a3 = (f32*)(p+0x6C);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (*(s8*)(p+0x151) != 0) {
        p[6]++;
        *a0 = 0;
        *a1 = 0;
        *a2 = 0;
        *a3 = 0;
        *(f32*)(p+0x5C) = (p[0x1E6] != 0) ? 1.6666666f : -1.6666666f;
    }
}

void func_00211BF0(u8 *p) {
    extern void func_00175700();
    f32 *a0, *a1, *a2, *a3;
    func_00175700(p);
    a0 = (f32*)(p+0x5C); a2 = (f32*)(p+0x68); a1 = (f32*)(p+0x60); a3 = (f32*)(p+0x6C);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (*(s8*)(p+0x151) != 0) {
        p[6]++;
        *a0 = 0;
        *a1 = 0;
        *a2 = 0;
        *a3 = 0;
        *(f32*)(p+0x5C) = (p[0x1E6] != 0) ? 1.6666666f : -1.6666666f;
    }
}
