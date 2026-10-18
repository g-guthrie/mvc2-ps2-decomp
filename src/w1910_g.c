typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 f0, f4, f8; u8 pad[0x10]; s32 f1c, f20, f24; u8 pad2[0x10]; void *f38; void *f3c; } Ent_g;
extern Ent_g D_00490DA8[];
extern u8 D_00490D78[];
extern u8 D_004BEA10[];

Ent_g *func_0040F5E0(s32 a, s32 b, s32 c)
{
    extern void func_0040EFE0();
    extern void func_0040EFF8();
    extern void func_0040F728(Ent_g *);
    extern void func_0040F530();
    Ent_g *e;
    s32 i;
    func_0040EFE0();
    for (i = 0; i < 0x100; i++) {
        if (D_00490DA8[i].f4 == 0) break;
    }
    if (i == 0x100) {
        e = 0;
    } else {
        e = &D_00490DA8[i];
        e->f4 = 1;
        e->f0 = (s32)D_00490D78;
        e->f1c = a;
        e->f20 = b;
        e->f24 = c;
        e->f8 = (s32)D_004BEA10;
        e->f38 = (void *)func_0040F530;
        e->f3c = e;
        func_0040F728(e);
    }
    func_0040EFF8();
    return e;
}
