#pragma opt_lifetimes off
#pragma opt_propagation off
#pragma opt_unroll_loops off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; s32 w1C; u8 pad2[0x170 - 0x20]; } E_b;
extern E_b D_005BF2F0[];
typedef struct { f32 x, y, z; } V3_b;

void func_00330380(u8 *a, u8 *b, u8 *c)
{
    extern u8 *func_003DD030(s32);
    extern void func_0041BAD0(u8 *);
    extern V3_b *func_0041BBB0(u8 *);
    extern f32 func_00417EB0(V3_b);
    extern f32 func_003DE790(f32);
    extern void func_0041BB30(u8 *);
    extern s32 fptosi(f32);
    u8 *cc = c;
    u8 *t6;
    u8 *t0;
    u8 *t1;
    f32 *py;
    u8 *bb = b;
    u8 *aa = a;
    V3_b *s;
    V3_b v;
    V3_b w;
    f32 r;
    s32 m;
    u16 k;
    u16 *e;
    u16 n;
    s32 i;

    t6 = func_003DD030(((E_b *)((s32)&D_005BF2F0[*(s32 *)bb - 1]))->w1C);
    t0 = func_003DD030(*(s32 *)(bb + 8));
    t1 = func_003DD030(*(s32 *)(bb + 0xC));
    func_0041BAD0(bb);
    while ((s = func_0041BBB0(aa)) != 0 && func_0041BBB0(bb) != 0) {
        v.x = s->x;
        py = &v.y;
        *py = s->y;
        v.z = s->z;
        w = v;
        r = func_00417EB0(w);
        if ((v.x < -350.0f || !(v.x <= 350.0f)) && v.z < -100.0f) {
            m = *(s16 *)(cc + 0x1C) * 30;
            { s32 fi = fptosi(r); *py += 0.019999999552965164f * r * func_003DE790((f32)(fi + m) * 0.01745329238474369f); }
        }
        e = (u16 *)(t0 + *(s16 *)(bb + 0x10) * 4);
        k = e[0];
        n = e[1];
        i = 0;
        while (i < n) {
            *(f32 *)(t6 + ((u16 *)t1)[k] + 4) = *py;
            i++;
            k++;
        }
    }
    *(s16 *)(aa + 0x12) = 0;
    *(s16 *)(aa + 0x10) = 0;
    *(s16 *)(bb + 0x12) = 0;
    *(s16 *)(bb + 0x10) = 0;
    func_0041BB30(bb);
}
