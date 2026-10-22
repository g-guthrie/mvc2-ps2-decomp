typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700();
extern s32 func_00175670();
extern int func_00174470(const void *);
extern s32 func_001AFC90();
extern void func_00186A60();
extern void func_001757E0();
extern void func_0014A700(f32, u16, s32, void *, s32, f32, f32, f32);
extern volatile u16 D_004F7F92;
extern u8 D_00443E78[];
extern void *func_003DA750();
extern void func_003802E0();
extern s32 func_00189310();
extern u8 D_00454120[];
extern s32 func_00191210();
extern void (*D_004543F0[])();
extern u8 D_00465260[];
extern s32 D_00471978[];
extern s32 func_0019B710();
extern void func_0019B740();
extern void func_00183d50();
extern void func_003C80C0();
extern u16 *D_004C26F8;
extern void func_001BAE90();
extern u8 *D_004C2840;
extern u8 D_00448EE0[];
extern void func_0018A990();
extern void func_0011D8F8();
typedef struct { u8 pad[0x24A]; s8 f; } S24A;
extern void func_00376AE0();
extern u8 *D_004C2818;
extern void func_00140F30();
extern void func_00170DF0(u32);
typedef struct { f32 x, y, z; } V3;
extern u8 D_0044F260[];
extern void func_00168E80();
extern void func_001695A0();
extern s32 func_00169850();
extern void func_001EB470();
extern void func_00183920();
extern void func_001E3710();
extern f32 D_004B3380[];
extern void func_0016EDA0();
extern void func_0018F8C0();
extern void func_002A70B0();
extern void func_00175910();
extern void (*D_0044BDE0[])();

s32 func_00262BB0(u8 *p) {
    if (!func_00189310(p, D_00454120, p + 0x3B0)) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    p[0x26C] = 7;
    *(u16 *)(p + 0x2C2) = 0xF0;
    return 1;
}

s32 func_001E9160(u8 *p) {
    u8 *q = p + 0x2B8;
    if (!func_00189310(p, D_0044F260, p + 0x378)) return 0;
    if (p[0x210] == 0) {
        if (q[2] != 0) return 0;
    }
    func_0018A990(p, p + 0x378);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}
