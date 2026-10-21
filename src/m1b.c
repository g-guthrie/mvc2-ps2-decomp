typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 *D_004C2840;
extern void func_001325A0(u8 *, s16 *, s32);

void func_00131AB0(u8 *a, s16 *b, s32 c) {
    if (D_004C2840[5] != 0x40) {
        func_001325A0(a,b,c);
    }
}

extern void (*D_004773A0[])(s8 *, s32);
extern void func_003D5350();
extern void func_003D7310(void *);

void func_003D6340(s8 *p, s8 *q) {
s32 f = 0;
((u8 *)D_004C2840)[0x91] = 1;
p[0x18] = 1;
if (p[0] != 1) f = 1;
D_004773A0[q[0]](q, f);
func_003D7310(func_003D5350);
}

extern s8 D_004C2854;
extern s32 func_0012ABC0(s32, s32);
extern s32 func_0012A990(s32, s32, s32, s32);
extern void func_001E46D0(s32);

void func_0012A3A0(u8 *p) {
    D_004C2854 = func_0012A990(func_0012ABC0(3, 0), D_004C2854, 7, 2);
    if (*(s8 *)(p + 0x41) != D_004C2854) {
        func_001E46D0((u8)(D_004C2854 * 35));
        p[0x41] = D_004C2854;
    }
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B7F58;
extern s32 D_004C283C;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003353E0();

void func_00335640(u8 *p) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003353E0;
        *(s16 *)(o + 0xCC) = 0x24;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x805;
        *(V3 *)(o + 0x34) = D_004B7F58;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}
