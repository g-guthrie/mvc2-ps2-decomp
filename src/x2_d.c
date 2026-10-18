typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[4]; u8 c4; u8 p5[0x17]; s16 s1c; u8 p1e[0x32]; f32 f50; f32 f54; u8 p58[4]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; u8 p70[0xCC]; u8 c13c; } S1B58;
typedef struct { u8 p0[0x50]; f32 f50; f32 f54; } Q1B58;
void func_001B58C0(S1B58 *p)
{
    Q1B58 *q = *(Q1B58 **)((u8 *)p + 0x18);
    p->f50 += p->f5c;
    p->f54 += p->f60;
    if (!(q->f54 < 1.0f)) {
        p->c4 = 2;
        p->c13c = 0;
    } else {
        s16 v = p->s1c - 1;
        p->s1c = v;
        if (v <= 0) {
            p->s1c = 6;
            p->c4 = 1;
            p->f50 = 0.3f + q->f50;
            p->f54 = 0.2f + q->f54;
            p->f5c = 0.04f;
            p->f68 = -0.004f;
            p->f60 = 0.04f;
            p->f6c = -0.004f;
        }
    }
}

typedef struct { u8 p0[5]; u8 c5; u8 p6[0x16]; s16 s1c; u8 p1e[0x1A]; f32 f38; u8 p3c[0x24]; f32 f60; u8 p64[8]; f32 f6c; } S1D59;
void func_001D59B0(S1D59 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_001E3270(u8 *, s32, f32);
    u8 *s0;
    s16 v;
    u32 t;
    s0 = (u8 *)((s32)q + 0x2B8);
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700(p);
    v = p->s1c - 1;
    p->s1c = v;
    if (v == 0) {
        t = p->c5;
        p->c5 = t + 1;
        p->f38 = *(f32 *)(q + 0x430);
        p->s1c = 0x1E;
        p->f60 = 4.285714149475098f;
        p->f6c = 0.5357142686843872f;
        func_001757E0(p, 0x12, 8);
        s0[1] = 1;
        func_001E3270(q, 0x22, 4.0f);
    }
}
