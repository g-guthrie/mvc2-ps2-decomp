typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
static void func_001CB680(u8 *p, u8 *o)
{
    s32 n;
    u32 *d, *s;
    p[4]++;
    s = (u32 *)(o + 236);
    d = (u32 *)(p + 236);
    for (n = 49; n > 0; n--) *d++ = *s++;
    p[316] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 80) = *(f32 *)(o + 80);
    *(f32 *)(p + 84) = *(f32 *)(o + 84);
    p[439] = o[439];
    p[440] = o[440];
    *(s8 *)(p + 48) = *(s8 *)(o + 48);
    *(V3 *)(p + 80) = *(V3 *)(o + 80);
    *(s8 *)(p + 36) = *(s8 *)(o + 36);
}

typedef struct { u8 p0[4]; u8 b4; u8 p5[0x17]; s16 h1C; u8 p1e[0x13]; s8 b31; u8 p32[2]; f32 f34; f32 f38; u8 p3c[0x115]; s8 b151; } P1CB9;
typedef struct { u8 p0[0x34]; f32 f34; u8 p38[0x3F8]; f32 f430; } Q1CB9;

void func_001CB920(P1CB9 *p, Q1CB9 *q)
{
    extern void func_001754A0(P1CB9 *, s32, s32);
    extern s8 func_00175670(P1CB9 *);
    extern void func_003DAA40(P1CB9 *);
    extern void func_001CB610(Q1CB9 *, s32);
    if (p->b4 == 0) {
        func_001CB680((u8 *)p, (u8 *)q);
        func_001754A0(p, 0x1B, 0x25);
        p->h1C = 2;
        p->b31 = -1;
        p->f34 = q->f34;
        p->f38 = q->f430;
    }
    if (func_00175670(p) < 0) {
        func_003DAA40(p);
        return;
    }
    if (p->b151 != 0) {
        s16 v;
        p->b151 = 0;
        v = p->h1C - 1;
        p->h1C = v;
        if (v < 0) {
            p->h1C = 2;
            func_001CB610(q, 5);
        }
    }
}
