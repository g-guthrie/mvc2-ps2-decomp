typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x10]; f32 f10; f32 f14; } Q96;
typedef struct {
    u8 pad0[5]; u8 b5; u8 pad6[0x16]; s16 s1C; u8 pad1E[3]; u8 b21; u8 pad22[0xF]; s8 b31; u8 pad32[2];
    f32 f34; f32 f38; u8 pad3C[0x20]; f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0xD0]; s16 h140;
} P96;
typedef struct { s32 a, b, c, d, e, f; } T96;
extern T96 D_0044A158[];

void func_00196E50(P96 *p, P96 *o)
{
    extern void func_00197600(P96 *);
    extern s32 func_00417A40(void);
    extern void func_00175580(P96 *, s32, s32, s32);
    Q96 *q;
    u32 t = p->b5;
    q = (Q96 *)((u8 *)p + 0x88);
    p->b5 = t + 1;
    func_00197600(p);
    p->h140 = o->h140;
    p->f34 = o->f34;
    p->f38 = 120.0f + o->f38;
    if (p->b21 <= 4) {
        p->f5C = 1.6666666269302368f * (f32)D_0044A158[(s32)p->b21].a / 65536.0f;
        p->f60 = 2.142857074737549f * (f32)D_0044A158[p->b21].b / 65536.0f;
        p->f68 = 1.6666666269302368f * (f32)D_0044A158[p->b21].c / 65536.0f;
        q->f10 = 1.6666666269302368f * (f32)D_0044A158[p->b21].d / 65536.0f;
        p->f6C = 2.142857074737549f * (f32)D_0044A158[p->b21].e / 65536.0f;
        q->f14 = 2.142857074737549f * (f32)D_0044A158[p->b21].f / 65536.0f;
        if (p->h140 == 0) {
            p->f5C = -p->f5C;
            p->f68 = -p->f68;
            q->f10 = -q->f10;
        }
        p->b31 = -2;
        p->s1C = 0x3C;
        func_00175580(p, 0x1B, 8, func_00417A40() & 3);
    }
}
