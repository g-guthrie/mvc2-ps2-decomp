typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern u32 D_004C27FC;
extern V3 D_00443E2C;
extern V3 D_00443DF0[];
extern void func_0014A210();

void func_0014A130(u8 *p, s32 k) {
    extern u8 *func_003DA750();
    extern void func_0014A220();
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0014A210;
        *(s16 *)(o + 0xCC) = 4;
        *(u32 *)(o + 0x84) = D_004C27FC;
        *(s32 *)(o + 0xD0) = 0x11;
        *(u32 *)(o + 0x3C) = 0xBDCCCCCD;
        if (k == 1) {
            *(V3 *)(o + 0x50) = D_00443E2C;
        } else {
            *(V3 *)(o + 0x50) = D_00443DF0[k];
        }
        *(u32 *)(o + 0xC8) = (u32)(p + 0x88);
        func_0014A220(o);
    }
}
