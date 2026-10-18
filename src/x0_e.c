typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V13F5F0;
typedef struct { u8 pad0[0x1C]; s16 h; u8 pad1e[2]; u8 idx; u8 pad21[0x13]; f32 f34, f38, f3c; } P13F5F0;
extern V13F5F0 D_004406E0[];
extern V13F5F0 D_004407A0[];

void func_0013F5F0(P13F5F0 *p) {
    V13F5F0 *a = &D_004406E0[p->idx];
    V13F5F0 *b = &D_004407A0[p->idx];
    f32 d, s, e;
    s = a->x; e = b->x;
    d = (e - s) / 30.0f;
    p->f34 = s + (f32)p->h * d;
    s = a->y; e = b->y;
    d = (e - s) / 30.0f;
    p->f38 = s + (f32)p->h * d;
    s = a->z; e = b->z;
    d = (e - s) / 30.0f;
    p->f3c = s + (f32)p->h * d;
}
