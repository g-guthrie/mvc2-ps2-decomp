typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34, f38;
    u8 pad1[0x5C - 0x3C];
    f32 f5c, f60;
    u8 pad2[0x68 - 0x64];
    f32 f68, f6c;
    u8 pad3[0x430 - 0x70];
    f32 f430;
} Sa;

void func_00365C30(Sa *p) {
    extern void func_001757E0();
    extern void func_001AD1E0();
    extern void func_001E7F60();
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (!(p->f60 < 0.0f)) {
        u32 t = ((u8 *)p)[5];
        ((u8 *)p)[5] = t + 1;
        func_001757E0(p, 0x17, 6);
        func_001AD1E0(p, 0x11, 0);
        func_001AD1E0(p, 0x11, 0);
    } else {
        func_001E7F60();
    }
}


typedef struct { f32 x, y, z; } V3a;
extern s32 D_004C2838;
extern s32 D_004B41E0[];

void func_00163760(V3a *v, s32 idx) {
    extern u8 *func_003DA750();
    extern void func_00163820();
    u8 *o;
    if ((o = func_003DA750(0, 9, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00163820;
        *(s32 *)(o + 0xD0) = 0x515;
        *(s32 *)(o + 0xD4) = 5;
        *(s16 *)(o + 0xCC) = 0x27;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3a *)(o + 0x34) = *v;
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        *(s32 *)(o + 0x44) = D_004B41E0[idx];
        *(s32 *)(o + 0x78) = 0;
        *(s32 *)(o + 0x7C) = 0;
        *(s32 *)(o + 0x80) = 0;
    }
}
