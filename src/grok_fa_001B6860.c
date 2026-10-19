typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001754A0(u8 *, s32, s32);
extern s8 func_00175670(u8 *);
extern void func_001B6F10(u8 *);
extern void func_001B6F30(u8 *);

void func_001B6860(u8 *p)
{
    switch (p[4]) {
    case 0: {
        s32 n;
        s32 *d;
        s32 *s;
        u8 *q;
        u8 one = 1;
        u32 t = p[4];
        p[4] = t + 1;
        d = (s32 *)(p + 0xEC);
        n = 0x31;
        q = *(u8 **)(p + 0x18);
        s = (s32 *)(q + 0xEC);
        do {
            *d = *s;
            n--;
            s++;
            d++;
            asm { nop }
            asm { nop }
        } while (n > 0);
        p[0x13C] = one;
        p[2] = (*(u8 **)(p + 0x18))[2];
        p[1] = (*(u8 **)(p + 0x18))[1];
        *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
        p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
        p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
        p[0x13C] = one;
        func_001754A0(p, 0x1B, 2);
        *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
        break;
    }
    case 1:
        if ((s8)func_00175670(p) < 0)
            func_001B6F10(p);
        break;
    case 2:
        func_001B6F30(p);
        break;
    }
}
