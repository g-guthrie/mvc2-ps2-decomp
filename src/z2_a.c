typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001FF9D0(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_001266A0();
    extern void func_00185640();
    extern u8 *func_001E7FD0();
    u8 *o;
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, 0x10);
        return;
    }
    if ((o = func_001E7FD0(p)) != 0) {
        func_001266A0(p, 5, 5);
        p[0x20B] = 0xC1;
        func_00185640(p, o);
    }
}

typedef struct { f32 x, y, z; } V13D8;
extern V13D8 D_004B16A0[];
typedef struct { u8 pad0[0x1C]; s16 s1c; u8 pad1[2]; u8 i20; u8 pad2[0x13]; f32 f34, f38, f3c; } P13D8;
void func_0013D8E0(P13D8 *p)
{
    V13D8 *a = &D_004B16A0[p->i20 * 2];
    V13D8 *b = &D_004B16A0[p->i20 * 2 + 1];
    p->f34 = a->x + (f32)p->s1c * ((b->x - a->x) / 30.0f);
    p->f38 = a->y + (f32)p->s1c * ((b->y - a->y) / 30.0f);
    p->f3c = a->z + (f32)p->s1c * ((b->z - a->z) / 30.0f);
}

typedef struct { u8 pad0[6]; u8 b6; u8 pad1[0x15]; s16 s1c; s16 s1e; u8 pad2[0x14]; f32 f34, f38; u8 pad3[0x20]; f32 f5c, f60; u8 pad4[4]; f32 f68, f6c; } P2E2070;
void func_002E2070(P2E2070 *p)
{
    extern void func_001D36E0();
    extern void func_00175700();
    extern void func_001757E0();
    s16 v = p->s1e - 1;
    p->s1e = v;
    if (v < 0) {
        p->s1e = 4;
        func_001D36E0(p, 1);
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    v = p->s1c - 1;
    p->s1c = v;
    if (v < 0) {
        u32 t = p->b6;
        p->b6 = t + 1;
        func_001757E0(p, 2, 3);
    }
}

typedef struct { u8 pad0[7]; u8 b7; u8 pad1[0x2C]; f32 f34; u8 pad2[0x108]; s16 s140; u8 pad3[0xE]; s8 b150; s8 b151; u8 pad4[0x94]; s8 b1e6; } P1F4E20;
void func_001F4E20(P1F4E20 *p)
{
    extern s8 func_00175700();
    extern void func_001757E0();
    if (func_00175700(p) < 0) {
        u32 t = p->b7;
        p->b7 = t + 1;
        func_001757E0(p, 0xF, 0x3C);
        return;
    }
    if (p->b151) {
        p->b151 = 0;
        p->s140 = p->s140 ^ 1;
        p->b1e6 = p->s140;
    }
    if (p->b150) {
        p->b150 = 0;
        if (p->s140) {
            p->f34 += 160.0f;
        } else {
            p->f34 -= 160.0f;
        }
    }
}

typedef struct { f32 x, y, z; } V18FDE0;
void func_0018FDE0(u8 *p)
{
    extern void func_0018F730();
    extern void func_0018DC10();
    extern void func_00186A60();
    u32 i;
    s16 v = *(s16 *)(p + 0x434);
    *(s16 *)(p + 0x290) = v;
    *(s16 *)(p + 0x27C) = v;
    *(s16 *)(p + 0x342) = 0;
    p[0x1B6] = p[0x1B5];
    *(u8 **)(p + 0x1CC) = p;
    p[0x1BA] = *(s8 *)(p + 0x140) ^ 1;
    p[0x1B9] = *(s8 *)(p + 0x140);
    i = p[0x1B6] & 0x7F;
    *(u8 **)(p + 0x1D0) = *(u8 **)(p + 0x184) + i * 28;
    func_0018F730(p, i);
    func_0018DC10(p, p);
    p[0x24A] = 0;
    p[5] = 3;
    p[7] = 0;
    p[6] = 0;
    p[0x24C] = 0;
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V18FDE0 *)(p + 0x50) = *(V18FDE0 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_00186A60(p, 0x20);
}

void func_001ED2E0(u8 *p)
{
    extern void func_001266A0();
    extern void func_0015D010();
    extern void func_0018C6E0();
    extern void func_001757E0();
    u32 v[4];
    { u32 t = p[0x1E6]; p[0x1E6] = t ^ 1; }
    *(s16 *)(p + 0x140) = p[0x1E6];
    if ((p[0x22] & 2) == 0) {
        { u32 t = p[0x1E6]; p[0x1E6] = t ^ 1; }
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    v[0] = 0xC2A6AAAA;
    v[1] = 0x431E9249;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x60) / 2.0f;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 2);
}

