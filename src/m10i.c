typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern void func_001754A0(u8 *, s32, s32);
void func_0019A7C0(u8 *p, u8 *q) {
    f32 a = 188.5714263916015625f;
    f32 b;
    *(s8 *)(p + 0x31) = -1;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(u32 *)(p + 0x60) = 0x414DB6DB;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    *(u32 *)(p + 0x5C) = 0x40555555;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x38) += a;
    b = 80.0f;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        b = -b;
    }
    *(f32 *)(p + 0x34) += b;
    func_001754A0(p, 0x1B, 5);
}
