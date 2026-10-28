typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 w[0x31]; } W31;
typedef struct { f32 x, y, z; } V3;
extern u16 *D_004C2990;
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } PS;

void residual_003794A0(u8 *p) {
    extern void func_001757E0(u8 *, s32, u8);
    f32 v;
    u32 t = p[4]; p[4] = t + 1;
    *(W31 *)(p + 0xEC) = *(W31 *)(*(u8 **)(p + 0x18) + 0xEC);
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
    p[0x1B0] = 0x43;
    p[0x1B1] = 0;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    if (*(s16 *)(p + 0x140) != 0) {
        ((PS *)p)->f34 += 6.666666507720947f;
    } else {
        ((PS *)p)->f34 += 6.666666507720947f;
    }
    v = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x38) = v;
    *(f32 *)(p + 0x38) = v - 12.857142448425293f;
    *(f32 *)(p + 0x50) = 1.25f;
    *(f32 *)(p + 0x54) = 1.100000023841858f;
    *D_004C2990 = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    *(s16 *)(p + 0x1C) = 0;
    func_001757E0(p, 0x17, 4);
}
