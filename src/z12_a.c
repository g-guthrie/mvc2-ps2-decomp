typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[2]; u8 b2; u8 p3; u8 b4; u8 b5; u8 b6; u8 b7; u8 p8[0x1C-8]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PH;

void func_00153590(void) {
    extern void func_001534D0(s32);
    func_001534D0(10);
    func_001534D0(55);
    func_001534D0(56);
    func_001534D0(57);
    func_001534D0(58);
    func_001534D0(59);
    func_001534D0(60);
    func_001534D0(61);
    func_001534D0(62);
    func_001534D0(63);
    func_001534D0(65);
    func_001534D0(66);
    func_001534D0(67);
    func_001534D0(68);
    func_001534D0(69);
    func_001534D0(70);
    func_001534D0(71);
    func_001534D0(72);
    func_001534D0(73);
    func_001534D0(74);
    func_001534D0(75);
    func_001534D0(76);
    func_001534D0(77);
    func_001534D0(78);
    func_001534D0(79);
}

typedef struct { u8 pad0[4]; u8 b4; u8 b5; u8 b6; u8 pad7[0x34-7]; f32 f34; f32 f38; u8 pad3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; } F1;
void func_00316260(F1 *p) {
    extern void func_00175700();
    extern void func_001757E0(F1 *, s32, s32);
    extern void func_00183D50(F1 *);
    f32 m;
    f32 *v1, *a2, *a3, *t0;
    ((u8 *)p)[0x209] = 1;
    func_00175700(p);
    if (((s8 *)p)[0x151] == 0) {
        v1 = &p->f5c;
        a3 = &p->f68;
        a2 = &p->f60;
        t0 = &p->f6c;
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        m = *(f32 *)((u8 *)p + 0x430);
        if (!(m < p->f38)) {
            p->f38 = m;
            *v1 = 0;
            *a2 = 0;
            *a3 = 0;
            *t0 = 0;
            func_001757E0(p, 0xF, 0x10);
            func_00183D50(p);
            p->b6++;
        }
    }
}

void func_003CC8D0(PH *p, u8 *q) {
    extern s8 func_00175700();
    extern void func_001757E0(PH *, s32, s32);
    extern void func_003CAB20(PH *, u8 *, s32);
    if (p->b6 == 0) {
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
        func_00175700(p);
        if (p->f38 < *(f32 *)(q + 0x430)) {
            p->b6++;
            p->f38 = *(f32 *)(q + 0x430);
            func_001757E0(p, 1, 3);
            return;
        }
    } else {
        if (func_00175700(p) < 0) {
            func_003CAB20(p, q, p->b7);
        }
    }
}

typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } QL;
void func_001CA620(PH *p) {
    extern void func_001CA9F0();
    extern void func_001CADB0();
    extern void func_001CAC90(PH *);
    extern void func_001CABF0(PH *);
    QL *q;
    s16 v;
    q = *(QL **)((u8 *)p + 0x18);
    if (p->b5 == 2) {
        func_001CA9F0();
        return;
    }
    if (p->b5 == 0) {
        p->b5++;
        p->b6 = 1;
        func_001CADB0();
        func_001CAC90(p);
        p->h1c = 7;
    }
    p->f34 += ((p->f5c + q->f34) - p->f34) / 8.0f;
    p->f38 += ((p->f60 + q->f38) - p->f38) / 8.0f;
    v = p->h1c - 1;
    p->h1c = v;
    if (v < 0) p->b5++;
    func_001CABF0(p);
}

void func_001FFBA0(PH *p) {
    extern s8 func_00175700(PH *);
    extern void func_00193430(PH *);
    extern void func_001830D0(PH *, u32 *, s32);
    extern void func_001757E0(PH *, s32, s32);
    u8 *r;
    u32 v[3];
    ((u8 *)p)[0x40C] = 2;
    ((u8 *)p)[0x33C] = 5;
    r = (u8 *)p + 0x2B8;
    ((u8 *)p)[0x405] = (((u8 *)p)[0x269] == 6) ? 2 : 0;
    r[0x12] = 6;
    if (func_00175700(p) < 0) {
        ((u8 *)p)[0x404] = 0;
        *(u8 *)((s32)p + 0x405) = 0;
        p->b6++;
        r[0x14] = 10;
        ((u8 *)p)[0x404] = 0xFF;
        *(u8 *)((s32)p + 0x405) = 0x10;
        p->h1c = 0x2C;
        func_00193430(p);
        v[0] = 0xC1555555;
        v[1] = 0x42DEDB6D;
        func_001830D0(p, v, 1);
        func_001757E0(p, 0x16, 0x1A);
    }
}

typedef struct { f32 a, b, c, d; } T45;
extern T45 D_00454970[];
void func_00271CD0(PH *p) {
    extern void func_00175700(PH *);
    f32 x;
    func_00175700(p);
    if (((s8 *)p)[0x151] == 0) {
        p->b7++;
        if (((u8 *)p)[0x1E6] != 0) x = D_00454970[((u8 *)p)[0x1B7]].a; else x = -D_00454970[((u8 *)p)[0x1B7]].a;
        p->f5c = x;
        if (*(u8 *)((s32)p + 0x1E6) != 0) x = D_00454970[((u8 *)p)[0x1B7]].b; else x = -D_00454970[((u8 *)p)[0x1B7]].b;
        p->f68 = x;
        p->f60 = D_00454970[((u8 *)p)[0x1B7]].c;
        p->f6c = D_00454970[((u8 *)p)[0x1B7]].d;
    }
}

typedef struct { u8 pad[0x404]; u8 b404; u8 b405; } PM2;
typedef struct { u8 pad[0x151]; s8 b151; } PK;
void func_00238300(PH *p) {
    extern s8 func_00175700(PH *);
    extern void func_001830D0(PH *, u32 *, s32);
    u32 v[3];
    ((u8 *)p)[0x40C] = 2;
    ((u8 *)p)[0x33C] = 5;
    ((PM2 *)p)->b405 = (((u8 *)p)[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if ((((s8 *)p)[0x151] & 1) == 0) {
        ((u8 *)p)[0x20D] = 2;
        p->f34 += p->f5c;
        p->f5c += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6c;
    }
    if ((*(s8 *)((s32)p + 0x151) & 2) != 0) {
        p->b6++;
        p->b7 = 0;
        ((u8 *)p)[0x22] = 0;
        ((PK *)p)->b151 ^= 2;
        ((PM2 *)p)->b404 = 0;
        *(u8 *)((s32)p + 0x405) = 0;
        v[0] = 0xC1D55555;
        v[1] = 0x433C9249;
        func_001830D0(p, v, 1);
    }
}
