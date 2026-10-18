typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
extern void func_001757E0(u8 *, s32, s32);

void func_00140F80(u8 *p) {
    *(u32 *)(p + 0xD0) |= 0x20000;
    *(f32 *)(p + 0xE0) = -0.005f * *(s16 *)(p + 0x1E);
    *(f32 *)(p + 0xE4) = -0.005f * *(s16 *)(p + 0x1E);
}

void func_001DB130(u8 *p) {
    f32 d;
    p[0x24] = 0xB;
    d = 161.66666f;
    if (*(s16 *)(p + 0x140) == 0) d = -d;
    *(f32 *)(p + 0x34) += d;
    *(f32 *)(p + 0x38) += 210.0f;
    func_001757E0(p, 0x17, 8);
}

void func_002304C0(u8 *p) {
    f32 a = 18.333333f;
    f32 b = -0.8333333f;
    if (*(s16 *)(p + 0x140) == 0) { a = -a; b = -b; }
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = b;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x6C) = 0;
}

void func_00394700(u8 *p) {
    f32 a;
    p[5] = 6;
    if (*(s16 *)(p + 0x140) != 0) a = 3.3333333f; else a = -3.3333333f;
    *(f32 *)(p + 0x5C) = a;
    *(s32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = 12.857142f;
    *(s32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x17, 0x10);
}
