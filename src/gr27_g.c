typedef unsigned char u8;
typedef signed int s32; typedef unsigned int u32;
typedef float f32;

extern f32 D_004F8060;
extern f32 D_004F8064;
extern f32 D_004F8068;
extern f32 D_004F806C;
extern f32 D_004F8070;
extern f32 D_004F8074;
extern f32 D_004F8078;
extern f32 D_004F807C;
extern f32 D_004F8080;
extern f32 D_004F8084;
extern f32 D_004F8088;
extern f32 D_004F808C;
extern f32 D_004F8090;
extern f32 D_004F8094;
extern f32 D_004F8098;
extern f32 D_004F809C;
extern f32 D_004F80A0;
extern f32 D_004F80A4;
extern f32 D_004F80A8;

void func_00414AA0(void)
{
    extern void func_003DF850(s32, f32 *);
    f32 *d;

    D_004F8060 = 0.0f;
    D_004F8080 = 0.0f;
    D_004F8070 = 1.0f;
    D_004F8064 = 1.0f;
    D_004F8068 = 1.0f;
    D_004F806C = 1.0f;
    D_004F8074 = 0.0f;
    D_004F8078 = 0.0f;
    D_004F807C = 0.0f;
    D_004F8090 = 1.0f;
    D_004F8084 = 1.0f;
    D_004F8088 = 1.0f;
    D_004F808C = 1.0f;
    D_004F80A0 = 10000.0f;
    D_004F80A8 = 10000.0f;
    D_004F8094 = 1.0f;
    D_004F80A4 = -10000.0f;
    D_004F8098 = 0.0f;
    D_004F809C = -1.0f;
    d = (f32 *)((u32)&D_004F8060);
    func_003DF850(0x59, d);
    D_004F80A0 = -10000.0f;
    D_004F80A4 = -10000.0f;
    D_004F80A8 = 10000.0f;
    D_004F8094 = -1.0f;
    D_004F8098 = 0.0f;
    D_004F809C = -1.0f;
    func_003DF850(0x5A, d);
    D_004F80A0 = 0.0f;
    D_004F80A4 = -10000.0f;
    D_004F8098 = -1.0f;
    D_004F80A8 = 0.0f;
    D_004F8094 = 0.0f;
    D_004F809C = -1.0f;
    func_003DF850(0x5B, d);
    func_003DF850(1, 0);
    func_003DF850(2, 0);
}
