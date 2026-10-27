typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C2B40;
extern u8 D_006327B0[];
extern u8 D_00632770[];


typedef struct { f32 x, y, z; } V3b;

void func_00417860(V3b *a, V3b *b, u16 c) {
    extern f32 func_003DE790(f32);
    extern f32 func_003DE710(f32);
    extern void func_003DD260(u8 *);
    extern void func_003DDF20(u8 *, V3b *, V3b *, V3b *);
    extern void func_003DF850(s32, u8 *);
    extern double litodp(s32);
    V3b va, vb, vc;
    double d;
    f32 fa;
    va.x = a->x; va.y = a->y; va.z = a->z;
    vb.x = b->x; vb.y = b->y; vb.z = b->z;
    d = (double)(s32)c;
    vc.x = func_003DE790((f32)(d = d * 6.283185307179586 / 65536.0));
    vc.y = func_003DE710((f32)d);
    vc.z = 0;
    func_003DD260(D_00632770);
    func_003DDF20(D_00632770, &va, &vb, &vc);
    func_003DF850(0x16, D_00632770);
}
