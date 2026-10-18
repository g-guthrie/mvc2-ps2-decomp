typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004C2840;

void func_00398C30(u8 *p) {
    s32 r;
    extern s32 func_00175700();
    extern void func_00398D00();
    if (*(s8 *)(p + 0x151) != 0) {
        f32 a = -2.14285707f;
        *(f32 *)(p + 0x38) += a;
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += 0.833333313f;
        } else {
            *(f32 *)(p + 0x34) += -0.833333313f;
        }
        p[0x13C] = (*(s8 *)(*(u8 **)&D_004C2840 + 0x1C) & 1) ^ *(s8 *)(p + 2);
    }
    if ((s8)func_00175700(p) < 0) func_00398D00(p);
}