typedef struct { u8 pad0[6]; u8 b6; u8 pad1[0x15]; s16 s1c; } P176FA0;
void func_00176FA0(u8 *p)
{
    extern void func_0018F4C0();
    extern void func_00175700();
    extern void func_00184540();
    extern void func_001843A0();
    u8 *q;
    s16 v;
    if (p[6] == 0) {
        p[6] = p[6] + 1;
        *(s16 *)(p + 0x1C) = 0x3C;
    }
    q = *(u8 **)(p + 0x1CC);
    if (q == 0) {
        q = *(u8 **)(p + 0x220);
    }
    if (q[5] == 3) {
        func_0018F4C0(p);
        return;
    }
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        if (*(s16 *)(p + 0x434) == 0) {
            func_0018F4C0(p);
        } else if (p[0x20D] == 2) {
            func_00184540(p);
        } else {
            func_001843A0(p);
        }
    }
}

typedef struct { u8 pad0[6]; u8 b6; u8 pad1[0x17]; s16 s1e; u8 pad2[0x14]; f32 f34, f38; u8 pad3[0x20]; f32 f5c, f60; u8 pad4[4]; f32 f68, f6c; } P1ECCE0;
void func_001ECCE0(u8 *p)
{
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    extern void func_001ECF90();
    ((void)0);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        if (*(s16 *)(p + 0x1E) == 0) {
            func_001757E0(p, 0x16, 0xC);
        } else {
            func_001757E0(p, 0x16, 0xF);
        }
        func_00183d50(p);
    }
    func_001ECF90(p);
}

void func_002C97C0(u8 *p, u8 *q)
{
    extern void func_00175C00();
    extern s8 func_00175700();
    extern void func_001830D0();
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (*(s8 *)(p + 0x161)) {
        q[4] = 1;
    }
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_00175C00(p, 0);
    }
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0xC2BAAAAA;
        v[1] = 0x432B6DB6;
        v[2] = 0;
        func_001830D0(p, v, 1);
        p[0x201] = 10;
    }
}

extern u8 D_004D18EC;
s32 func_001648E0(u8 *p)
{
    s8 c;
    s32 a1, m, sh;
    u8 *q;
    f32 d, tgt, me, diff;
    if (p[0x1E4] == *(s32 *)(p + 0x464)) {
        c = *(s8 *)(p + 0x4B6) - 1;
        *(s8 *)(p + 0x4B6) = c;
        if (c != 0 && D_004D18EC == 0) {
            sh = 2 >> p[0x1E6];
            m = *(s32 *)(p + 0x468);
            a1 = *(s8 *)(p + 0x211);
            if (m & 0x400) sh ^= 3;
            if (a1 == 0 || (a1 & sh) == 0) {
                q = *(u8 **)(p + 0x220);
                d = *(f32 *)(p + 0x460);
                if (q[0x1E6] == 0) d = -d;
                tgt = d + *(f32 *)(q + 0x34);
                me = *(f32 *)(p + 0x34);
                {
                f32 x = me, y = tgt;
                if (*(s32 *)(p + 0x46C) != 0) { x = tgt; y = me; }
                diff = x - y;
                }
                if (!(diff <= 0.0f)) {
                    *(s16 *)(p + 0x4F0) = m;
                    return 0;
                }
            }
        }
    }
    { u32 t = p[0x451]; p[0x451] = t - 1; }
    *(s16 *)(p + 0x4F0) = 0;
    return 1;
}

void func_00235E40(u8 *p)
{
    extern void func_001865B0();
    extern void func_00175700();
    extern void func_0018C4B0();
    extern void func_0035B500();
    s32 f = 0;
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        f = 1;
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            func_001865B0(p);
            return;
        }
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 1) {
        u32 t = p[6];
        p[6] = t + 1;
        func_0018C4B0(p, 5);
        func_0035B500(p, f);
    }
}

