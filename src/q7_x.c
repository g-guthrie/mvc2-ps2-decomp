typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { f32 x, y, z; } V3;
extern f32 D_00444320[];
extern V3 D_004B38E0;
extern void func_00150210(void);

void func_001500E0(u8 *owner, s32 kind, s32 c) {
    extern u8 *func_003DA750();
    extern void func_00150520(u8 *, f32, f32, f32);
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00150210;
        *(u32 *)(o + 0xD0) = 0x431;
        *(f32 *)(o + 0x34) = D_00444320[c];
        switch (kind) {
        case 0:
            *(f32 *)(o + 0x38) = -0.9800000190734863f;
            break;
        case 1:
            *(f32 *)(o + 0x38) = -0.9800000190734863f;
            break;
        case 2:
            *(f32 *)(o + 0x38) = -0.9800000190734863f;
            break;
        }
        *(f32 *)(o + 0x3C) = 0.07000000029802322f;
        *(s16 *)(o + 0x1E) = kind;
        o[0x23] = c;
        func_00150520(o, 0.4991999864578247f, 1.0f, 1.0f);
        *(V3 *)(o + 0x50) = D_004B38E0;
        *(u8 **)(o + 0xC8) = owner + 0x88;
        *(u8 **)(o + 0x18) = owner;
    }
}
