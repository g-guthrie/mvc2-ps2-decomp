typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700();
extern void func_00134710();
extern f32 D_0043E8A0[];

void func_001345C0(u8 *p, u8 *q, u32 r) {
    f32 c = D_0043E8A0[r & 0xF];
    f32 a = 40.0f;
    f32 b = a - c;
    if (q[2] == 0) {
        b = -40.0f;
        a = b - c;
    }
    *(f32 *)(p + 0x34) = a;
    *(f32 *)(p + 0x70) = b;
    *(u32 *)(p + 0x38) = 0x40A00000;
    func_00134710(p, q, r);
}
