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
extern void func_00170DF0();
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

void func_001C6120(u8 *p, u8 *q) {
    u8 *v = q + 0x2B8;
    if (q[0x2C3] == 0 || v[0xA] != 0) {
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140) ^ 1;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = 102.857140f + *(f32 *)(q + 0x38);
        p[7] = 5;
        p[0] = 1;
        p[0x13C] = 1;
        if (*(s16 *)(p + 0x140) == 0) *(u32 *)(p + 0x5C) = 0xC0D55555;
        else *(u32 *)(p + 0x5C) = 0x40D55555;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0;
    }
    func_00175700(p);
}

void func_0014A640(void) {
    func_0014A700(0.7f, D_004F7F92, 4, D_00443E78, 0, 1.0f, 0.0f, 0.0f);
}
