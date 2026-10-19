typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int D_004C283C;
extern double func_00119058(f32);

void func_00334C40(u8 *p)
{
    s16 h1e = *(s16 *)(p + 0x1E);
    if (h1e >= 9) {
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        if (*(f32 *)(p + 0x74) == 0.0f)
            *(f32 *)(p + 0x74) = 1.0f;
        return;
    }
    if (*(s16 *)(p + 0x1C) == 0) {
        s32 v = h1e + 27;
        if (v >= 35)
            v = 34;
        *(s16 *)(p + 0xCC) = (s16)v;
        *(int *)(p + 0x84) = D_004C283C;
    }
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    *(f32 *)(p + 0x74) = *(f32 *)(p + 0x74) - 0.0125f;
    if (*(f32 *)(p + 0x74) < 0.0f)
        *(f32 *)(p + 0x74) = 0.0f;
    if (*(f32 *)(p + 0x50) < 1.0f) {
        f32 f12 = *(f32 *)(p + 0x50) + 0.0125f;
        *(f32 *)(p + 0x50) = f12;
        if (func_00119058(f12) >= 1.0)
            *(f32 *)(p + 0x50) = 1.0f;
    }
    if (*(s16 *)(p + 0x1C) >= 8) {
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    }
}
