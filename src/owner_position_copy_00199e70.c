/* Inherit the owner state and cached owner position, then start the follow-up phase. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_00199F50(u8 *);
void func_00199E70(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u8 *owner=*(u8**)(p+0x18);
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


    } while (n > 0);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x24]=7;
    *(f32*)(p+0x34)=*(f32*)(owner+0x34);
    *(f32*)(p+0x38)=*(f32*)(owner+0x38);
    func_00199F50(p);
}
