typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern V3 D_005BF2A8;
extern V3 D_005BF2B8;

s32 func_003DEAF0(u8 *p, u8 *base, s32 idx) {
    extern void func_003F38A0(u8 *, V3 *, V3 *);
    extern void func_003F3BE0(u8 *, f32, f32, f32);
    V3 a, b;
    u8 *r;
    r = base + 0x10;
    r += idx * 64;
    a = D_005BF2A8;
    b = D_005BF2B8;
    a.x = *(f32 *)(r + 0x20);
    a.y = *(f32 *)(r + 0x24);
    a.z = *(f32 *)(r + 0x28);
    b.x = *(f32 *)(r + 0x30);
    b.y = *(f32 *)(r + 0x34);
    b.z = *(f32 *)(r + 0x38);
    func_003F38A0(p + 0x54, &D_005BF2B8, &a);
    *(f32 *)(p + 0x54) = *(f32 *)(r + 0x10);
    *(f32 *)(p + 0x68) = *(f32 *)(r + 0x14);
    *(f32 *)(p + 0x7C) = *(f32 *)(r + 0x18);
    func_003F3BE0(p + 0x54, a.x, a.y, a.z);
    *(f32 *)(p + 0x84) = b.x;
    *(f32 *)(p + 0x88) = b.y;
    *(f32 *)(p + 0x8C) = b.z;
    *(s32 *)(p + 0x180) = *(s16 *)(r + 0xA);
    *(s16 *)(p + 4) = *(s16 *)(r + 0);
    *(u16 *)(p + 6) = *(u16 *)(r + 2);
    *(s16 *)(p + 0x18E) = *(s16 *)(r + 6);
    *(s16 *)(p + 0x18C) = *(s16 *)(r + 8);
    *(f32 *)(p + 0x11C) = *(f32 *)(r + 0x10);
    *(f32 *)(p + 0x120) = *(f32 *)(r + 0x14);
    *(f32 *)(p + 0x124) = *(f32 *)(r + 0x18);
    *(f32 *)(p + 0x128) = *(f32 *)(r + 0x20);
    *(f32 *)(p + 0x12C) = *(f32 *)(r + 0x24);
    *(f32 *)(p + 0x130) = *(f32 *)(r + 0x28);
    *(f32 *)(p + 0x134) = *(f32 *)(r + 0x30);
    *(f32 *)(p + 0x138) = *(f32 *)(r + 0x34);
    *(f32 *)(p + 0x13C) = *(f32 *)(r + 0x38);
    *(s32 *)(p + 0x118) = 0;
    *(s32 *)(p + 0x114) = 0;
    return 1;
}
