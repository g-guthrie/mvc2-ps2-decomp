typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C283C;
extern u8 *D_004C2840;
extern void func_00170E60(s32, s32, s32, s32, s32, u8 *);
extern void func_00330380(void);

void func_003302E0(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x84);
    u8 *t = *(u8 **)(p + 0x1C);
    func_00170E60(*(s32 *)(D_004C283C + 0x14), *(s32 *)(t + 0x3C), *(s32 *)(p + 0x14), *(s32 *)(t + *(s16 *)(a0 + 0xCC) * 4), (s32)func_00330380, a0);
}



extern u8 D_004C1848[2];
extern u8 D_004C1849[2];
extern void func_00186A60(u8 *, s32);


extern void func_00134C60(s32);
extern void func_00134D30(s32);
void func_00134C10(void)
{
    if (*(s8 *)(D_004C2840 + 0x4D) != 3) func_00134C60(0);
    func_00134C60(1);
    func_00134D30(0);
    func_00134D30(1);
}

extern u8 *D_004C2938;


extern void (*D_004C20C0[2])(void);
extern void func_003BD830(u8 *);
void func_003BCAE0(u8 *a0)
{
    if (*(u8 *)(*(u8 **)(a0 + 0x18) + 0x25C) != 0) {
        func_003BD830(a0);
    } else {
        D_004C20C0[*(u8 *)(a0 + 4)]();
    }
}

extern void (*D_004C15D0[2])(u8 *);
extern s32 func_003D92F0(u8 *);
extern void func_001843A0(u8 *);
void func_0030A940(u8 *a0)
{
    if (func_003D92F0(a0)) {
        func_001843A0(a0);
    } else {
        D_004C15D0[*(u8 *)(a0 + 6)](a0);
    }
}

extern void (*D_004C1D28[2])(u8 *, u8 *);
void func_0037E750(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x18);
    if (*(u8 *)(p + 4) >= 2) {
        *(u8 *)(a0 + 4) += 1;
        *(u8 *)(a0 + 0x13C) = 0;
    } else {
        D_004C1D28[*(u8 *)(a0 + 5)](a0, p);
    }
}

typedef struct { float x, y, z; } V3;
extern V3 D_00444A88;
extern void func_001E3520(u8 *, s32);
void func_00155800(u8 *a0)
{
    *(s32 *)(a0 + 0xD0) = 0x3D;
    *(s16 *)(a0 + 0xCC) = 0x5A;
    *(u8 **)(a0 + 0x84) = D_004C283C;
    *(s32 *)(a0 + 0x74) = 0x3F800000;
    *(V3 *)(a0 + 0x50) = D_00444A88;
    *(s16 *)(a0 + 0x1E) = 0xD2;
    func_001E3520(a0, 0x10);
}
