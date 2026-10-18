typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003962E0(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    s16 v;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (p[0x20] != 0) {
        if (!(*(f32 *)(q + 0x430) <= *(f32 *)(p + 0x38))) goto act;
    }
    if (*(s8 *)(p + 0x1B2) != 0) goto act;
    if (*(s8 *)(p + 0x1B3) != 0) goto act;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) goto done;
act:
    t = p[5];
    p[5] = t + 1;
    *(f32 *)(p + 0x5C) /= 4.0f;
    *(f32 *)(p + 0x68) /= 4.0f;
    *(f32 *)(p + 0x60) /= 4.0f;
    *(f32 *)(p + 0x6C) /= 4.0f;
    if (p[0x20] == 0) {
        func_001757E0(p, 0x17, 7);
    } else {
        func_001757E0(p, 0x17, 9);
    }
done:
    func_001E7F60(p);
}
