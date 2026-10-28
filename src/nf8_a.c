typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001A8470(u8 *p, u8 *q) {
    extern void func_001A8140(u8 *, u8 *);
    u8 *o;
    f32 a, b;
    u32 t = p[5];
    o = *(u8 **)(p + 8);
    p[5] = t + 1;
    if (o[0x20] == 7) {
        a = -3.333333254f;
        b = 34.28571320f;
    } else {
        a = -40.0f;
        b = 102.8571396f;
    }
    if (*(s16 *)(p + 0x140) != 0) a = -a;
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + a;
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38) + b;
    func_001A8140(p, q);
}
