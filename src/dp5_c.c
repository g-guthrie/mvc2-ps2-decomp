/* nearmiss: try.sh/try30.sh -O3 -Op -fp off -sdatathreshold 8, 4/110 words: a0/a1 vs retail a2/a3 for 0x807 and D_004C283C temps */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
extern f32 D_00583C10[];
extern f32 D_00583C14[];
extern f32 D_00583C18[];

typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
extern u8 *func_003DA750(s32, s32, s32);
typedef struct OB {
    u8 _p0[5];
    u8 b5;
    u8 _p1[0x10 - 6];
    void *fn10;
    u8 _p2[0x23 - 0x14];
    u8 b23;
    u8 _p3[0x34 - 0x24];
    V3 v34;
    u32 w40;
    u32 w44;
    u32 w48;
    u8 _p4[0x84 - 0x4C];
    s32 w84;
    u8 _p5[0xCC - 0x88];
    s16 hcc;
    u8 _p6[2];
    u32 wd0;
    u8 _p7[0x13C - 0xD4];
    u8 b13c;
} OB;

extern V3 D_004B7F80[];
extern V3 D_004B7FA0[];

void func_00336F10(void)
{
    extern void func_00336B20();
    extern void func_003374C0(u8 *);
    s32 i;
    u8 *o;
    s32 off;
    f32 *ang;
    f64 d;

    off = 0;
    i = 0;
    do {
        if ((o = func_003DA750(0, 6, 1)) == 0) {
            return;
        }
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00336B20;
        *(s16 *)(o + 0xCC) = 0x27;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = *(V3 *)((u8 *)D_004B7F80 + off);
        ang = (f32 *)((u8 *)D_004B7FA0 + off);
        d = (f64)ang[0];
        *(u32 *)(o + 0x40) = (u32)(s32)(0.5 + 65536.0 * d / 360.0) & 0xFFFF;
        d = (f64)ang[1];
        *(u32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * d / 360.0) & 0xFFFF;
        d = (f64)ang[2];
        *(u32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * d / 360.0) & 0xFFFF;
        o[0x23] = i;
        o[5] = i;
        func_003374C0(o);
        i++;
        off += 0xC;
    } while (i < 2);
}
