typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x30];
    u32 w30;
    u32 w34;
    u32 w38;
    u32 w3c;
} GG;

typedef struct {
    u8 pad0[0x538];
    s8 b538;
    u8 pad1[0x1F];
    u32 w558;
    u32 w55c;
    u32 w560;
    u32 w564;
} PP;

extern GG *D_004C2840;
extern u32 D_00583BCC[];
extern u32 D_00583BD0[];
extern u32 D_00583BA0[];
extern u32 D_00583BB0[];
extern u32 D_00583BA4[];
extern u32 D_00583BB4[];
extern u8 D_00583B9D[];
extern u8 D_004F20B0[];
extern u8 D_00583B90[];

#define AT(a, i) (*(u32 *)((u8 *)(a) + (i) * 8))

void func_0032D730(PP *p)
{
    extern u8 func_0032D620(u32 *, s32);
    u32 v;
    u32 a, b, c, d;
    s8 i;
    s32 j;

    a = p->w558 | D_004C2840->w30;
    b = p->w55c | D_004C2840->w34;
    c = p->w560 | D_004C2840->w38;
    d = p->w564 | D_004C2840->w3c;
    AT(D_00583BCC, p->b538) = 0;
    AT(D_00583BD0, p->b538) = 0;
    AT(D_00583BA0, p->b538) = a | 0xFFFF77;
    AT(D_00583BB0, p->b538) = AT(D_00583BA0, p->b538);
    AT(D_00583BA4, p->b538) = b | 0x2000004;
    AT(D_00583BB4, p->b538) = AT(D_00583BA4, p->b538);
    AT(D_00583BCC, p->b538) |= c;
    AT(D_00583BD0, p->b538) |= d;
    if (AT(D_00583BA0, p->b538) == 0xF8FFFFFF
        && AT(D_00583BA4, p->b538) == 0x7FFFFFF
        && AT(D_00583BCC, p->b538) == 0xF8FFFFFF
        && AT(D_00583BD0, p->b538) == 0x7FFFFFF) {
        D_00583B9D[0] = 1;
    }
    i = 0;
    j = 0;
    while (i < 3) {
        u8 r = func_0032D620(&v, *(s8 *)(D_004F20B0 + (p->b538 + j) * 0x5B8 + 0x540));
        *(u32 *)(D_00583B90 + p->b538 * 8 + r * 4 + 0x10) |= v;
        j += 2;
        i++;
    }
}
