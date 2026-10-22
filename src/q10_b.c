typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad[0x104]; s16 h140; } O_003530D0;
void func_003530D0(O_003530D0 *a, O_003530D0 *b) {
    a->f38 = 199.2857056f + b->f38;
    if (b->h140 != 0) {
        a->f34 = 116.6666641f + b->f34;
    } else {
        a->f34 = b->f34 - 116.6666641f;
    }
}

typedef struct { u8 pad0[5]; u8 b5; u8 pad1[0x12]; u8 *p18; u8 pad2[0x40]; f32 f5c; f32 f60; u8 pad3[4]; f32 f68; f32 f6c; u8 pad4[0xD0]; s16 h140; } O_0034DAE0;
extern s32 func_00175700( void *);
extern void func_001757E0( void *, s32, s32);
void func_0034DAE0(O_0034DAE0 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p->b5;
        p->b5 = t + 1;
        p->h140 = *(s16 *)(p->p18 + 0x140);
        p->f60 = 0.0f;
        p->f6c = 0.0f;
        p->f5c = (p->h140 != 0) ? -6.6666665f : 6.6666665f;
        p->f68 = 0.0f;
        func_001757E0(p, 0x17, 4);
    }
}

extern void func_001830D0( void *, void *, s32);
void func_002A4830(u8 *p) {
    f32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = -5.0f;
        v[1] = 132.8571319f;
        v[2] = 0.0f;
        func_001830D0(p, v, 1);
    }
}

void func_0031FAF0(u8 *p) {
    f32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        if (p[0x269] != 5) {
            p[0x404] = 0;
            p[0x405] = 0;
            v[0] = -80.0f;
            v[1] = 34.2857132f;
            func_001830D0(p, v, 1);
        }
    }
}

typedef struct { u8 pad0[6]; u8 b6; u8 pad1[0x15]; s16 h1C; u8 pad2[0x16]; f32 f34; u8 pad3[0x24]; f32 f5c; u8 pad4[8]; f32 f68; u8 pad5[0x17A]; u8 b1E6; } O_0026C5E0;
void func_0026C5E0(O_0026C5E0 *p) {
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    {
        s16 h = p->h1C - 1;
        p->h1C = h;
        if (h == 0) {
            u32 t = p->b6;
            p->b6 = t + 1;
            func_001757E0(p, 2, 2);
            p->f68 = (p->b1E6 != 0) ? -0.8333333134f : 0.8333333134f;
        }
    }
}

extern void func_0018C6E0(void *);
extern void func_0015D010( void *, void *);
void func_002FB620(u8 *p) {
    f32 v[3];
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 6);
    v[0] = -85.0f;
    v[1] = 53.57142639f;
    v[2] = 0.0f;
    func_0015D010(p, v);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
}
