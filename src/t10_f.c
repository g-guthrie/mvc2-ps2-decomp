typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();
extern void func_001757E0();
extern void func_00183d50();
extern s32 func_00189B40();
extern s8 D_004F7FC8[];
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad1[0x1C]; f32 f58; f32 f5c; f32 f60; u8 pad2[4]; f32 f68; f32 f6c; u8 pad3[0x430 - 0x70]; f32 f430; } F;

void func_00296AD0(F *p) {
    f32 z = 0.0f;
    f32 *v1, *a3, *t0, *t1;
    v1 = &p->f5c;
    t0 = &p->f68;
    a3 = &p->f60;
    t1 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (!(p->f68 * p->f5c <= z)) {
        u32 t = *((u8 *)p + 6);
        *((u8 *)p + 6) = t + 1;
        *v1 = z;
        *a3 = z;
        *t0 = z;
        *t1 = z;
        p->f38 = p->f430;
        func_001757E0(p, 2, 2);
    } else {
        func_00175700(p);
    }
}

