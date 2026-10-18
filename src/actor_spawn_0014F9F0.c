typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern V3 D_004B38E0[];

void func_0014F9F0(u8 *p, s32 b, s32 flag)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0014FB00(void);
    extern void func_00150520(u8 *, f32, f32, f32);
    u8 *o;

    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void (**)(void))(o + 0x10) = func_0014FB00;
        *(s32 *)(o + 0xD0) = 0x431;
        *(s16 *)(o + 0x1E) = b;
        o[0x23] = flag;
        if (flag != 0)
            *(u32 *)(o + 0x34) = 0x411E8F5C;
        else
            *(u32 *)(o + 0x34) = 0x4128CCCD;
        *(u32 *)(o + 0x38) = 0xBF7D70A4;
        *(u32 *)(o + 0x3C) = 0x3D8F5C29;
        *(V3 *)(o + 0x50) = D_004B38E0[0];
        func_00150520(o, 1.0f, 0.37439998984336853f, 0.6825000047683716f);
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}
