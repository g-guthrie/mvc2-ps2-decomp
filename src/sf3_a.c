typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { f32 x, y, z; } V3;

extern V3 D_00444370[];
extern s32 D_004C27FC;

void func_00150C40(u8 a) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00150D70();
    u8 *o;
    s32 i;
    s32 j;
    s32 ang;
    i = 0;
    j = 0;
    ang = 0;
    do {
        if ((o = func_003DA750(0, 0xD, 1)) == 0) return;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00150D70;
        *(u16 *)(o + 0xCC) = 0x24;
        *(s32 *)(o + 0x84) = D_004C27FC;
        *(u32 *)(o + 0xD0) = 9;
        *(V3 *)(o + 0x34) = *(V3 *)((u8 *)D_00444370 + j);
        *(u32 *)(o + 0x48) = (s32)(0.5 + 65536.0 * (f64)ang / 360.0) & 0xFFFF;
        o[0x20] = i;
        *(s16 *)(o + 0x1C) = 0;
        o[0x21] = a;
        j += 12;
        ang += 0xB4;
        i++;
    } while (i < 2);
}
