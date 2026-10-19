typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001D04F0(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001D02E0(u8 *);

void residual_001D01D0(u8 *p)
{
    u8 *g;
    s32 n;
    s32 *s;
    s32 *d;
    p[4]++;
    g = *(u8 **)(*(u8 **)(p + 0x18) + 0x1CC);
    if (g[1] != 0x28) {
        func_001D04F0(p);
        return;
    }
    s = (s32 *)(g + 0xEC);
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
    } while (n > 0);
    p[0x13C] = 1;
    p[2] = g[2];
    p[1] = g[1];
    *(f32 *)(p + 0x50) = *(f32 *)(g + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(g + 0x54);
    p[0x1B7] = g[0x1B7];
    p[0x1B8] = g[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(g + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(g + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(g + 0x24);
    *(u8 **)(p + 0x14) = g;
    *(s16 *)(p + 0x140) = *(s16 *)(g + 0x140);
    *(s8 *)(p + 0x31) = -1;
    func_001757E0(p, 0x17, 7);
    func_001D02E0(p);
}
