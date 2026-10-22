typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_0015D010(void *p, f32 *v);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_001E3210(void *p, s32 a);
extern void func_001E3710(void *p, s32 a);
extern void func_001266A0(s32 a, s32 b, s32 c);
extern void func_0018C6E0(void *);

void func_002024A0(u8 *p) {
    f32 v[3];
    p[0x1B4] = 10;
    p[6] = 0;
    v[0] = -53.33333206f;
    v[1] = 137.1428528f;
    func_0015D010(p, v);
    func_001757E0(p, 15, 1);
}

extern u8 *func_003DA750(void *p, s32 b, s32 c);
extern void func_003CCFE0();

void func_003CA780(u8 *p) {
    u8 *o = func_003DA750(0, 1, 1);
    if (o != 0) {
        *(void **)(o + 0x10) = (void *)func_003CCFE0;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        *(u16 *)(o + 0x26) = 0x3A01;
        *(s16 *)(o + 0x1E) = 0x27;
        o[0x13C] = 0;
    }
}

extern void func_0039E450();
extern void func_0039DAC0();

void func_0039DA50(u8 *p) {
    s8 *sb = (s8 *)p;
    u8 *q = *(u8 **)(p + 0x18);
    s16 v = *(s16 *)(q + 0x1E) - 1;
    *(s16 *)(q + 0x1E) = v;
    if (sb[0x1B3] == 0 && (sb[0x1B2] == 0 || (((sb[0x1B2] << 24) >> 24) & 1) == 0)) {
        func_0039E450();
    } else {
        func_0039DAC0();
    }
}

void func_002A5D80(u8 *p) {
    f32 v[3];
    func_001266A0((s32)p, 5, 5);
    func_0018C6E0(p);
    p[0x1B4] = 10;
    v[0] = -80.0f;
    v[1] = 128.5714264f;
    v[2] = 0.0f;
    func_0015D010(p, v);
    func_001757E0(p, 15, 2);
}

extern s32 func_00175700(void *p);
extern void func_002CEC90(void *p);
extern void func_00186A20();

void func_002CF010(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_002CEC90(p);
    if ((s8)p[0x151] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00186A20();
    }
}

extern void func_002848D0(void *p);

void func_00284650(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (((s8 *)p)[0x151] & 1) {
        u32 t = p[6];
        f32 v;
        p[6] = t + 1;
        if (p[0x1E6] != 0) {
            v = -40.0f;
        } else {
            v = 40.0f;
        }
        *(f32 *)(p + 0x34) += v;
        p[0x20D] = 2;
    }
    func_002848D0(p);
}

extern void func_00183210();

void func_00314AB0(u8 *p) {
    f32 v[3];
    u32 t;
    p[0x33C] = 5;
    func_00175700(p);
    if (((s8 *)p)[0x151] != 0) {
        p[0x151] = 0;
        t = p[6];
        p[6] = t + 1;
        v[0] = 8.333333015f;
        v[1] = 199.2857056f;
        func_00183210(p, v, 0, t + 1);
        *(s16 *)(p + 0x1C) = 0x10;
        func_001E3210(p, 0x1D);
        func_001E3710(p, 0x50);
    }
}

extern void func_00131AB0(void *p, void *q, s32 a, s32 b);

void func_002FE960(u8 *p, u8 *q) {
    f32 v[3];
    u32 t;
    s16 *r;
    func_00175700(p);
    if (((s8 *)p)[0x151] != 0) {
        r = (s16 *)(q + 4);
        t = p[6];
        p[6] = t + 1;
        p[0x216] = 1;
        *r = 0x258;
        q[3] = 0;
        func_00131AB0(p, r, 7, t + 1);
        v[0] = -21.66666603f;
        v[1] = 210.0f;
        v[2] = 0.0f;
        func_00183210(p, v, 1);
    }
}

extern void func_001830D0();

void func_002DA990(u8 *p) {
    f32 v[3];
    u8 v2;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (p[0x269] == 6) {
        v2 = 2;
    } else {
        v2 = 0;
    }
    p[0x405] = v2;
    func_00175700(p);
    if (((s8 *)p)[0x151] != 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        v[0] = 0.0f;
        v[1] = 210.0f;
        func_001830D0(p, v, 1);
    }
}

extern void func_0022C6B0();
extern void func_0022C5D0(void *p);

void func_00228CB0(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) {
        func_00175700(p);
    } else {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_0022C6B0();
        func_0022C5D0(p);
    }
}

extern void func_0019BE70();

void func_0019BDD0(u8 *p) {
    s8 i;
    u8 *o;
    for (i = 0; i <= 8; i++) {
        o = func_003DA750(0, 3, 0);
        if (o != 0) {
            *(void **)(o + 0x10) = (void *)func_0019BE70;
            *(u8 **)(o + 0x18) = p;
            *(u16 *)(o + 0x26) = 0x900;
            o[0x20] = i;
            o[0x21] = 7;
            *(s16 *)(o + 0x1C) = 0x20;
            *(s16 *)(o + 0x1E) = 0x76;
        }
    }
}

extern void func_00185490(void *p);
extern void func_001843A0(void *p);

void func_001ED480(u8 *p) {
    u8 *q;
    s8 r;
    if (((s8 *)p)[0x151] != 0) {
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        func_001266A0((s32)p, 0, 0);
        q[0x1B5] = 0x21;
        q[0x1E6] = p[0x1E6];
        p[0x1E6] = ((s8 *)p)[0x1E6] ^ 1;
    }
    r = func_00175700(p);
    if (r < 0) {
        func_00185490(p);
        func_001843A0(p);
    }
}

extern void func_00217D20(void *p);

void func_00217C80(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00217D20(p);
    }
}

void func_00221440(u8 *p) {
    s8 a = -8;
    s8 b = -4;
    u8 *q = *(u8 **)(p + 0x220);
    s8 c;
    if (q[0x1E6] == 0) {
        if (!(*(f32 *)(p + 0x34) < *(f32 *)(q + 0x34))) {
            a = 8;
            b = 4;
        }
    } else {
        if (*(f32 *)(p + 0x34) <= *(f32 *)(q + 0x34)) {
            a = 8;
            b = 4;
        }
    }
    c = a + 0x10;
    if (*(f32 *)(q + 0x38) <= 102.8571396f + *(f32 *)(p + 0x38)) {
        c = c + b;
    }
    p[0x22] = c;
}

void func_001F9DE0(u8 *p) {
    f32 v[3];
    u8 v2;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (p[0x269] == 6) {
        v2 = 2;
    } else {
        v2 = 0;
    }
    p[0x405] = v2;
    func_00175700(p);
    if (((s8 *)p)[0x151] != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = -66.66666412f;
        v[1] = 57.85713959f;
        func_001830D0(p, v, 1, t + 1);
    }
}

void func_002DEA20(u8 *p) {
    f32 v[3];
    u8 v2;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (p[0x269] == 6) {
        v2 = 2;
    } else {
        v2 = 0;
    }
    p[0x405] = v2;
    func_00175700(p);
    if (((s8 *)p)[0x151] != 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[7];
        p[7] = t + 1;
        v[0] = 0.0f;
        v[1] = 205.7142792f;
        func_001830D0(p, v, 1);
    }
}
