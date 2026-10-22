typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003BA140(u8 *p);
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern u8 *D_004C2794;

void func_003B97D0(u8 *p) {
    u8 *q;
    u8 v;

    q = *(u8 **)(p + 0x18);
    func_003BA140(p);
    p[0x24] = 10;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x14D] = 0xD4;
    p[0x14C] = 0xD4;
    p[0x14D] = 1;
    p[0x14D] = 1;
    p[0x14D] = 0x40;
    p[0x14E] = 0x40;
    p[0x14F] = 0x40;
    p[0x14F] = 0x40;
    p[0x13C] = 1;
    if (*(u8 *)(*(u8 **)(p + 0x14) + 0x269) == 8) {
        p[0x1B5] = 0x32;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) = *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) + 1;
    } else {
        v = 0x31;
        if (*(u8 *)(*(u8 **)(p + 0x14) + 0x269) == 3) {
            p[0x1B5] = 0x30;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) = *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) + 1;
        } else {
            p[0x1B5] = v;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) = *(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C) + 1;
        }
    }
    func_001757E0(p, 0x15, (u8)(p[0x21] + 0x11));
}
