typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0013EE10(u8 *p) {
    *(s32 *)(p + 0x40) -= 0x100;
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    if (*(s16 *)(p + 0x1E) >= 200) *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0xD0) |= 0x20000;
    *(s32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = -(1.0f - 0.004999999888f * (f32)*(s16 *)(p + 0x1E));
}

extern void func_00154790();
extern void func_001E3B70();
void func_0031A990(u8 *p, u8 *q) {
    f32 v[4];
    f32 a = -90.0f;
    if (*(s16 *)(p + 0x140)) a = -a;
    v[0] = a + *(f32 *)(q + 0x34);
    v[1] = 285.0f + *(f32 *)(q + 0x38);
    func_00154790(v, p[0x1E6], 2, 0);
    func_001E3B70(*(s32 *)(p + 0x1DC), 0);
}
