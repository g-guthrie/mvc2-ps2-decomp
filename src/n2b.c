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

u8 *func_001BAD80(u8 *a, s32 b) {
    u8 *r = func_003DA750(0, 4, 0);
    if (r) {
        *(void **)(r + 0x10) = func_001BAE90;
        *(u8 **)(r + 0x18) = a;
        *(s16 *)(r + 0x140) = *(s16 *)(*(u8 **)(r + 0x18) + 0x140);
        *(s16 *)(r + 0x26) = 0x1700;
        D_004C26F8 = (u16 *)(r + 0xD0);
        *D_004C26F8 = *(u16 *)(*(u8 **)(r + 0x18) + 0x168);
        r[0x23] = b;
        return r;
    }
    return 0;
}

void func_00140E90(u8 *a, V3 *v) {
    u8 *r = func_003DA750(0, 0xD, 1);
    if (r) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = func_00140F30;
        *(s16 *)(r + 0xCC) = 7;
        *(u8 **)(r + 0x84) = D_004C2818;
        *(u8 **)(r + 0xD0) = a;
        if (v) *(V3 *)(r + 0x34) = *v;
        func_00170DF0((u32)*(u8 **)(D_004C2818 + 0x14) + 0x4EC);
    }
}

void func_0018FB70(u8 *p, s16 a) {
    s32 k;
    s16 v;
    a = -a;
    k = 1;
    if (a > 13) k = 3;
    func_0016EDA0(p[2], k);
    func_0018F8C0(p, &a);
    v = *(s16 *)(p + 0x434) - a;
    *(s16 *)(p + 0x434) = v;
    if (v < 0) {
        *(s16 *)(p + 0x434) = 0;
        if (*(s8 *)(D_004C2840 + 0xAA)) {
            *(s16 *)(p + 0x434) = 1;
            if (*(s16 *)(p + 0x438) <= 0) *(s16 *)(p + 0x438) = 1;
        }
    }
}
