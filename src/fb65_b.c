typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 b0; u8 pad[13]; } R7;
typedef struct { u8 pad0[0x12]; u16 h12; } T7;
typedef struct { u8 pad0[4]; u8 b4; u8 pad5[0x33]; f32 f38; } F7;
typedef struct E7 {
    s16 h0, h2, h4, h6;
    u8 b8, b9;
    s16 hA;
    u8 bC, bD;
    u8 pad0E;
    s8 b0F;
    f32 f10, f14;
    u8 pad18[0xC];
    R7 *w24;
    F7 *w28;
    f32 f2C;
    u8 pad30[3];
    u8 b33;
    u8 pad34;
    u8 b35;
} E7;
typedef struct N7 {
    u8 pad0[5];
    u8 b5;
    u8 pad6[2];
    struct N7 *w8;
    struct N7 *wC;
    u8 pad10[0x12];
    u8 b22;
    u8 pad23[0x11];
    f32 f34, f38;
    u8 pad3C[0x4C];
    s16 h88, h8A;
    u8 pad8C[0xB0];
    u8 b13C;
} N7;
typedef struct {
    u8 pad0[0x1C8];
    struct S7 *w1C8;
    u8 pad1CC[0x3E];
    u8 b20A;
} D7;
typedef struct S7 {
    u8 pad0[0x34];
    f32 f34;
    u8 pad38[0x119];
    s8 b151;
    u8 pad152[0x94];
    u8 b1E6;
    u8 pad1E7[0x1F5];
    u8 b1B5;
} S7;

extern R7 D_004734C0[];
extern u8 D_00473320[];
extern s16 D_00473220[][4];
extern u8 D_004C1F30[8];

void func_003ABB40(N7 *a, E7 *b) {
    extern void func_003AD110();
    extern void func_00126470();
    extern void func_00175580(N7 *, s32, s32, s32);
    extern void func_003ACCC0(N7 *, E7 *, F7 *, u8 *);
    extern void func_003AD320(u8 *, u8 *);
    extern void func_001E3A10(u8 *);
    extern void func_003AD3A0(N7 *, u8 *, u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_001266A0(u8 *, s32, s32);
    extern s32 fptosi(f32);
    E7 *s7;
    u8 *s1;
    N7 *s2;
    E7 *s3;
    s32 s4;
    s16 *t;
    R7 *r;
    N7 *s5;
    f32 f1, z;
    s1 = *(u8 **)((u8 *)a + 0x18);
    s1[0x201] = 3;
    s1[0x206] = 3;
    if (*(s8 *)(s1 + 0x151) >= 0) {
        r = &D_004734C0[*(s8 *)(s1 + 0x151)];
        b->w24 = r;
        func_003AD110(a, b, r);
        if (r->b0 >= 0) {
            func_00126470();
        }
    }
    s2 = a;
    s3 = b;
    s4 = 0;
    while (b->b0F >= s4) {
        u8 cur = s3->bC;
        u8 tgt = s2->b22;
        s32 d = (u8)(tgt - cur);
        s32 st = b->bD;
        u8 u;
        if (d != 0) {
            if ((s8)d < 0) {
                if ((u8)(-(s8)st) > (u8)d) cur = tgt + st;
            } else {
                if ((u8)st < (u8)d) cur = tgt - st;
            }
        }
        s2->b22 = cur;
        u = (((s2->b22 + 4) & 0xF8) / 8);
        func_00175580(s2, 0x1B, 1, u);
        *(u8 **)((u8 *)s2 + 0x164) = D_00473320;
        *(u8 **)((u8 *)s2 + 0x1D4) = *(u8 **)((u8 *)s2 + 0x17C) + (((T7 *)*(u8 **)((u8 *)s2 + 0x164))->h12 << 4);
        t = D_00473220[u];
        s3->h0 = fptosi(1.6666666269302368f * (f32)t[0]);
        s3->h2 = fptosi(2.142857074737549f * (f32)t[1]);
        s3->h4 = fptosi(1.6666666269302368f * (f32)t[2]);
        s3->h6 = fptosi(2.142857074737549f * (f32)t[3]);
        if (s4 == 0) {
            f32 f2 = s3->f10;
            f32 f3 = s3->f14;
            if (b->b35 != 0) {
                f2 -= (f32)s3->h4;
                f3 += (f32)s3->h6;
            }
            s3->f2C = f2;
            s2->f34 = f2;
            s2->f38 = f3;
        } else {
            s5 = s2->w8;
            f1 = s5->f34 + (f32)s5->h88 - (f32)s3->h4;
            s3->f2C = f1;
            s2->f34 = f1;
            s2->f38 = (f32)s3->h6 + (s5->f38 - (f32)s5->h8A);
        }
        s2->b13C = 1;
        s5 = s2;
        s2 = s2->wC;
        s7 = s3;
        s4++;
        s3 = (E7 *)((u8 *)s2 + 0x88);
    }
    func_003ACCC0(s5, s7, b->w28, s1);
    z = 0.0f;
    f1 = s5->f34 - s7->f2C;
    if (f1 != z) {
        N7 *p;
        s32 i;
        *(f32 *)(s1 + 0x34) += f1;
        p = a;
        for (i = 0; i < b->b0F; i++) {
            p->f34 += f1;
            s5 = p;
            p = p->wC;
        }
    }
    if (b->hA != 0) {
        D7 *d7;
        func_003AD320(s1, (u8 *)((u32)s1 + 0x2B8));
        if (s5->b22 != a->b22) {
            if (b->w28 == 0) return;
            if (!(b->w28->f38 <= *(f32 *)(s1 + 0x430))) return;
            func_001E3A10(*(u8 **)(s1 + 0x1DC));
            func_003AD3A0(a, s1, (u8 *)((s32)s1 + 0x2B8));
            if (a->b5 == 3) {
                func_001E3210(s1, 7);
                return;
            }
        }
        d7 = *(D7 **)(s1 + 0x1DC);
        d7->w1C8 = (S7 *)s1;
        if (s1[0x425] == 0) {
            d7->b20A = 1;
        } else {
            d7->b20A = 0x10;
        }
        *((u8 *)d7 + 0x1E6) = s1[0x1E6];
        *((u8 *)d7 + 0x1B5) = D_004C1F30[*(u16 *)(s1 + 0x2B8) / 2];
        func_001266A0(s1, 0xD, 6);
        a->b5 = 2;
        b->b9 = b->b0F;
        b->b8 = 0;
        b->hA = a->b22;
        b->b33 = 0;
        if (b->w28 != 0) {
            b->w28->b4 = 2;
            b->w28 = 0;
        }
    }
}
