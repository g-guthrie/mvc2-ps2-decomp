typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct TS {
    u8 _p0[0x2];
    u8 b2;
    u8 b3;
    u8 _p1[0x4];
    s16 h8;
    s16 ha;
    s8 bc;
    s8 bd;
    s8 be;
    s8 bf;
    f32 f10;
    f32 f14;
    u8 _p2[0x1];
    u8 b19;
    u8 b1a;
    u8 b1b;
} TS;
typedef struct { u8 a, b, c2, d; u32 w; } TE;

extern u8 D_004F4484[];
extern u8 D_004F4490[];
extern TE D_004B9208[];
extern u8 D_004F7F3E;
extern u8 D_004F7F30;
extern u8 D_004F7F31;
extern u8 D_004F7F32;
extern u8 D_004D18A6;

void func_003D4290(TS *p, s32 n)
{
    extern void func_001E3CE0(s32);
    extern s32 func_001315E0(s32);
    extern void func_003D33B0();
    extern void func_003D4880();
    extern void func_003D7350(u8, u8, u8, s32);
    u16 *a;
    s8 old;
    u16 *b;
    TE *e;
    s32 i;
    u32 m;

    e = D_004B9208;
    i = 0;
    do {
        func_003D7350(e->a, e->b, e->d, e->w);
        i++;
        e++;
    } while (i < 5);
    old = p->be;
    a = (u16 *)(D_004F4484 + n * 20);
    b = (u16 *)(D_004F4490 + n * 20);
    if (((*a | *b) & 0x2000) != 0) {
        p->be = old - 1;
    }
    if (((*a | *b) & 0x1000) != 0) {
        p->be = p->be + 1;
    }
    p->be = (p->be + 5) % 5;
    p->bf = p->be + 7;
    if (old != p->be) func_001E3CE0(1);
    m = func_001315E0((s8)n) & 0xFFFF;
    if ((m & *a) != 0) {
        switch (p->be) {
        case 0:
            func_003D33B0(p);
            break;
        case 1:
            D_004F7F3E = 1;
            D_004F7F30 = 0;
            D_004F7F31 = 0;
            D_004F7F32 = 0;
            p->b1b = D_004D18A6;
            D_004D18A6 = 0;
            break;
        case 2:
            p->b2 = 0;
            p->b3 = 0;
            p->bc = 0;
            p->h8 = 0x4650;
            p->ha = 10;
            p->f10 = 200.0f;
            p->f14 = 120.0f;
            p->b19 = 1;
            p->b1a = 0;
            func_003D4880();
            break;
        case 3:
            p->b2 = 0;
            p->b3 = 0;
            p->bc = 0;
            p->h8 = 0x4650;
            p->ha = 10;
            p->f10 = 80.0f;
            p->f14 = 88.0f;
            p->b19 = 2;
            p->b1a = 0;
            break;
        case 4:
            p->bd = 1;
            p->be = 1;
            break;
        default:
            break;
        }
        func_001E3CE0(2);
    }
}
