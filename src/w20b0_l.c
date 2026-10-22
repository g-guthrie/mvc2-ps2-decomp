typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0044A260[];
extern s16 D_0044A262[];

void func_001952E0(u8 *a, u8 *b) {
    extern void func_00197600();
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_00195250(u8 *, u8 *);
    u32 t;
    t = a[5];
    a[5] = t + 1;
    if (a[0x21] < 4) {
        func_00197600();
        *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140);
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
        a[0x31] = 2;
        if (*(s16 *)(a + 0x140) != 0) {
            *(f32 *)(a + 0x34) -= 1.6666666f * (f32)D_0044A260[a[0x21] * 2] / 256.0f;
        } else {
            *(f32 *)(a + 0x34) += 1.6666666f * (f32)D_0044A260[a[0x21] * 2] / 256.0f;
        }
        *(f32 *)(a + 0x38) += 2.142857f * (f32)D_0044A262[a[0x21] * 2] / 256.0f;
        func_001754A0(a, 0x1B, 8);
        func_00195250(a, b);
    }
}
