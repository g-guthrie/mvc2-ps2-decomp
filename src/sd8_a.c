#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; s32 w1C; u8 pad20[0x150]; } T170;
typedef struct { s32 w0; f32 f4; f32 f8; } Ob;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; s16 h10; s16 h12; } Q;
typedef struct { u8 pad[0x1E]; s16 h1E; } C;
extern T170 D_005BF2F0[];

void func_00330FF0(Q *p, Q *q, s32 context) {
    extern s32 func_003DD030(s32);
    extern void func_0041BAD0(Q *);
    extern Ob *func_0041BBB0(Q *);
    extern void func_0041BB30(Q *);
    C *c = (C *)(u32)context;
    s32 r;
    u8 *base;
    u16 *ranges;
    u16 *offs;
    Ob *o;
    r = q->w0 - 1;
    base = (u8 *)func_003DD030(((T170 *)((u8 *)&D_005BF2F0 + r * 0x170))->w1C);
    ranges = (u16 *)func_003DD030(q->w8);
    offs = (u16 *)func_003DD030(q->wC);
    func_0041BAD0(q);
    while ((o = func_0041BBB0(p)) != 0) {
        f32 x = o->f4;
        f32 y = o->f8;
        u16 start;
        u16 count;
        s32 i;
        if (x < -50.0f) {
            f32 k = (f32)c->h1E;
            x = x * (100.0f - 0.5f * k) / 100.0f;
            y = y * (100.0f + 10.0f * (0.5f * k)) / 100.0f;
        }
        start = ranges[2 * q->h10];
        count = ranges[2 * q->h10 + 1];
        for (i = 0; i < count; i++, start++) {
            u8 *e = base + offs[start];
            *(f32 *)(e + 4) = x;
            *(f32 *)(e + 8) = y;
        }
    }
    p->h12 = 0;
    p->h10 = 0;
    q->h12 = 0;
    q->h10 = 0;
    func_0041BB30(q);
}
