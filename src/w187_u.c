typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x1C]; s16 h1C; u8 pa[0x14]; f32 f34; f32 f38; u8 p1[0x20]; f32 f5C; f32 f60; u8 p2[4]; f32 f68; f32 f6C; u8 p3[0xE1]; s8 b151; } PF;
extern s16 D_00450D80[];
extern s16 D_00450D82[];
extern void func_00175700();

void func_00214DD0(PF *p) {
    s32 a;
    u32 t;
    s32 h;
    func_00175700(p);
    a = p->b151;
    if (a == 0x18) {
        t = ((u8 *)p)[6];
        ((u8 *)p)[6] = t + 1;
        p->f38 = *(f32 *)((u8 *)p + 0x430);
        return;
    }
    if (p->h1C > 12) {
        p->f34 += p->f5C;
        p->f5C += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6C;
    }
    if (p->b151 != 0) {
        f32 v;
        p->h1C = p->b151;
        p->b151 = 0;
        v = 1.6666666269302368f * (f32)D_00450D80[p->h1C / 2];
        if (((u8 *)p)[0x1E6] == 0) v = -v;
        p->f34 += v;
        p->f38 -= 2.142857074737549f * (f32)D_00450D82[p->h1C / 2];
    }
}