typedef struct { u8 pad0[6]; u8 b6, b7; u8 pad1[0x14]; s16 s1c; u8 pad2[0x1A]; f32 f38; u8 pad3[0x20]; f32 f5c, f60; u8 pad4[4]; f32 f68, f6c; u8 pad5[0xE0]; s8 b150; u8 pad6[0x167]; u8 b2b8[0x10]; } P1FFFB0;
void func_001FFFB0(P1FFFB0 *p)
{
    extern void func_00175C00();
    extern void func_001757E0();
    extern void func_00175700();
    u8 *q;
    s16 v;
    f32 z;
    p->b2b8[0xC] = 7;
    v = p->s1c - 1;
    p->s1c = v;
    q = p->b2b8;
    if (v == 0) {
        q[0xC] = 0;
        func_00175C00(p, 0);
        *(u32 *)&p->f5c = 0;
        *(u32 *)&p->f60 = 0;
        *(u32 *)&p->f68 = 0;
        *(u32 *)&p->f6c = 0;
        *(u32 *)&p->f6c = 0xBF4DB6DB;
        {
            u32 t = p->b6;
            p->b6 = t + 1;
        }
        p->b7 = 0;
        func_001757E0(p, 1, 9);
        return;
    }
    if (p->b150 == 0) {
        p->f38 += p->f60;
        p->f60 += p->f6c;
    }
    z = 0.0f;
    if (p->f60 < z) {
        p->f60 = z;
        p->f6c = z;
    }
    func_00175700(p);
}

typedef struct { u8 pad0[5]; u8 b5; u8 pad1[0x16]; s16 s1c; s16 s1e; u8 pad2[1]; u8 b21; } P3B3270;
void func_003B3270(P3B3270 *p)
{
    extern void func_00175700();
    extern f32 func_003DE770(f32);
    extern s32 func_00118FA8(f32);
    extern void func_003B2F10(P3B3270 *, s32, u8, s16, u8);
    extern void func_001E3710();
    s16 v;
    s32 i;
    s16 r;
    func_00175700(p);
    v = p->s1c - 1;
    p->s1c = v;
    if (v == 0) {
        u32 t = p->b5;
        p->b5 = t + 1;
        p->b21 = 7;
        p->s1e = 0;
        r = func_00118FA8(func_003DE770(-170.0f));
        i = 0;
        do {
            func_003B2F10(p, 1, p->b21, r, p->s1e);
            r = func_00118FA8((f32)r - 50.0f);
            i++;
            p->s1e = p->s1e + 1;
            p->s1e = p->s1e & 3;
        } while (i < 6);
        p->b21 = 0;
        func_001E3710(p, 0x48);
    }
}

typedef struct { u8 pad0[4]; u8 b4; u8 b5; u8 pad1[0x1A]; u8 b20; u8 pad2[0x13]; f32 f34, f38; u8 pad3[0x20]; f32 f5c, f60; u8 pad4[4]; f32 f68, f6c; u8 pad5[0xCC]; s16 s140; } P19B920;
extern f32 D_004F1F4C;
void func_0019B920(u8 *p)
{
    extern s8 func_00175700();
    u8 *o = *(u8 **)(p + 0x18);
    if (p[0x20] != 0 && (o[5] != 0 || o[0x1E4] != 0x1D)) {
        p[0x13C] = 0;
        p[4] = 3;
        return;
    }
    *(f32 *)(p + 0x34) = D_004F1F4C + *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x60);
    *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
    if (func_00175700(p) < 0) {
        p[0x13C] = 0;
        p[4] = 3;
        return;
    }
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x151] = 0;
        o[0x2C5] = 1;
        *(s16 *)(o + 0x140) = *(s16 *)(p + 0x140);
        o[0x1E6] = *(s8 *)(p + 0x140);
        *(u32 *)(o + 0x5C) = 0;
        *(u32 *)(o + 0x60) = 0;
        *(u32 *)(o + 0x68) = 0;
        *(u32 *)(o + 0x6C) = 0;
    }
}

typedef struct { f32 x, y, z; } V122670;
void func_00122670(V122670 *v, f32 *len, s32 *a, s32 *b)
{
    extern f32 func_00117430(f32);
    extern s32 func_00417690(f32, f32);
    f32 zero = 0.0f;
    f32 r;
    *len = v->x * v->x + v->z * v->z;
    r = func_00117430(*len);
    if (zero == r && zero == v->y) {
        *a = 0;
    } else {
        *a = func_00417690(r, v->y);
    }
    *len = func_00117430(*len + v->y * v->y);
    if (zero == v->x && zero == v->z) {
        *b = 0;
    } else {
        *b = func_00417690(v->x, v->z);
    }
}

