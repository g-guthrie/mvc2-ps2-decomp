typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern f32 *D_004C26D0;

typedef struct { u8 pad[0x34]; f32 f34, f38; u8 pad2[0x140 - 0x3C]; s16 h140; } PP;

static void func_00192E30(u8 *p) {
    PP *q = (PP *)p;
    q->f34 = (*(PP **)(p + 0x18))->f34;
    q->f38 = (*(PP **)(p + 0x18))->f38;
    if (q->h140 != 0) {
        q->f34 += D_004C26D0[0];
    } else {
        q->f34 -= D_004C26D0[0];
    }
    q->f38 += D_004C26D0[1];
}

void func_00192EA0(u8 *p)
{
    extern s32 func_001757E0(u8 *, s32, s32);
    s32 n;
    u32 *d, *s;
    f32 f;
    u32 t;
    d = (u32 *)(p + 0xEC);
    t = p[4];
    p[4] = t + 1;
    s = (u32 *)(*(u8 **)(p + 0x18) + 0xEC);
    for (n = 49; n > 0; n--) *d++ = *s++;
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
    p[0x13C] = 1;
    p[0x24] = (p[0x21] != 0) ? 0 : 0xB;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(s16 *)(p + 0x1C) = 0;
    f = p[0x20] ? -30.0f : 0.0f;
    D_004C26D0[0] = f;
    f = p[0x20] ? 34.2857132f : 0.0f;
    D_004C26D0[1] = f;
    func_00192E30(p);
    func_001757E0(p, 0x17, p[0x21] << 1);
}
