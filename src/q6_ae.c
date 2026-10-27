typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00347770(u8 *p) {
    extern int func_00175700(u8 *);
    u8 *q = *(u8 **)(p + 0x18);
    if (q[0x1E4] != 0x1D) {
        p[4] = 3;
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x34) -= 120.0f;
    } else {
        *(f32 *)(p + 0x34) += 120.0f;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x38) += 120.0f;
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    *(f32 *)(p + 0x118) -= 0.05f;
    if (*(f32 *)(p + 0x118) <= 0.0f) {
        p[4] = 3;
    }
    func_00175700(p);
}
