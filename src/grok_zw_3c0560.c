typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *func_003DA750(u8 *, s32, s32);
extern void func_003C06A0(u8 *);
extern void func_001754A0(u8 *, s32, s32);

void func_003C0560(u8 *owner, u8 kind)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *p;
    u8 *o;
    if ((p = func_003DA750(owner, 1, 2)) != 0) {
        s32 tag = 0x3604;
        *(void **)(p + 0x10) = func_003C06A0;
        d = (s32 *)(p + 0xEC);
        *(u8 **)(p + 0x18) = owner;
        n = 0x31;
        p[1] = owner[1];
        p[0x20] = kind;
        *(s16 *)(p + 0x26) = (s16)tag;
        *(u8 **)(p + 0xD8) = *(u8 **)(owner + 0xD8);
        o = *(u8 **)(owner + 0xD8);
        s = (s32 *)(o + 0xEC);
        do {
            *d = *s;
            n--;
            s++;
            d++;
            asm { nop }
            asm { nop }
        } while (n > 0);
        p[0x13C] = 1;
        o = *(u8 **)(owner + 0xD8);
        p[2] = o[2];
        o = *(u8 **)(owner + 0xD8);
        p[1] = o[1];
        o = *(u8 **)(owner + 0xD8);
        *(f32 *)(p + 0x50) = *(f32 *)(o + 0x50);
        o = *(u8 **)(owner + 0xD8);
        *(f32 *)(p + 0x54) = *(f32 *)(o + 0x54);
        o = *(u8 **)(owner + 0xD8);
        p[0x1B7] = o[0x1B7];
        o = *(u8 **)(owner + 0xD8);
        p[0x1B8] = o[0x1B8];
        o = *(u8 **)(owner + 0xD8);
        *(s8 *)(p + 0x30) = *(s8 *)(o + 0x30);
        o = *(u8 **)(owner + 0xD8);
        *(V3 *)(p + 0x50) = *(V3 *)(o + 0x50);
        o = *(u8 **)(owner + 0xD8);
        *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
        p[0x13C] = 1;
        *(s16 *)(p + 0x140) = 0;
        p[0x24] = 8;
        func_001754A0(p, 0x1B, 0xF);
    }
}
