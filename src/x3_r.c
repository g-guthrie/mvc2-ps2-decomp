typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_001D4DB0(u8 *p, void *context) {
    u8 *q = context;
    extern int func_00175700(u8 *);
    u8 *s2 = q + 0x2B8;
    f32 d;
    func_00175700(p);
    d = *(f32 *)(q + 0x38) - *(f32 *)(p + 0x38);
    if (*(s8 *)(s2 + 7) == 0) {
        if (d < 308.5714111328125f) {
            *(f32 *)(p + 0x6C) = d / 16.0f;
            return;
        }
        s2[7] = 1;
    }
    if (d < 377.1428527832031f) {
        *(f32 *)(p + 0x6C) = d / 16.0f;
    } else {
        *(f32 *)(q + 0x38) = 377.1428527832031f + *(f32 *)(p + 0x38);
    }
}
