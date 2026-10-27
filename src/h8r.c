typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 fptosi(f32);
s32 func_003C2510(u8 *p) {
    s16 d = (s16)fptosi(*(f32 *)(p + 0x34) - (f32)*(s16 *)(p + 0xD0));
    if (d < 0) d = -d;
    return (f32)d < 26.666666f ? 1 : 0;
}

void func_00193180(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    f32 f;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    switch (p[0x20]) {
    case 0:
        f = 0.0f;
        break;
    case 1:
        f = 80.0f;
        break;
    case 2: {
        s16 v = *(s16 *)(p + 0x140) ^ 1;
        f = 80.0f;
        *(s16 *)(p + 0x140) = v;
        break;
    }
    }
    if (*(s16 *)(p + 0x140)) f = -f;
    *(f32 *)(p + 0x34) += f;
}
