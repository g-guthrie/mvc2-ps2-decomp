typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {
    u8 pad0[6]; u8 b6; u8 pad7[0x1C - 7]; s16 h1C; u8 pad1E[0x34 - 0x1E];
    f32 f34; f32 f38; u8 pad3C[0x5C - 0x3C]; f32 f5C; f32 f60; u8 pad64[0x68 - 0x64];
    f32 f68; f32 f6C; u8 pad70[0x1E6 - 0x70]; u8 b1E6;
} P;

extern void func_00175700(P *);

void func_0029D060(P *p)
{
    f32 v;
    s16 h;
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    func_00175700(p);
    h = p->h1C - 1;
    p->h1C = h;
    if (h == 0) {
        if (p->b1E6 != 0) v = -4.166666507720947f; else v = 4.166666507720947f;
        p->f5C = v;
        if (p->b1E6 != 0) v = 0.2864583134651184f; else v = -0.2864583134651184f;
        p->f68 = v;
        p->b6++;
        p->h1C = 8;
    }
}
