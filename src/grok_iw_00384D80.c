#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 D_00464730[];
extern u8 *D_004C29AC __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, s32, s32);
extern void func_00384ED0(u8 *);

void residual_00384D80(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u32 t;

    n = 0x31;
    t = p[4];
    d = (s32 *)(p + 0xEC);
    p[4] = t + 1;
    p[0x13C] = 0;
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
    } while (n > 0);
    n = 1;
    p[0x13C] = (u8)n;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x18) + 0x140);
    p[0x24] = 0;
    *(u16 *)D_004C29AC = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    func_001757E0(p, 0x17, D_00464730[p[0x21] * 4]);
    func_00384ED0(p);
}
