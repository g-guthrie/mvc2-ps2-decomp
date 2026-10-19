#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_001C9100(u8 *);
extern void func_001C92F0(u8 *);

void func_001C8FD0(u8 *p, u8 *flag)
{
    u8 *o;
    s32 n;
    s32 *d;
    s32 *s;
    o = func_003DA750(0, 3, 0);
    if (o == 0)
        return;
    *(u8 **)(o + 0x18) = p;
    *(u16 *)(o + 0x26) = 0x1E04;
    *(void **)(o + 0x10) = func_001C9100;
    if (flag == 0)
        return;
    d = (s32 *)(o + 0xEC);
    *(void **)(o + 0x10) = func_001C92F0;
    n = 0x31;
    s = (s32 *)(*(u8 **)(o + 0x18) + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
    } while (n > 0);
    o[0x13C] = 1;
    o[2] = (*(u8 **)(o + 0x18))[2];
    o[1] = (*(u8 **)(o + 0x18))[1];
    *(f32 *)(o + 0x50) = *(f32 *)(*(u8 **)(o + 0x18) + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(*(u8 **)(o + 0x18) + 0x54);
    o[0x1B7] = (*(u8 **)(o + 0x18))[0x1B7];
    o[0x1B8] = (*(u8 **)(o + 0x18))[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(*(u8 **)(o + 0x18) + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(*(u8 **)(o + 0x18) + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(*(u8 **)(o + 0x18) + 0x24);
    o[0x13C] = 0;
}
