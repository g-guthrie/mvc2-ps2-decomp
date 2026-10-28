typedef signed int s32;
typedef unsigned int u32;
typedef struct { s32 w0; s32 w1; } E8;
extern s32 D_00633E20;
extern E8 D_00633E30[];

/* Queue three (lo, hi) entries into a 64-slot ring of 8-byte records. */
#define PUT_ENTRY(lo, hi) \
    hi = (hi + 0xF) & ~0xF; \
    ((E8 *)b)[i].w0 = ((hi >> 4) & 0xFFFFFF) | 0x4F000000; \
    ((E8 *)b)[i].w1 = lo | (hi >> 20);

void func_00423370(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1)
{
    s32 i;
    u32 b;
    i = D_00633E20;
    b = (u32)D_00633E30;
    PUT_ENTRY(a0, a1)
    i = ++i % 64;
    PUT_ENTRY(a2, a3)
    i = ++i % 64;
    PUT_ENTRY(t0, t1)
    D_00633E20 = ++i % 64;
}
