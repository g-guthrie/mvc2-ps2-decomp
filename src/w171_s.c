typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

void func_00224C30(u8 *p)
{
    extern void func_00185490(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183D10(u8 *);
    extern void func_00224D60(u8 *);
    u32 t;
    u32 off;
    s32 v;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    t = p[6];
    p[6] = t + 1;
    p[0x1B5] = 0x30;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    off = p[2] * 2;
    off += (u32)D_004C2794;
    ++*(s16 *)(off + 0x7C);
    func_00185490(p);
    if (p[0x20D] != 2) {
        func_001757E0(p, 0x16, 0);
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_00183D10(p);
    } else {
        f32 k = 8.0f;
        func_001757E0(p, 0x16, 1);
        *(f32 *)(p + 0x5C) /= k;
        *(f32 *)(p + 0x68) /= k;
        *(f32 *)(p + 0x60) /= k;
        *(f32 *)(p + 0x6C) /= k;
    }
    v = 0x68;
    *(s16 *)(p + 0x1C) = v;
    *(s16 *)(p + 0x1E) = 0x1E;
    func_00224D60(p);
}
