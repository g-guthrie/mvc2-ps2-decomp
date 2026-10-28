typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B227c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G227c;
extern G227c *D_004C2794;
extern s16 D_004B8758[];

void func_0039E5C0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0039E550(u8 *);
    u8 *s;
    u8 *h;
    u8 *o;
    s16 *tb;
    s16 i;
    u32 t;

    if (p[0x20] != 0) {
        s = *(u8 **)(p + 0x14);
    } else {
        s = p;
        func_001E3710(*(u8 **)(p + 0x18), 0x4C);
    }
    h = s + 0x88;
    if (s[0x96] != 0) return;
    t = p[4];
    p[4] = t + 1;
    *(B227c *)(p + 0xEC) = *(B227c *)(*(u8 **)(p + 0x18) + 0xEC);
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
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x48;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[0x24] = 0;
    if (p[0x20] == 0) {
        p[0x14C] = 0x18;
        p[0x14D] = 0x10;
        p[0x14E] = 0x50;
        i = 0;
        p[0x14F] = 0x50;
        {
            u8 *r = *(u8 **)(p + 0x14);
            *(f32 *)(p + 0x34) = *(f32 *)(r + 0x34);
            *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38);
            *(s16 *)(p + 0x140) = *(s16 *)(r + 0x140);
        }
        for (; i < 7; i++) {
            if ((o = func_003DA750(p, 1, 2)) == 0) break;
            *(void (**)(u8 *))(o + 0x10) = func_0039E550;
            o[0x20] = 1;
            o[0x21] = i;
            *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
            *(u8 **)(o + 0x14) = p;
            *(s16 *)(o + 0x26) = 0x2801;
            o[1] = p[1];
        }
        *(s16 *)(h + 4) = i;
        func_001757E0(p, 0x16, 8);
        return;
    }
    p[0x14C] = 0x20;
    p[0x14D] = 0x20;
    p[0x14E] = 0x50;
    p[0x14F] = 0x50;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 8) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 8) + 0x38);
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 8) + 0x140);
    tb = D_004B8758;
    if ((*(u8 **)(p + 8))[0x20] != 0) tb += 2;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x34) -= 1.6666666269302368f * tb[0] / 256.0f;
    } else {
        *(f32 *)(p + 0x34) += 1.6666666269302368f * tb[0] / 256.0f;
    }
    *(f32 *)(p + 0x38) += 2.142857074737549f * tb[1] / 256.0f;
    if (p[0x21] & 1) {
        func_001757E0(p, 0x16, 9);
    } else {
        func_001757E0(p, 0x16, 0xA);
    }
}
