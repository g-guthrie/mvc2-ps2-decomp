typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef f32 F32Vec[3];
extern f32 data_f32_004B1940[8][2][3];

/* Provisional: independently matched local helper duplicates the global body. */
static void func_0013E760(u8 *p)
{
    F32Vec *a = (F32Vec *)(void *)data_f32_004B1940 + p[0x20] * 2;
    F32Vec *b = (F32Vec *)(void *)data_f32_004B1940 + (p[0x20] * 2 + 1);
    f32 d, e;
    e = (*a)[0];
    d = ((*b)[0] - e) / 30.0f;
    *(f32 *)(p + 0x34) = e + (f32)*(s16 *)(p + 0x1C) * d;
    e = (*a)[1];
    d = ((*b)[1] - e) / 30.0f;
    *(f32 *)(p + 0x38) = e + (f32)*(s16 *)(p + 0x1C) * d;
    e = (*a)[2];
    d = ((*b)[2] - e) / 30.0f;
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
