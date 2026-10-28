typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 p0[0x34]; f32 f34, f38, f3c; u8 p1[0x48-0x40]; s32 f48; u8 p2[0x140-0x4C]; s16 f140; } CC;
typedef struct { u8 pad[0x160]; s8 b[8]; } A160;

extern u8 D_00473AC0[];
extern u8 D_00473360[];
extern s16 D_004733C0[][32];
extern s16 D_004733C2[][32];
extern u8 D_004733A0[][2];
extern u8 D_004733A1[][2];
extern u8 D_004C1F3C[8];

void func_003ACCC0(u8 *a, u8 *b, CC *c, u8 *o) {
    extern void func_00178F20(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    u8 x, y;
    u8 *t;
    u8 k, m;
    s16 v;
    s8 *p;
    x = 0x10;
    y = 0;
    if (*(s16 *)(o + 0x140) == 0) {
        x = 0xF0;
        y = 8;
    }
    a[0x160] = D_00473AC0[(u8)(y + ((u8)(x + a[0x22]) >> 5))];
    p = ((A160 *)a)->b;
    func_00178F20(a, *(u8 **)(o + 0x1DC));
    if (c == 0) return;
    t = *(u8 **)(o + 0x1DC);
    m = D_00473360[t[1]];
    k = p[0] - 1;
    *(V3 *)&c->f34 = *(V3 *)(a + 0x34);
    c->f34 += 1.6666666269302368f * (f32)D_004733C0[m][k*2];
    c->f38 -= 2.142857074737549f * (f32)D_004733C2[m][k*2];
    v = D_004733A1[k][0];
    c->f140 = v;
    switch (v) {
    case 2:
        c->f48 = 0x8000;
        c->f140 = 1;
        break;
    case 3:
        c->f48 = 0x8000;
        c->f140 = 0;
        break;
    default:
        c->f48 = 0;
        break;
    }
    func_001757E0((u8 *)c, 0x14, D_004C1F3C[m] + D_004733A0[k][0]);
}
