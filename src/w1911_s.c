typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef float f32;
typedef int s32;
typedef struct { f32 x, y, z; } V3;
typedef struct { V3 r[3]; } Row;
extern Row D_00440090[];
extern s32 D_004C2830;
typedef void (*Mvc2StateHandler)(u8 *);
extern const Mvc2StateHandler jtbl_00440240[];
extern const Mvc2StateHandler jtbl_00440260[];
void func_0013A9D0(u8 *p) {
    u8 *state = *(u8 **)(p + 0x18);
    jtbl_00440240[state[4]](p);
}

void func_0013AA00(u8 *p) {
    u8 *context = *(u8 **)(p + 0x18);
    *(s8 *)(p + 0x13C) = *(s8 *)(context + 0x13C);
}

void func_0013ABD0(u8 *p) {
    u8 *state = *(u8 **)(p + 0x18);
    jtbl_00440260[state[4]](p);
}

void func_0013A610(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0013A760(u8 *);
    u8 *o;
    s32 i;
    u8 *q;
    s16 j;
    s32 off;
    q = *(u8 **)(p + 0x14);
    off = 0;
    i = 0;
    while ((j = i) < 3) {
        if ((o = func_003DA750(0, 6, 1)) == 0) return;
        *(u8 **)(o + 0x18) = p;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(s32 *)(o + 0x14) = *(s32 *)(p + 0x14);
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0013A9D0;
        o[0x20] = p[0x20];
        o[0x21] = i;
        o[0x1] = *(s8 *)(q + 0x540);
        *(s16 *)(o + 0xCC) = j + 0x63;
        *(s32 *)(o + 0x84) = D_004C2830;
        *(V3 *)(o + 0x34) = *(V3 *)((u8 *)&D_00440090[o[0x20]] + off);
        *(s32 *)(o + 0x40) = 0x2000;
        *(s32 *)(o + 0x44) = 0;
        *(s32 *)(o + 0x48) = 0;
        *(s32 *)(o + 0xD0) = 0x813;
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3C23D70A;
        *(u32 *)(o + 0x58) = 0x3F800000;
        func_0013A760(o);
        i = (s16)(i + 1);
        off += 12;
    }
}
