typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u8 *D_004C2704;
extern void func_001BF550(u8 *p);
/* func_001BF860: not yet matched without a stand-in callee. */

extern s32 D_004BEDA0[];
s32 func_004166F0(u8 *p) {
    s32 x = *(u8 *)(*(u8 **)(p + 8) + 0x13);
    s32 r;
    if (x > 5) r = 0; else r = D_004BEDA0[(u8)x];
    return r;
}

extern const s32 D_004BEDC0[];
extern s32 func_00416770(void *owner, s32 scale);
/* func_004167A0: not yet matched without a stand-in callee. */

extern u32 *func_003F1F90(u32 *p, u32 key);

/* func_003F2510: not yet matched without a stand-in callee. */

u16 func_00220260(u8 *actor, s32 b) {
    u16 t = b & 0x3C00;
    u16 hi = (t & 0x3000) / 0x1000;
    u16 lo = (t & 0xC00) / 0x100;
    hi |= lo;
    return hi;
}
