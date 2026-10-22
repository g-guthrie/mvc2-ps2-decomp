typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B1940[];

/* 0x0013E760 static copy (real body, verified in src/y1_e.c) */
static void func_0013E760(u8 *p)
{
    V3 *a = &D_004B1940[p[0x20] * 2];
    V3 *b = &D_004B1940[p[0x20] * 2 + 1];
    f32 d, e;
    e = a->x;
    d = (b->x - e) / 30.0f;
    *(f32 *)(p + 0x34) = e + (f32)*(s16 *)(p + 0x1C) * d;
    e = a->y;
    d = (b->y - e) / 30.0f;
    *(f32 *)(p + 0x38) = e + (f32)*(s16 *)(p + 0x1C) * d;
    e = a->z;
    d = (b->z - e) / 30.0f;
    *(f32 *)(p + 0x3C) = e + (f32)*(s16 *)(p + 0x1C) * d;
}

/* 0x0013EA00 */
void func_0013EA00(u8 *p) {
    s32 a = *(s16 *)(p + 0x1C);
    if (a != 0x1E) {
        *(s16 *)(p + 0x1C) = a + 1;
        func_0013E760(p);
    }
    *(s16 *)(p + 0x1E) += 1;
    if (*(s16 *)(p + 0x1E) >= 0xC8) *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0xD0) |= 0x20000;
    if (p[0x20] & 1) {
        *(f32 *)(p + 0xE0) = 0.004999999888241291f * (f32)*(s16 *)(p + 0x1E);
    } else {
        *(f32 *)(p + 0xE0) = 1.0f - 0.004999999888241291f * (f32)*(s16 *)(p + 0x1E);
    }
    *(u32 *)(p + 0xE4) = 0;
}
