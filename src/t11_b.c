typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct V3 { f32 x, y, z; } V3;

extern s32 D_004C283C;
extern V3 D_004B7B20;
extern V3 D_004B8290;
extern u8 D_00453980[];
extern u8 D_004571B0[];
extern s32 func_00175700();
extern void func_001843A0();
extern void func_0024EDA0();
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern void func_0031D200();
extern u8 *func_003DA750();
extern void func_003327F0();
extern void func_0033EF10();
extern void func_003349D0();
extern void func_00363C30();
extern void func_00294B20();
extern void func_001830D0();
extern void func_001757E0();
extern void func_001EC280();


s32 func_0025C620(u8 *p) {
    if (func_00189310(p, D_00453980, p + 0x398) == 0) return 0;
    if (p[0x2B9] != 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    func_0018A990(p, p + 0x398);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 4;
    func_00186A60(p, 0x1D);
    return 1;
}

