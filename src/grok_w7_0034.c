typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_00341890(void);
extern void func_00343250(void);
extern void func_003433A0(void);
extern void func_00343770(void);
extern void func_003450C0(void);
extern void func_003458A0(void);
extern void func_00346820(void);
extern void func_00346AC0(void);
extern void func_00347280(void);
extern void func_00348F20(void);
extern void func_0034A1B0(void);
extern s32 D_004C283C;
extern u8 *D_004C2938;

void func_003418A0(void)
{
    u8 *p = func_003DA750(0, 5, 0);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_00341890;
        *(s16 *)(p + 204) = 18;
        *(s32 *)(p + 132) = D_004C283C;
        *(s32 *)(p + 208) = 0x800;
    }
}

void func_00343330(s32 a0)
{
    u8 *p = func_003DA750(0, 6, 0);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_00343250;
        *(s16 *)(p + 204) = (s16)(a0 + 34);
        *(s32 *)(p + 132) = D_004C283C;
        *(s32 *)(p + 208) = 0x801;
        p[32] = (u8)a0;
    }
}

void func_00343700(s32 a0)
{
    u8 *p = func_003DA750(0, 6, 0);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_003433A0;
        *(s16 *)(p + 204) = (s16)(a0 + 50);
        *(s32 *)(p + 132) = D_004C283C;
        *(s32 *)(p + 208) = 0x801;
        p[32] = (u8)a0;
    }
}

void func_00343960(s32 a0)
{
    u8 *p = func_003DA750(0, 6, 0);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_00343770;
        *(s16 *)(p + 204) = (s16)(a0 + 58);
        *(s32 *)(p + 132) = D_004C283C;
        *(s32 *)(p + 208) = 0x801;
        p[32] = (u8)a0;
    }
}

void func_00345180(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_003450C0;
        *(s16 *)(p + 204) = 0;
        *(s32 *)(p + 132) = D_004C283C;
        *(s32 *)(p + 208) = 0xC01;
        *(s32 *)(p + 120) = 0;
        *(s32 *)(p + 124) = 0x3F800000;
        *(s32 *)(p + 128) = 0;
        *(s32 *)(p + 116) = 0x3F800000;
    }
}

void func_00345830(u8 *a0, s32 a1)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p) {
        *(void **)(p + 16) = func_003458A0;
        p[32] = (u8)a1;
        *(u8 **)(p + 24) = a0;
        p[1] = a0[1];
        *(s16 *)(p + 38) = 0;
        *(s16 *)(p + 208) = *(u16 *)(a0 + 360);
    }
}

void func_003467C0(u8 *a0)
{
    u8 *p = func_003DA750(0, 1, 1);
    if (p) {
        *(void **)(p + 16) = func_00346820;
        *(u8 **)(p + 24) = a0;
        p[1] = a0[1];
        p[32] = 0;
        p[33] = 0;
        *(s16 *)(p + 38) = 0x100;
    }
}

void func_00346A60(u8 *a0)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p) {
        *(void **)(p + 16) = func_00346AC0;
        *(u8 **)(p + 24) = a0;
        p[1] = a0[1];
        p[32] = 0;
        p[33] = 0;
        *(s16 *)(p + 38) = 0x101;
    }
}

void func_00345FE0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    *(float *)(p + 52) = *(float *)(q + 52);
    q = *(u8 **)(p + 24);
    *(float *)(p + 56) = *(float *)(q + 56);
    *(float *)(p + 52) += *(float *)(D_004C2938 + 8);
    *(float *)(p + 56) += *(float *)(D_004C2938 + 12);
}

void func_00347220(u8 *a0, s32 a1)
{
    u8 *p = func_003DA750((s32)a0, 1, 2);
    if (p) {
        *(void **)(p + 16) = func_00347280;
        *(s32 *)(p + 24) = *(s32 *)(a0 + 24);
        *(u8 **)(p + 20) = a0;
        *(s16 *)(p + 38) = 0x201;
        p[32] = (u8)a1;
    }
}

void func_00348E40(u8 *a0)
{
    u8 *p = func_003DA750((s32)a0, 1, 2);
    if (p) {
        *(void **)(p + 16) = func_00348F20;
        *(s32 *)(p + 24) = *(s32 *)(a0 + 24);
        *(u8 **)(p + 20) = a0;
        p[1] = a0[1];
        p[32] = 2;
        p[33] = 0;
        *(s16 *)(p + 38) = 0x301;
    }
}

void func_00348EB0(u8 *a0)
{
    u8 *p = func_003DA750((s32)a0, 1, 2);
    if (p) {
        *(void **)(p + 16) = func_00348F20;
        *(s32 *)(p + 24) = *(s32 *)(a0 + 24);
        *(u8 **)(p + 20) = a0;
        p[1] = a0[1];
        p[32] = 5;
        p[33] = 0;
        *(s16 *)(p + 38) = 0x301;
    }
}

void func_0034A0D0(u8 *a0)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p) {
        *(void **)(p + 16) = func_0034A1B0;
        *(u8 **)(p + 24) = a0;
        *(u8 **)(p + 20) = a0;
        p[1] = a0[1];
        p[32] = 0;
        p[33] = 0;
        *(s16 *)(p + 38) = 0x302;
        *(float *)(p + 92) = *(float *)(a0 + 52);
    }
}

void func_003460D0(u8 *p)
{
    s16 v = *(s16 *)(p + 28) - 1;
    *(s16 *)(p + 28) = v;
    if (v <= 0) {
        *(s16 *)(p + 28) = 2;
        (*(s8 *)D_004C2938)--;
    }
}
