typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { f32 x, y, z; } V3_3120;
extern f32 D_004F1F4C[3];
extern f32 D_004F1F58[3];
extern f32 D_004F1F94[3];
extern f32 D_004F1FA0[3];
extern s32 D_004F1FB8;
extern f32 D_004F1FF4;
extern u8 D_004F2038;
extern u8 D_004F1F45;

void func_00123120(void)
{
    extern f32 func_004175C0(s32);
    extern s32 func_00126530(void);
    extern void func_00126400(void);
    extern void func_00126780(void);
    extern void func_00126080(s32);
    extern void func_00126A40(void);
    f32 r;
    *(V3_3120 *)D_004F1F58 = *(V3_3120 *)D_004F1F4C;
    *(V3_3120 *)D_004F1FA0 = *(V3_3120 *)D_004F1F94;
    D_004F1FB8 = 0;
    r = func_004175C0(0xF4A);
    D_004F1FF4 = 320.0f / r;
    if (D_004F2038 == 0) {
        D_004F2038 = 1;
    } else {
        if (func_00126530() != 0) {
            func_00126400();
        }
        func_00126780();
        func_00126080(D_004F1F45);
        func_00126A40();
    }
}
