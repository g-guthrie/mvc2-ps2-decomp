typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w188_j.c "-O3 -Op -sdatathreshold 8" */

extern u8 *D_004C283C;
void func_003305E0(u8 *a) {
    f32 z;
    f32 c;
    f32 k;
    f32 q;
    f32 t;
    u8 *s;
    extern f32 func_00417F60(void);
    extern f32 func_00117078(f32);
    extern void func_00170E60(u8 *, s32, s32, s32, void (*)(void), u8 *);
    extern void func_00330820(void);
    switch (a[4]) {
    case 0:
        *(s16 *)(a + 0x1C) = *(s16 *)(a + 0x1C) + 5;
        if (*(s16 *)(a + 0x1C) >= 0x168) *(s16 *)(a + 0x1C) = 0;
        *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x60);
        z = 0.0f;
        if (*(f32 *)(a + 0x60) > z) {
            c = -4.999999873689376e-06f;
            *(f32 *)(a + 0x60) = *(f32 *)(a + 0x60) + c;
        }
        k = 4.999999873689376e-05f;
        if (*(f32 *)(a + 0x5C) <= k) {
            *(f32 *)(a + 0x5C) = 0.0f;
            q = 9.999999747378752e-05f;
            t = q * func_00417F60() - 4.999999873689376e-05f;
            *(f32 *)(a + 0x60) = func_00117078(t + (9.999999747378752e-05f * func_00417F60() - 4.999999873689376e-05f));
        }
        s = *(u8 **)(a + 0x84);
        func_00170E60(*(u8 **)((u8 *)D_004C283C + 0x14), *(s32 *)((a[0x20] << 3) + (s32)*(u8 **)(s + 0x1C) + 0x24), *(s32 *)(s + 0x14), *(s32 *)((s32)*(u8 **)(s + 0x1C) + *(s16 *)(a + 0xCC) * 4), func_00330820, a);
        break;
    case 1:
        break;
    default:
        break;
    }
}
