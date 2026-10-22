typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u32 addr; u32 size; s32 owner; s32 z; } E16;
typedef struct { s32 n; s32 f4; E16 *tab; s32 dir; u32 cur; s32 f14; s32 f18; u32 total; } Arena;
u32 func_003F0C60(Arena *a, u32 size, u32 align) {
    extern u32 func_003F0B20(Arena *);
    s32 i, n;
    u32 r;
    u32 t;
    E16 *e;
    r = func_003F0B20(a);
    if (r <= size + align) return 0;
    i = 0;
    while (i < a->n) {
        if (a->tab[i].size == 0) break;
        i++;
    }
    if (i == a->n) return 0;
    a->tab[i].z = 0;
    a->tab[i].size = size;
    a->tab[i].owner = a->f18;
    if (a->dir != 0) {
        a->tab[i].addr = ~(align - 1) & (a->cur + align - 1);
        t = a->tab[i].addr;
        a->cur = t + size;
    } else {
        a->tab[i].addr = ~(align - 1) & (a->cur - size);
        a->cur = a->tab[i].addr;
    }
    a->total += size;
    return i + 1;
}
