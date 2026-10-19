typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00152550(u8 *, s32);

void func_00161160(u8 *p)
{
    s32 v;

    p[0x13C] = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
    v = *(s32 *)(p + 0xDC);
    if (v < 0x15)
        *(f32 *)(p + 0x74) += 0.05f;
    else if (v < 0x28)
        *(u32 *)(p + 0x74) = 0x3F800000;
    else
        *(f32 *)(p + 0x74) -= 0.05f;
    *(s16 *)(p + 0x1E) += 1;
    if (*(s16 *)(p + 0x1E) >= 0x50)
        *(s16 *)(p + 0x1E) = 0;
    v = *(s32 *)(p + 0xDC) + 1;
    *(s32 *)(p + 0xDC) = v;
    if (!(v < 0x3D) || *(s8 *)(p + 0x13C) == 0) {
        p[4] += 1;
        func_00152550(p, 0);
    }
}
