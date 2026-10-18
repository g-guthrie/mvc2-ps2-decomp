typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;
typedef float f32;
extern u8 D_004D17CA; extern f32 D_004F7FD0, D_004F7FD4;
extern void func_00417CB0(f32, f32, f32, f32, f32, u32, u32, u32, u32);
void func_004212D0(s32 x) {
    f32 p, q;
    if (D_004D17CA == 1) {
        p = 344.0f + 1.5f * D_004F7FD0;
        q = (f32)x + D_004F7FD4;
        func_00417CB0(p, q, 0.9f, 48.0f, 26.0f, 0x8000FF00, 0x8000FF00, 0x8000FF00, 0x8000FF00);
    } else if (D_004D17CA == 0) {
        func_00417CB0(256.0f + 1.5f * D_004F7FD0, (f32)x + D_004F7FD4, 0.9f, 48.0f, 26.0f, 0x8000FF00, 0x8000FF00, 0x8000FF00, 0x8000FF00);
    }
}
