typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { s32 x[49]; } S49;
typedef struct { u32 a, b; } G2708;
extern G2708 *D_004C2708;

static void func_001C88F0(u8 *p) {
    f32 *offset = (f32 *)D_004C2708;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140))
        *(f32 *)(p + 0x34) += offset[0];
    else
        *(f32 *)(p + 0x34) -= offset[0];
    *(f32 *)(p + 0x38) += offset[1];
}

void func_001C8960(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    u32 t = p[4];
    p[4] = t + 1;
    *(S49 *)(p + 0xEC) = *(S49 *)(*(u8 **)(p + 0x18) + 0xEC);
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
    D_004C2708->a = 0;
    D_004C2708->b = 0;
    func_001C88F0(p);
    func_001757E0(p, 0x17, p[0x21] * 2);
}
