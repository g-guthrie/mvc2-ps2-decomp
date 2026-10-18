typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;

extern void func_001757E0(u8 *, s32, s32);
extern void func_0022F590(u8 *, u8 *);
extern void func_0019DE50(u8 *, s32, s32);
static void func_002304C0(u8 *p, u8 *q) {
    f32 a = 18.33333206f;
    f32 b = -0.8333333135f;
    if (*(s16 *)(p + 0x140) == 0) {
        a = -a;
        b = -b;
    }
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x68) = b;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
}
void func_002306E0(u8 *p, u8 *q) {
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    t = p[7];
    p[7] = t + 1;
    *(s8 *)(q + 0x14) = -0x79;
    p[0x169] = 0x16;
    p[0x168] = 0;
    func_001757E0(p, p[0x169], p[0x168]);
    func_0022F590(p, q);
    func_002304C0(p, q);
    func_0019DE50(p, 6, 0);
}
