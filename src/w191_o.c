typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    s16 h0;
    s16 h2;
    u8 pad4[4];
    s16 h8;
} S3B0;

typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x22 - 8];
    u8 b22;
    u8 pad23[0x34 - 0x23];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad70[0xD0 - 0x70];
    S3B0 s0D0;
    u8 padDA[0x140 - 0xDA];
    s16 h140;
} P3B0;

void func_003B0330(P3B0 *p, u8 *q)
{
    extern void func_00175910(P3B0 *, s32, s32, s32);
    extern void func_00174910(P3B0 *, s32);
    extern void func_003B07D0(P3B0 *, u8 *);
    S3B0 *s = &p->s0D0;
    u32 t;
    s32 v;

    t = p->b7;
    if (t == 0) {
        p->b7 = t + 1;
        s->h8 = 0x1900;
    } else {
        if (p->h140 == 0) {
            t = p->b22;
            p->b22 = t - 1;
        } else {
            t = p->b22;
            p->b22 = t + 1;
        }
        t = p->b22;
        p->b22 = t & 0x1F;
        if (p->h140 != 0) {
            v = 12 - p->b22 / 2;
        } else {
            v = p->b22 / 2 - 4;
        }
        func_00175910(p, 0x17, 3, v & 0xF);
        p->f34 = s->h0;
        p->f38 = s->h2;
        p->f5c = 0.0f;
        p->f60 = 0.0f;
        p->f68 = 0.0f;
        p->f6c = 0.0f;
        func_00174910(p, s->h8);
        *(u16 *)&s->h8 += 0x64;
    }
    func_003B07D0(p, q);
}
