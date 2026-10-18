typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct P {
    u8 pad0[6]; u8 b6; u8 pad7[0x34 - 7]; f32 f34; f32 f38; u8 pad3c[0x5C - 0x3C];
    f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0x160 - 0x70];
    s8 b[8]; u8 pad168[0x20D - 0x168]; u8 b20D; u8 pad20E[0x430 - 0x20E]; f32 f430;
} P;
extern void func_00175700(P *);
extern void func_001CEA00(P *, s32);
extern void func_00183d50(P *);
extern void func_001757E0(P *, s32, s32);

void func_002C8E60(P *p)
{
    f32 *a, *b, *c, *d;
    s8 *q;
    d = &p->f6C;
    c = &p->f68;
    b = &p->f60;
    a = &p->f5C;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_00175700(p);
    if (p->f38 > p->f430) {
        s8 f;
        s8 *r;
        q = p->b;
        f = q[1];
        r = q + 1;
        if (f != 0) {
            *r = 0;
            func_001CEA00(p, 7);
        }
    } else {
        p->b6++;
        p->f38 = p->f430;
        p->b20D = 1;
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0xC);
    }
}
