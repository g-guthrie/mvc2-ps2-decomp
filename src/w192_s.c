typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct P {
    u8 pad0[6]; u8 b6; u8 b7; u8 pad8[0x1C - 8]; s16 h1C; u8 pad1E[0x34 - 0x1E]; f32 f34; f32 f38; u8 pad3C[0x5C - 0x3C];
    f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0x140 - 0x70]; s16 h140; u8 pad142[0x1E6 - 0x142]; s8 b1E6;
    u8 pad1E7[0x20B - 0x1E7]; u8 b20B;
} P;
extern void func_00184540(P *);
extern void func_00175700(P *);
extern P *func_001E7FD0(P *);
extern void func_001266A0(P *, s32, s32);
extern void func_0015D010(P *, u32 *);
extern void func_001757E0(P *, s32, s32);
extern void func_00185770(P *, P *);

void func_001F4070(P *p)
{
    P *o;
    u32 v[4];
    s16 h;
    h = p->h1C - 1;
    p->h1C = h;
    if (h == 0) {
        func_00184540(p);
        return;
    }
    func_00175700(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if (p->h1C < 8) {
        if ((o = func_001E7FD0(p)) != 0) {
            p->b6++;
            p->b7 = 0;
            p->b20B = 0xCB;
            func_001266A0(p, 5, 5);
            v[0] = 0xC3055555;
            v[1] = 0x435EDB6D;
            func_0015D010(p, v);
            p->h140 ^= 1;
            p->b1E6 = p->h140;
            o->h140 ^= 1;
            o->b1E6 = o->h140;
            func_001757E0(p, 0xF, 0x31);
            func_00185770(p, o);
        }
    }
}
