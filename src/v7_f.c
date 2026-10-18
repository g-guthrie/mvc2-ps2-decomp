typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C27FC;
extern u8 *func_003DA750();
extern void func_0014FE90();
extern void func_00150520(u8 *, f32, f32, f32);

void func_0014FDC0(u8 *p, s16 n) {
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0014FE90;
        *(s32 *)(o + 0xD0) = 0x421;
        *(u32 *)(o + 0x34) = 0x40D8A3D7;
        *(u32 *)(o + 0x38) = 0x3EBD70A4;
        *(u32 *)(o + 0x3C) = 0x3DA3D70A;
        *(s16 *)(o + 0x1E) = n;
        func_00150520(o, 1.0f, 1.0f, 0.0f);
        *(s16 *)(o + 0xCC) = 0x39;
        *(s32 *)(o + 0x84) = D_004C27FC;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}
