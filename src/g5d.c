typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_00446C40[];

void func_0018CBB0(u8 *p, u8 idx) {
    f32 r = 1.6666666f * (f32)*(s16 *)(D_00446C40 + idx * 2) / 256.0f;
    *(u32 *)(p + 0x68) = 0x3FFD5555;
    if (p[0x1BA] != 0) {
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        r = -r;
    }
    *(f32 *)(p + 0x22C) = r;
}

extern f32 func_00117078(f32 f);

s32 func_003657D0(u8 *a, u8 *b, u32 c) {
    f32 d = func_00117078(*(f32 *)(a + 0x34) - *(f32 *)(b + 0x34));
    return d <= 1.6666666f * (f32)c;
}
