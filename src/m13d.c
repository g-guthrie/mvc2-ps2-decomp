typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern double func_00119058(f32);

void func_001EA9F0(u8 *p) {
    f32 v = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00119058(v * *(f32 *)(p + 0x5C)) < 0.0) {
        func_001843A0(p);
    } else {
        func_00175700(p);
    }
}
