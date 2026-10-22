typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x160]; s8 b[8]; } Sfb80a;
typedef struct { u8 p0[8]; s32 w8; u8 pc[0x16]; u16 h22, h24, h26, h28, h2a, h2c; } Efb80a;
extern u8 D_004F54D0[];

void func_00254EE0(u8 *a)
{
    extern void func_002552F0(u8 *, s32);
    extern void func_00255300(u8 *, s32);
    extern void func_00255310(u8 *, s32);
    s8 *p;
    s8 *q;
    s8 f;
    Efb80a *e;
    e = (Efb80a *)(D_004F54D0 + (*(s16 *)(a + 0x13E) + 1) * 0x30);
    p = ((Sfb80a *)a)->b;
    q = p + 1;
    f = p[1];
    if (f == 1) {
        e->w8 = 1;
        e->h22 |= (u16)0xF000;
        e->h24 |= 0xF000;
        e->h26 |= 0xF000;
        e->h28 |= 0xF000;
        e->h2c |= 0xF000;
    }
    if (q[0] == 2) {
        func_002552F0(a, 10);
    }
    if (q[0] == 3) {
        func_002552F0(a, 11);
    }
    if (q[0] == 4) {
        func_002552F0(a, 12);
    }
    if (q[0] == 5) {
        func_002552F0(a, 10);
    }
    if (q[0] == 6) {
        func_002552F0(a, 10);
        func_002552F0(a, 12);
    }
    if (q[0] == 7) {
        func_002552F0(a, 12);
    }
    if (q[0] == 8) {
        func_002552F0(a, 10);
        func_002552F0(a, 12);
    }
    if (q[0] == 9) {
        func_002552F0(a, 9);
        func_002552F0(a, 10);
    }
    if (q[0] == 10) {
        func_002552F0(a, 9);
        func_00255310(a, 10);
    }
    if (q[0] == 11) {
        func_002552F0(a, 9);
        func_002552F0(a, 10);
    }
    if (q[0] == 12) {
        func_002552F0(a, 12);
        func_002552F0(a, 14);
    }
    if (q[0] == 13) {
        func_002552F0(a, 9);
    }
    if (q[0] == 14) {
        func_002552F0(a, 10);
        func_002552F0(a, 12);
        func_002552F0(a, 14);
    }
    if (q[0] == 15) {
        func_002552F0(a, 9);
        func_002552F0(a, 12);
    }
    if (q[0] == 16) {
        func_00255300(a, 10);
        func_00255300(a, 12);
    }
    if (q[0] == 50) {
        func_00255310(a, 10);
    }
    if (q[0] == 52) {
        func_00255310(a, 12);
    }
    if (q[0] == 53) {
        func_00255310(a, 10);
    }
    if (q[0] == 54) {
        func_00255310(a, 10);
        func_00255310(a, 12);
    }
    if (q[0] == 55) {
        func_00255310(a, 12);
    }
    if (q[0] == 56) {
        func_00255310(a, 10);
        func_00255310(a, 12);
    }
    if (q[0] == 57) {
        func_00255310(a, 9);
        func_00255310(a, 10);
    }
    if (q[0] == 59) {
        func_00255310(a, 9);
        func_00255310(a, 10);
    }
    if (q[0] == 60) {
        func_00255310(a, 12);
        func_00255310(a, 14);
    }
    if (q[0] == 61) {
        func_00255310(a, 9);
    }
    if (q[0] == 62) {
        func_00255310(a, 10);
        func_00255310(a, 12);
        func_00255310(a, 14);
    }
    if (q[0] == 63) {
        func_00255310(a, 9);
        func_00255310(a, 12);
    }
}
