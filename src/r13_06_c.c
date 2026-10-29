/* func_0035A820: MW 3.0 "-O3 -Op -fp off -sdatathreshold 0", exact when compiled in the same mwccps2 run after src/wrm2_e.c (warm-up: nearest preceding double-arithmetic function func_003504B0; this function lowers its (s32) casts to fptosi). qq = q is assigned at the end of the first block and e is declared right after qq. */
#pragma opt_lifetimes off
#pragma opt_propagation off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[8]; u16 h8; } QCc;

void func_0035A820(u8 *p, u8 *q)
{
    extern void func_00175910(u8 *, u8, u8, u8);
    extern f32 func_00417440(s32);
    extern f32 func_00417500(s32);
    extern s32 func_0035A7B0(u8 *, u8 *);
    u8 *qq;
    u8 *e;
    u8 *pp = p;
    u8 *o;
    s16 k;
    s32 a;
    s16 x;
    s32 h;
    s16 hh;
    s16 y;
    s16 d;
    f32 t;
    f32 sn;
    f32 cs;
    o = *(u8 **)(pp + 0x18);
    e = *(u8 **)(o + 0x18C);
    *(f32 *)(pp + 0x34) = *(f32 *)(o + 0x34);
    *(f32 *)(pp + 0x38) = *(f32 *)(o + 0x38);
    *(s16 *)(pp + 0x140) = *(s16 *)(o + 0x140);
    *(s32 *)(pp + 0x48) = *(s32 *)(o + 0x48);
    qq = q;
    if ((h = *(s16 *)(o + 0x160)) == 0) {
        pp[0x13C] = 0;
        *(u16 *)(qq + 8) = 0xFFFF;
        return;
    }
    pp[0x13C] = 1;
    hh = h; if (*(u16 *)(qq + 8) != hh) {
        ((QCc *)qq)->h8 = h;
        e += hh * 16;
        *(u8 **)qq = e;
        *(s16 *)(qq + 4) = *(s16 *)e;
        *(s16 *)(qq + 6) = *(s16 *)(e + 2);
        *(s8 *)(qq + 0xF) = *(s8 *)(e + 4);
        pp[0x169] = 0x1A;
        pp[0x168] = e[6];
        func_00175910(pp, pp[0x169], pp[0x168], e[7]);
    }
    *(s8 *)(pp + 0x31) = *(s8 *)(qq + 0xF);
    x = *(s16 *)(qq + 4);
    y = *(s16 *)(qq + 6);
    if (*(s16 *)(pp + 0x140) != 0) x = -x;
    k = *(s16 *)(o + 0x4C);
    a = (s16)(s32)(2.142857074737549f * (f32)-y);
    t = (f32)(a + *(s16 *)(o + 0x4E) * 2);
    sn = t * func_00417440(*(s32 *)(pp + 0x48));
    t = func_00417500(*(s32 *)(pp + 0x48));
    x = (s32)(1.6666666269302368f * (f32)x);
    { f32 u = (f32)(x + k); u *= t; u += sn; k = (s32)(u - (f32)k); }
    t = (f32)-(x + *(s16 *)(o + 0x4C)) * func_00417440(*(s32 *)(pp + 0x48));
    cs = func_00417500(*(s32 *)(pp + 0x48));
    h = *(s16 *)(o + 0x4E) * 2;
    { f32 u = (f32)(a + h); cs = u * cs; d = (s32)(t + cs - (f32)h); }
    *(f32 *)(pp + 0x34) += (f32)k;
    *(f32 *)(pp + 0x38) += (f32)d;
    func_0035A7B0(pp, qq);
}
