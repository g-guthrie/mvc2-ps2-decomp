typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003AC500(u8 *p, u8 *end) {
    do {
        u8 *c = p;
        s16 *q = (s16 *)(c + 0x88);
        p = *(u8 **)(p + 8);
        *(f32 *)(p + 0x34) = *(f32 *)(c + 0x34) + (f32)q[0] - (f32) * (s16 *)(p + 0x8C);
        *(f32 *)(p + 0x38) = (f32) * (s16 *)(p + 0x8E) + (*(f32 *)(c + 0x38) - (f32)q[1]);
        p[0x13C] = 1;
    } while (end != p);
}
