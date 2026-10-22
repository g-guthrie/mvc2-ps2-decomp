typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p1[0x20]; f32 f5c, f60; f32 f64_, f68, f6c; u8 p3[0xE2]; u8 f152; } P1;
void func_002E8B70(P1 *p) {
    extern void func_00175700();
    f32 v;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    v = p->f60;
    if (v < 0.0f) v = -v;
    if (v >= 10.714285f) {
        p->f6c = 2.0f * -p->f6c;
    }
    p->f152 = 1;
    func_00175700(p);
}

void func_002511D0(u8 *p) {
    extern void func_00175700();
    extern void func_001E3210();
    extern void func_001830D0();
    f32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8*)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001E3210(p, 0x18);
        v[0] = 56.666664f;
        v[1] = 141.42857f;
        v[2] = 0.0f;
        func_001830D0(p, v, 1);
    }
}

void func_00261CE0(u8 *p) {
    extern void func_0015D010();
    extern void func_0018C6E0(void *);
    extern void func_001757E0();
    u32 v[4];
    if (*(u16*)(p + 0x20E) & 0x400) {
        p[0x1E6] = p[0x1E6] ^ 1;
        *(s16*)(p + 0x140) = *(s16*)(p + 0x140) ^ 1;
    }
    v[0] = 0xC2A6AAAA;
    v[1] = 0x431E9249;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    *(u32*)(p + 0x5C) = 0;
    *(u32*)(p + 0x68) = 0;
    *(f32*)(p + 0x60) /= 2.0f;
    *(u32*)(p + 0x6C) = 0xBF4DB6DB;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 1);
}

void func_001F1B40(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    p[0x206] = 3;
    if (*(s8*)(p + 0x151) != 0) p[0x151] = 0;
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(u32*)(p + 0x5C) = 0x40855555;
        *(u32*)(p + 0x68) = 0;
        *(u32*)(p + 0x60) = 0x41892492;
        *(u32*)(p + 0x6C) = 0xBF2B6DB6;
        if (p[0x1E6] != 0) {
            *(f32*)(p + 0x5C) = -*(f32*)(p + 0x5C);
        }
        func_001757E0(p, 0xF, 0xE);
    }
}

void func_002CA720(u8 *p) {
    extern s32 func_00175700();
    extern void func_001830D0();
    extern void func_001757E0();
    extern void func_001CEAE0();
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0x41555555;
        v[1] = 0x435EDB6D;
        v[2] = 0;
        func_001830D0(p, v, 1);
        func_001757E0(p, 0x15, 0x29);
        func_001CEAE0(p, 0xA);
    }
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p1[0x20]; f32 f5c, f60; u8 p2[4]; f32 f68, f6c; u8 p3[0x3C0]; f32 f430; } P2;
void func_00239B70(P2 *p) {
    extern void func_00175700();
    extern void func_001865B0();
    f32 z = 0.0f;
    f32 *q1, *q2;
    func_00175700(p);
    q1 = &p->f5c;
    q2 = &p->f68;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (!(p->f5c * p->f68 < z)) {
        *q1 = z;
        *q2 = z;
    }
    if (p->f38 <= p->f430) {
        p->f38 = p->f430;
        ((u8*)p)[0x20D] = 0;
        func_001865B0(p);
    }
}

void func_002B22F0(u8 *p) {
    extern void func_00178F20();
    extern void func_00179160(void *, void *);
    u8 *o;
    s32 a;
    f32 f;
    s8 *q;
    o = *(u8**)(p + 0x1DC);
    if (o[0x15B] > 0) {
        func_00178F20(o, p);
    } else {
        func_00179160(o, p);
    }
    if (p[0x20A] == 0) {
        o = *(u8**)(p + 0x1DC);
        q = (s8*)(o + 0x150);
        if (*(s8*)(o + 0x150) != 0) {
            *q = 0;
            f = 0.0f;
            o = *(u8**)(p + 0x1DC);
            a = *(s8*)(o + 0x161);
            if (a == 1) f = 1.0f;
            if (a == 2) f = -1.0f;
            if (*(s16*)(o + 0x140) == 0) f = -f;
            *(f32*)(p + 0x34) += f;
        }
    }
}

typedef struct { u8 p0[6]; u8 f6; u8 p0b[0x2D]; f32 f34, f38; u8 p1[0x20]; f32 f5c, f60; u8 p2[4]; f32 f68, f6c; u8 p3[0x3C0]; f32 f430; } P3;
void func_002EF090(P3 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    if (p->f38 <= p->f430) {
        u32 t = p->f6;
        p->f6 = t + 1;
        p->f38 = p->f430;
        p->f68 = -p->f5c / 8.0f;
        func_001757E0(p, 2, 3);
        func_00183d50(p);
    }
}

typedef struct { u8 p0[0x34]; f32 f34, f38; } O4;
typedef struct { u8 p0[6]; u8 f6; u8 p0b[0xD]; O4 *f14; u8 p0c[4]; s16 f1c; u8 p1[0x16]; f32 f34, f38; u8 p2[0x20]; f32 f5c, f60; u8 p3[8]; f32 f6c; u8 p4[0xD0]; s16 f140; } P5;
void func_00266880(P5 *p) {
    extern void func_001757E0();
    O4 *o = p->f14;
    f32 a;
    f32 k = 46.0f;
    u32 t = p->f6;
    p->f6 = t + 1;
    func_001757E0(p, 0x16, 7);
    *(u32*)&p->f60 = 0x41A2DB6D;
    *(u32*)&p->f6c = 0xBF676DB6;
    a = 53.333332061f;
    if (p->f140 != 0) a = -a;
    p->f5c = (o->f34 + a - p->f34) / k;
    p->f60 += (222.857131958f + o->f38 - p->f38) / k;
    p->f1c = 0x2E;
}

