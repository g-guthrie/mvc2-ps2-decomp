typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34, f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c, f60;
    u8 pad64[4];
    f32 f68, f6c;
} S232;

extern u8 *D_004C2794;
static void func_00231D70(u8 *p, s32 u)
{
    p[437] = (u8)((signed char)p[336] + 81);
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
}

static void func_0022FFB0(u8 *p, s32 unused) {
    f32 a = 16.6666660309f;
    f32 b = 18.3333320618f;
    f32 c = -0.208333328366f;
    if (*(s16 *)(p + 0x140) == 0) { a = -a; b = -b; c = -c; }
    if (p[0x1B7] != 0) *(f32 *)(p + 0x5C) = b; else *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = c;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
}

void func_00232020(u8 *p, s32 b)
{
    extern void func_00175700(u8 *, s32);
    extern void func_001863F0(u8 *);
    S232 *s = (S232 *)p;
    func_00175700(p, b);
    if (*(s8 *)(p + 0x151) == 0) {
        s->f34 += s->f5c;
        s->f5c += s->f68;
        s->f38 += s->f60;
        s->f60 += s->f6c;
        func_001863F0(p);
    } else {
        u32 t;
        *(s16 *)(p + 0x1C) = 0x20;
        t = p[7];
        p[7] = t + 1;
        func_0022FFB0(p, b);
        func_00231D70(p, b);
    }
}
