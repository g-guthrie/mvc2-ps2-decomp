typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3h;

extern V3h *D_00442550[];
extern s32 D_004B3110[];

void func_001442F0(u8 *p) {
    V3h *a, *b;
    s32 h, h1, n;
    s16 v;
    switch (p[4]) {
    case 0:
        h = *(s16 *)(p + 0x1E);
        h1 = h + 1;
        n = D_004B3110[h1] - D_004B3110[h];
        a = D_00442550[p[0x20]] + h;
        b = D_00442550[p[0x20]] + h1;
        *(f32 *)(p + 0x34) += (b->x - a->x) / (f32)n;
        *(f32 *)(p + 0x38) += (b->y - a->y) / (f32)n;
        *(f32 *)(p + 0x3C) += (b->z - a->z) / (f32)n;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < n) break;
        *(s16 *)(p + 0x1C) = 0;
        *(V3h *)(p + 0x34) = *b;
        v = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = v;
        if ((u32)v < 0x30) break;
        p[4]++;
        break;
    case 1:
        break;
    }
    if (p[0x20] == 4) p[5]++;
}
