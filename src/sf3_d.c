typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x50 - 0x40];
    f32 f50;
    f32 f54;
    u8 pad58[0x140 - 0x58];
    s16 h140;
    u8 pad142[0x1B4 - 0x142];
    s8 b1B4;
    u8 pad1B5[0x2B8 - 0x1B5];
    u8 t2B8[4];
    f32 f2BC;
} OW155;

typedef struct {
    u8 pad0[0x18];
    OW155 *o;
    s16 h1C;
    s16 h1E;
    u8 b20;
    u8 b21;
    u8 pad22[0x34 - 0x22];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x44 - 0x40];
    u32 w44;
    u32 w48;
    u8 pad4C[0x78 - 0x4C];
    f32 f78;
    f32 f7C;
    u8 pad80[0x13C - 0x80];
    u8 b13C;
} PL155;
extern f32 func_00417440(u32);
extern f32 func_00417500(u32);

void func_00155C70(PL155 *p, s32 a1) {
    OW155 *o;
    u8 *t;
    u8 v;
    f32 k;
    o = p->o;
    t = o->t2B8;
    v = t[p->b21];
    p->b13C = v;
    if (v != 0) {
        f32 r;
        *(V3 *)&p->f34 = *(V3 *)&o->f34;
        k = o->f50 * 40.0f;
        if (o->h140 == 0) k = -k;
        p->f34 += k;
        p->f38 += 205.7142791748047f * o->f54;
        if (o->b1B4 == 0) {
            p->h1C = p->h1C + 1;
            p->w44 = (u32)(s32)(0.5 + 65536.0 * (double)((p->h1C + p->h1E) * 2) / 360.0) & 0xFFFF;
            p->w48 = (u32)(s32)(0.5 + 65536.0 * (double)((p->h1C + p->h1E) * 3) / 360.0) & 0xFFFF;
            r = func_00417440((u32)(s32)(0.5 + 65536.0 * (double)(p->h1C % 360) / 360.0) & 0xFFFF);
            p->f78 = *(f32 *)(t + 4) * (0.5f + 0.5f * r);
            r = func_00417500((u32)(s32)(0.5 + 65536.0 * (double)(p->h1C % 360) / 360.0) & 0xFFFF);
            p->f7C = *(f32 *)(t + 4) * (0.5f + 0.5f * r);
        } else {
            p->f78 = *(f32 *)(t + 4);
            p->f7C = 0;
        }
    }
}
