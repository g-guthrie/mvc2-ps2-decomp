typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(void *);
extern u8 *D_004C2794;
typedef struct { u8 p0[2]; u8 b2; u8 p1[3]; u8 b6; u8 p2[0x35]; f32 f5c; u8 p3[0xE0]; u16 h140; } S_002FABA0;
void func_002FABA0(u8 *p) {
    u32 t;
    s16 *q;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        t = p[6];
        p[6] = t + 1;
        p[0x1B5] = 0x38;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
        q[0x3E] = q[0x3E] + 1;
        *(u32 *)(p + 0x5C) = 0xC0D55555;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
    }
}

extern s32 D_004BF630[2];
extern void func_001A0400(void *, void *);
extern void func_001A09B0(void *);
extern void func_001A0880(void *, void *);
extern void func_001A0620(void *, void *);
extern void func_001A0540(void *, void *);
typedef struct { u8 p0[4]; u8 b4; u8 p1[0x1B]; u8 b20; u8 p2[0x13]; f32 f34; f32 f38; u8 p3[0x188]; s32 w1C4; } A_001A0200;
typedef struct { u8 p[0x24]; f32 f24; f32 f28; } R;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p1[0x27C]; R r; } B_001A0200;
void func_001A0200(A_001A0200 *a, B_001A0200 *b) {
    u32 t;
    R *r = &b->r;
    func_001A0400(a, b);
    t = a->b4;
    a->b4 = t + 1;
    a->f34 = b->f34 + r->f24;
    a->f38 = b->f38 + r->f28;
    a->w1C4 = D_004BF630[a->b20];
    func_001A09B0(a);
    func_001A0880(a, b);
    func_001A0620(a, b);
    func_001A0540(a, b);
}

typedef struct { f32 x, y, z; } V3_00156F50;
extern V3_00156F50 D_00444C60;
extern s32 D_004C2838;
extern void func_00156EE0();
typedef struct { u8 p0[0x10]; void *w10; u8 p1[0x20]; V3_00156F50 v34; u8 p1b[8]; s32 w48; u8 p2[4]; V3_00156F50 v50; u8 p3[0x28]; s32 w84; u8 p4[0x44]; s16 hCC; u8 p5[2]; s32 wD0; u8 p6[0x68]; u8 b13C; } O;
typedef struct { u8 p0[0x34]; V3_00156F50 v34; } S_00156F50;
extern O *func_003DA750(s32, u8, s32);
void func_00156F50(S_00156F50 *p, u8 type) {
    O *o;
    if ((o = func_003DA750(0, (type == 9) ? 0x1B : 0x3F, 1)) != 0) {
        o->b13C = 1;
        o->w10 = (void *)func_00156EE0;
        o->hCC = 0x17;
        o->w84 = D_004C2838;
        o->v34 = p->v34;
        o->w48 = 0x1555;
        o->v50 = D_00444C60;
        o->wD0 = 0x800199;
    }
}
