typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0016C9B0(u8 *p) {
    *(f32 *)(p + 0x108) -= 0.00052083336f;
    *(f32 *)(p + 0x110) -= 0.00052083336f;
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1C) = 0xF0;
        }
    }
}

void func_003739E0(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
}

extern void func_004177A0(s32, f32, f32, f32);
extern void func_00414A40();
extern void func_00416AB0();
extern void func_004171E0();
void func_001433D0(void) {
    f32 c = 12000.0f, a = 1.0f, b = 0.100000001f;
    func_00414A40();
    func_00416AB0(3);
    func_004171E0();
    func_004177A0(0x975, a, b, c);
    func_00416AB0(1);
}

void func_0015F240(u8 *p) {
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v != 0) {
        *(f32 *)(p + 0x54) += 0.150000006f;
    } else {
        u32 t;
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.5f;
        t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1E) = 10;
    }
}

extern s16 D_004520C0[][2];
void func_00238B70(u8 *p, f32 *q) {
    s32 i = *(s8 *)(p + 0x151);
    s16 *e = D_004520C0[i];
    f32 a = 1.66666663f * e[0];
    f32 b = 2.14285707f * e[1];
    if (p[0x1E6] != 0) a = -a;
    q[9] = a;
    q[10] = b;
}

extern void func_0018F1A0();
void func_0018F130(u8 *p, s32 q) {
    u8 *o = *(u8 **)(p + 0x1DC);
    f32 v[2];
    func_0018F1A0(p[0x242], q, v);
    if (o[0x1E6] != 0) v[0] = -v[0];
    *(f32 *)(p + 0x22C) = v[0];
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x230) = v[1];
    *(f32 *)(p + 0x6C) = -0.803571403f;
}

extern void func_0015D010();
extern void func_001266A0();
extern void func_0018C6E0();
extern void func_001757E0();
void func_0025B760(u8 *p) {
    f32 v[3];
    v[0] = -83.3333282f;
    v[1] = 158.571426f;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_001266A0(p, 5, 5);
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 3);
}

extern s32 func_00175700();
extern void func_00175C00();
extern void func_00183920();
void func_002F1100(u8 *p) {
    f32 v[3];
    func_00175700();
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00175C00(p, 1);
        *(u32 *)(p + 0x2B8) = 0;
        v[0] = 46.6666641f;
        v[1] = 162.857132f;
        func_00183920(p, v);
    }
}

extern s32 func_00175700();
extern void func_0022C5D0();
void func_002270E0(u8 *p) {
    if ((s8)func_00175700() < 0) {
        func_0022C5D0(p);
    } else if (*(s8 *)(p + 0x151) != 0) {
        f32 d;
        p[0x151] = 0;
        d = 53.3333321f;
        if (p[0x1E6] == 0) d = -d;
        *(f32 *)(p + 0x34) += d;
    }
}

