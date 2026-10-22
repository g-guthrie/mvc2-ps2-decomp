typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

#pragma padloop on

extern s8 D_00473B80[];
extern s8 D_00473B81[];
typedef struct { u8 p0[0x34]; V3 pos; } Q3;
typedef struct {
    u8 p0[0x18]; Q3 *q; u8 p1[0x21 - 0x1C]; u8 b21; u8 p2[0x34 - 0x22];
    V3 pos; u8 p3[0xD0 - 0x40]; s32 i; u8 p4[0x140 - 0xD4]; s16 flag;
} H3;
static void func_003AE2C0(H3 *p)
{
    f32 t;
    p->pos = p->q->pos;
    t = 1.6666666269302368f * (f32)D_00473B80[p->i * 4 + p->b21 * 2];
    p->pos.y += 2.142857074737549f * (f32)D_00473B81[p->i * 4 + p->b21 * 2];
    if (p->flag != 0) t = -t;
    p->pos.x += t;
}
extern s16 D_004C1F50;
static void func_003AE370(u8 *p)
{
    *(s16 *)(p + 30) = (&D_004C1F50)[*(s32 *)(p + 208)];
}
void func_003AE390(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    s32 n;
    u32 *d;
    u32 *r;
    u32 t;
    t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    d = (u32 *)(p + 0xEC);
    r = (u32 *)(q + 0xEC);
    n = 49;
    for (; n > 0; --n) {
        *d++ = *r++;
    }
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x24] = 0;
    *(s32 *)(p + 0xD0) = 0;
    func_003AE2C0((H3 *)p);
    func_003AE370(p);
    p[0x168] = 2;
    if (p[0x21] != 0)
        p[0x168] = 4;
    func_001757E0(p, 0x13, p[0x168]);
}
