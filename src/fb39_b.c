typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 p0[3]; u8 type; u8 p4[0x20]; s8 idx; u8 p25[0xF];
    f32 px, py, pz; u8 p40[8]; s32 f48; s16 w4c, w4e; f32 f50, f54; u8 p58[0x98];
    f32 fF0, fF4, fF8, fFC, f100; u8 p104[0x10];
    s32 f114; u8 p118[4]; s32 f11c, f120; u8 p124[0x18];
    s8 f13c; u8 p13d[3]; s16 f140; s16 f142; s16 f144, f146; u8 p148[0x15]; u8 f15d;
    u8 p15e[0x5A]; u8 f1b8;
} P;

typedef struct { u16 *tbl; u8 pad[0x5B4]; } T5B8;
typedef struct { u8 pad[0x24]; s32 v; } Q;

extern f32 D_004F1FC0[];
extern f32 D_004F1F60[];
extern f32 D_004F1C00[];
extern T5B8 D_004F2228[];
extern Q *D_004C2840;

void func_00152FB0(P *p)
{
    s32 idx;
    s32 t;
    f32 x, y, z;
    f32 k;
    extern void func_00417980(f32, f32, f32, f32 *, f32 *, f32 *);
    extern s32 func_00174F60(P *);
    if (p->f13c != 0 && (t = p->type) > 0 && t < 5) {
    idx = p->idx;
    func_00417980(p->px, p->py, p->pz, &x, &y, &z);
    y -= 240.0f * D_004F1FC0[0];
    p->fF0 = x;
    p->fF4 = y;
    p->fF8 = 0.1f * D_004F1F60[0] + D_004F1C00[p->idx];
    p->fFC = 1.6666666f * p->f50;
    p->f100 = 2.142857074737549f * p->f54;
    p->f114 = p->f48;
    p->f120 = p->f140;
    p->f11c = 0;
    p->f144 = p->w4c;
    p->f146 = p->w4e;
    k = D_004F1F60[0] / 812.3572998046875f;
    p->fFC /= k;
    p->f100 /= k;
    if (p->f15d != 0) {
        u16 *r = (u16 *)((u8 *)D_004F2228[p->f1b8].tbl + ((p->f15d & 0xFF) << 4));
        p->fFC *= (f32)r[0] / 1000.0f;
        p->f100 *= (f32)r[1] / 1000.0f;
        p->f114 = (p->f114 + r[2]) & 0xFFFF;
        p->f144 = r[3];
        p->f146 = r[4];
        p->f120 ^= r[5];
    }
    t = func_00174F60(p);
    D_004C2840->v += t;
    D_004F1C00[idx] += 0.001f * (f32)t;
    }
}
