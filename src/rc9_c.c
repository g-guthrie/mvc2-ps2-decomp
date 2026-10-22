typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f[16]; } M16;
typedef struct { s8 b0, b1, b2, b3; f32 f4; } Rec;
typedef struct { u8 pad[0x1C]; s32 *tab; } GT;
typedef struct { u8 pad[0x84]; GT *g; u8 pad88[0x44]; s16 h; u8 padCE[0x1E4 - 0xCE]; } OB;

extern GT *D_004C2834;
extern f32 *D_0043E3B0[];

void func_00134850(u8 *p) {
    extern void func_003DD260(f32 *);
    extern void func_003DDB60(f32 *, f32, f32, f32);
    extern void func_003DDB20(f32 *, f32, f32, f32);
    extern void func_003DE160(f32 *, f32 *, f32 *);
    extern void func_003DE3A0(f32 *, f32 *);
    extern void func_00123090();
    extern void func_00417A50(f32, f32, f32);
    extern void func_00170B70(GT *, s32, s32);
    extern void func_0011D8F8(void *, s32, s32);
    extern void func_001538B0(OB *, s32, f32 *);
    M16 m60, mA0, mE0, m120, m160, m1A0;
    OB o1, o2;
    Rec *r;
    s8 *q;
    s32 i;
    f32 *w2;
    f32 *w;
    f32 *t;

    if (*(s8 *)(p + 0x13C) == 0) return;
    r = *(Rec **)(p + 0xD8);
    if (r == 0) return;
    func_003DD260(mA0.f);
    func_003DDB60(mA0.f, *(f32 *)(p + 0x34), *(f32 *)(p + 0x38), *(f32 *)(p + 0x3C));
    *(f32 *)(p + 0x88) = mA0.f[0];
    *(f32 *)(p + 0x8C) = mA0.f[1];
    *(f32 *)(p + 0x90) = mA0.f[2];
    *(f32 *)(p + 0x94) = mA0.f[3];
    *(f32 *)(p + 0x98) = mA0.f[4];
    *(f32 *)(p + 0x9C) = mA0.f[5];
    *(f32 *)(p + 0xA0) = mA0.f[6];
    *(f32 *)(p + 0xA4) = mA0.f[7];
    *(f32 *)(p + 0xA8) = mA0.f[8];
    *(f32 *)(p + 0xAC) = mA0.f[9];
    *(f32 *)(p + 0xB0) = mA0.f[10];
    *(f32 *)(p + 0xB4) = mA0.f[11];
    *(f32 *)(p + 0xB8) = mA0.f[12];
    *(f32 *)(p + 0xBC) = mA0.f[13];
    *(f32 *)(p + 0xC0) = mA0.f[14];
    *(f32 *)(p + 0xC4) = mA0.f[15];
    func_00123090();
    for (i = 0; (s8)i < 2; i = (s8)(i + 1)) {
        w = m1A0.f;
        func_003DD260(w);
        m120.f[0] = *(f32 *)(p + 0x88);
        m120.f[1] = *(f32 *)(p + 0x8C);
        m120.f[2] = *(f32 *)(p + 0x90);
        m120.f[3] = *(f32 *)(p + 0x94);
        m120.f[4] = *(f32 *)(p + 0x98);
        m120.f[5] = *(f32 *)(p + 0x9C);
        m120.f[6] = *(f32 *)(p + 0xA0);
        m120.f[7] = *(f32 *)(p + 0xA4);
        m120.f[8] = *(f32 *)(p + 0xA8);
        m120.f[9] = *(f32 *)(p + 0xAC);
        m120.f[10] = *(f32 *)(p + 0xB0);
        m120.f[11] = *(f32 *)(p + 0xB4);
        m120.f[12] = *(f32 *)(p + 0xB8);
        m120.f[13] = *(f32 *)(p + 0xBC);
        m120.f[14] = *(f32 *)(p + 0xC0);
        m120.f[15] = *(f32 *)(p + 0xC4);
        if (i != 0) {
            r = *(Rec **)(p + 0xDC);
            w2 = m160.f;
            if (r == 0) break;
            func_003DD260(w2);
            func_003DDB60(w2, *(f32 *)(p + 0x64), -6.0f, 0.0f);
            func_003DE160(m120.f, w2, m120.f);
        }
        q = (s8 *)(p + 0x1B0);
        while (r->b0 >= 0) {
            func_003DD260(m60.f);
            func_003DD260(mE0.f);
            if (r->b2 != 0) {
                func_003DD260(mA0.f);
                t = D_0043E3B0[r->b2 & 7];
                func_003DDB20(mA0.f, t[0], t[1], t[2]);
                func_003DE160(mE0.f, mE0.f, mA0.f);
            }
            func_003DD260(mA0.f);
            func_003DDB60(mA0.f, r->f4, 0.0f, 0.0f);
            func_003DE160(mE0.f, mE0.f, mA0.f);
            func_003DE160(mE0.f, mE0.f, w);
            func_003DE3A0(w, mE0.f);
            func_003DE160(m60.f, mE0.f, m120.f);
            func_00417A50(1.0f, 1.0f, 1.0f);
            if (r->b1 >= 0) {
                if (*q >= 0) {
                    if (r->b0 > 0) func_00170B70(D_004C2834, *q, r->b0 - 1);
                    func_0011D8F8(&o1, 0, 0x1E4);
                    o1.h = *q;
                    o1.g = D_004C2834;
                    func_001538B0(&o1, D_004C2834->tab[*q], m60.f);
                }
                q++;
            } else {
                if (r->b0 > 0) func_00170B70(D_004C2834, r->b3, r->b0 - 1);
                func_0011D8F8(&o2, 0, 0x1E4);
                o2.h = r->b3;
                o2.g = D_004C2834;
                func_001538B0(&o2, D_004C2834->tab[r->b3], m60.f);
            }
            r = r + 1;
        }
    }
}
