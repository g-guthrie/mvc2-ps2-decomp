typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 D_00472300[];
extern u8 *D_004C29DC __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, s32, s32);
extern void func_00394CD0(u8 *);

void residual_00394BA0(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u32 t;
    s32 a;

    n = 0x31;
    t = p[4];
    d = (s32 *)(p + 0xEC);
    p[4] = t + 1;
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
    } while (n > 0);
    a = 1;
    p[0x13C] = (u8)a;
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
    *(u16 *)D_004C29DC = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    p[0x24] = 0;
    func_001757E0(p, 0x17, D_00472300[p[0x20] * 4]);
    func_00394CD0(p);
}
