typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

#pragma padloop on

extern s8 D_004BFA44[8];
extern s8 D_004BFA48[8];

typedef struct { u8 pad[0x34]; f32 f34; } LF;
static void func_001C8D60(u8 *a) {
    LF *sa;
    *(float *)(a + 0x34) = *(float *)(*(u8 **)(a + 0x18) + 0x34);
    *(float *)(a + 0x38) = *(float *)(*(u8 **)(a + 0x18) + 0x38);
    if (*(s16 *)(*(u8 **)(a + 0x18) + 0x140) != 0) {
        sa = (LF *)a;
        sa->f34 = sa->f34 + 1.6666666f * (float)D_004BFA44[a[0x20]];
    }
    ((s8 *)a)[0x24] = ((s8 *)*(u8 **)(a + 0x18))[0x24];
    ((s8 *)a)[0x31] = -1;
}

void func_001C8DE0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    s32 n;
    u32 *d;
    u32 *r;
    u32 t;
    t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    d = (u32 *)(p + 0xEC);
    r = (u32 *)(q + 0xEC);
    n = 49;
    for (; n > 0; --n) {
        *d++ = *r++;
    }
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = 1;
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24) + 8;
    *(s16 *)(p + 0x140) = 0;
    func_001C8D60(p);
    func_001757E0(p, 0x17, D_004BFA48[p[0x20]]);
}
