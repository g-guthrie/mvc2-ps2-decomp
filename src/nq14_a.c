typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_003ECD00(s32);
static void func_00417FB0(void) { func_003ECD00(0); }

void func_0012FCC0(void)
{
    extern void func_004180F0(f32, f32, f32, f32);
    extern void func_00416AA0(s32, s32, s32, f32);
    func_004180F0(0.0f, 0.0f, 640.0f, 480.0f);
    func_00416AA0(0, 0, 0, 0.001f);
    func_00417FB0();
    func_004180F0(0.0f, 0.0f, 640.0f, 480.0f);
    func_00416AA0(0, 0, 0, 0.001f);
    func_00417FB0();
    func_004180F0(0.0f, 0.0f, 640.0f, 480.0f);
}
