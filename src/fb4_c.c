typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[2];
    u8 b4;
    u8 pad5[0x34 - 5];
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
} OW;

typedef struct {
    u8 pad0[0x14];
    OW *o;
    u8 pad18[0x1C - 0x18];
    s16 h1C;
    s16 h1E;
    u8 pad20[0x34 - 0x20];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0x44 - 0x40];
    u32 w44;
    u32 w48;
    u8 pad4C[0x78 - 0x4C];
    f32 f78;
    f32 f7C;
} PL;

extern s32 fptosi(f32);
extern f32 func_00417440(u32);
extern f32 func_00417500(u32);
extern void func_003DAA40(PL *);

void func_0015FB30(PL *p) {
    OW *o;
    s16 a;
    f32 r;
    *(V3 *)&p->f34 = *(V3 *)&p->o->f34;
    o = p->o;
    a = fptosi(13.333333015441895f * o->f50);
    if (o->h140 == 0) a = -a;
    p->f34 = o->f34 + (f32)a;
    p->f38 += 222.8571319580078f * p->o->f54;
    if (p->o->b1B4 == 0) {
        p->h1C = p->h1C + 1;
        p->w44 = (u32)(s32)(0.5 + 65536.0 * (double)((p->h1C + p->h1E) * 2) / 360.0) & 0xFFFF;
        p->w48 = (u32)(s32)(0.5 + 65536.0 * (double)((p->h1C + p->h1E) * 3) / 360.0) & 0xFFFF;
        r = func_00417440((u32)(s32)(0.5 + 65536.0 * (double)(p->h1C % 360) / 360.0) & 0xFFFF);
        p->f78 = 0.5f + 0.5f * r;
        r = func_00417500((u32)(s32)(0.5 + 65536.0 * (double)(p->h1C % 360) / 360.0) & 0xFFFF);
        p->f7C = 0.5f + 0.5f * r;
    }
    if (p->o->b4 != 0) func_003DAA40(p);
    if (p->o->b1 != 0x18) func_003DAA40(p);
}
