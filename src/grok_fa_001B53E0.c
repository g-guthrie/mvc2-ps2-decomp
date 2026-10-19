typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void *func_003DA750(void *, int, int);
extern void func_001B5540(u8 *);

void func_001B53E0(u8 *owner, u8 a1, u8 a2)
{
    u8 *p = func_003DA750(0, 3, 0);
    if (p) {
        s32 n;
        s32 *d;
        s32 *s;
        u8 one = 1;
        d = (s32 *)(p + 0xEC);
        *(void (**)(u8 *))(p + 16) = func_001B5540;
        n = 0x31;
        *(u8 **)(p + 24) = owner;
        s = (s32 *)(*(u8 **)(p + 24) + 0xEC);
        do {
            *d = *s;
            n--;
            s++;
            d++;
            asm { nop }
            asm { nop }
        } while (n > 0);
        p[0x13C] = one;
        p[2] = (*(u8 **)(p + 24))[2];
        p[1] = (*(u8 **)(p + 24))[1];
        *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 24) + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 24) + 0x54);
        p[0x1B7] = (*(u8 **)(p + 24))[0x1B7];
        p[0x1B8] = (*(u8 **)(p + 24))[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 24) + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 24) + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 24) + 0x24);
        *(s16 *)(p + 0x26) = 0x1402;
        p[0x14D] = 0x20;
        p[0x14C] = 0x20;
        p[0x14F] = 0x24;
        p[0x14E] = 0x24;
        p[0x20] = a1;
        p[4] = one;
        p[5] = a2;
        *(u16 *)(p + 0xD0) = *(u16 *)(owner + 0x168);
        p[0xD1] = owner[0x169];
        *(f32 *)(p + 0x34) = *(f32 *)(owner + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(owner + 0x38);
    }
}
