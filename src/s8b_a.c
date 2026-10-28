typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 b[8]; } E8;
extern s8 D_004F7F5F;
extern E8 D_004B91D0[];
extern f32 D_00477290[];
extern f32 D_004F7FD0;
extern f32 D_004F7FD4;
extern void func_00417AE0(s32, f32 *);

void func_003D4630(void)
{
    E8 *e = &D_004B91D0[D_004F7F5F];
    f32 *o = (f32 *)D_00477290;
    f32 k = *(volatile f32 *)&D_004F7FD0;
    o[0] = o[8] = k + 4.0f * (f32)e->b[0] - 4.0f;
    o[4] = o[12] = 8.0f + (D_004F7FD0 + 4.0f * (f32)e->b[2]);
    o[1] = o[5] = (D_004F7FD4 + 4.0f * (f32)e->b[1]) - 2.0f;
    o[9] = o[13] = 1.0f + (16.0f + (D_004F7FD4 + 4.0f * (f32)e->b[1]));
    func_00417AE0(4, o);
}

typedef struct { u32 base, start, end, cur, lim, align; } Heap;

s32 func_003F0940(Heap *h, u32 base, u32 size, u32 align)
{
    u32 n;
    u32 t;
    h->base = base;
    h->align = align;
    t = size + align - 1; n = ~(align - 1) & t;
    t = h->base + h->align - 1; h->start = ~(h->align - 1) & t;
    t = h->base + n + h->align - 1; h->end = ~(h->align - 1) & t;
    h->cur = h->start;
    h->lim = h->end;
    return 1;
}