typedef struct { u8 pad0[6]; u8 b6; u8 pad1[0x2D]; f32 f34, f38; u8 pad3[0x20]; f32 f5c, f60; u8 pad4[4]; f32 f68, f6c; } P276A80;
static s32 func_00275A40(P276A80 *p)
{
    u8 *bytes = (u8 *)p;
    if (p->f38 < *(f32 *)(bytes + 0x430)) {
        *(s32 *)(bytes + 92) = 0;
        *(s32 *)(bytes + 96) = 0;
        *(s32 *)(bytes + 104) = 0;
        *(s32 *)(bytes + 108) = 0;
        p->f38 = *(f32 *)(bytes + 0x430);
        return 1;
    }
    return 0;
}
void func_00276A80(P276A80 *p)
{
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_001B9AC0();
    extern void func_00379850();
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00275A40(p);
    if (func_00175700(p) < 0) {
        u8 *q = (u8 *)p;
        u32 t = q[6];
        q[6] = t + 1;
        if (q[0x20D] == 2) {
            func_001757E0(p, 0x15, 8);
            func_001B9AC0(p, 1);
        } else {
            func_001757E0(p, 0x15, 4);
            func_001B9AC0(p, 0);
        }
        func_00379850(p);
        *(s16 *)(q + 0x1E) = (q[0x1B7] != 0) ? 0x28 : 0xE;
        q[0x28E] = 0x10;
        q[0x28F] = 0;
    }
}

extern u8 D_00459530[], D_00459534[], D_00459538[], D_0045953C[];
void func_002BC120(u8 *p)
{
    extern void func_00175700();
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? *(f32 *)(D_00459530 + (p[0x1B7] << 4)) : -*(f32 *)(D_00459530 + (p[0x1B7] << 4));
        *(f32 *)(p + 0x68) = p[0x1E6] ? *(f32 *)(D_00459534 + (p[0x1B7] << 4)) : -*(f32 *)(D_00459534 + (p[0x1B7] << 4));
        *(f32 *)(p + 0x60) = *(f32 *)(D_00459538 + (p[0x1B7] << 4));
        *(f32 *)(p + 0x6C) = *(f32 *)(D_0045953C + (p[0x1B7] << 4));
    }
}

typedef struct { u8 pad0[6]; u8 b6; u8 pad1[0x2D]; f32 f34, f38; u8 pad3[0x20]; f32 f5c, f60; u8 pad4[4]; f32 f68, f6c; u8 pad5[0xF1]; s8 b161; u8 pad6[0xAB]; u8 b20d; u8 pad7[0x222]; f32 f430; } P2A9FA0;
void func_002A9FA0(P2A9FA0 *p)
{
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *a, *b, *c, *d;
    d = &p->f6c;
    c = &p->f68;
    b = &p->f60;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    a = &p->f5c;
    if (p->b161 >= 0) {
        func_00175700(p);
    }
    if (p->f38 <= p->f430) {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->f38 = p->f430;
        p->b20d = 0;
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        *(u32 *)c = 0;
        *(u32 *)d = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 6);
    }
}

typedef struct { u8 pad0[0x168]; u16 h168; u8 pad1[0x1B8 - 0x16A]; } PA19F0F0;
extern u8 D_004D18A6[];
void func_0019F0F0(u8 *p, u16 *q)
{
    extern void func_001757E0();
    extern void func_00175700();
    u8 *o = *(u8 **)(p + 0x18);
    u8 *r;
    p[0x13C] = 0;
    r = o + 0x2B8;
    if (*(u16 *)(o + 0x168) != q[0]) {
        if (p[0x21] != 0) {
            u32 t = p[4];
            p[4] = t + 1;
        } else {
            u32 t = p[5];
            p[5] = t + 1;
            p[0x13C] = 1;
            func_001757E0(p, 0x17, 0x2B);
        }
    } else {
        if (*(s8 *)(o + 0x151) != 0) {
            *(s16 *)(p + 0x140) = *(s16 *)(o + 0x140);
            *(s8 *)(p + 0x31) = -2;
            if (p[0x21] != 0) {
                p[0x31] = *(s8 *)(p + 0x31) - 3;
            }
            *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
            *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
            if (D_004D18A6[0] == 0) {
                func_00175700(p);
            }
            if (*(s8 *)(p + 0x150) == 0) {
                if (p[0x21] != 0) {
                    if (r[0xE] != 0) return;
                }
                p[0x13C] = 1;
            }
        }
    }
}
