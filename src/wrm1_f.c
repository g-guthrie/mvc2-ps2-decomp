typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh src/rb62_a.c "-O3 -Op -fp off -sdatathreshold 8" */
typedef struct { f32 x, y, z; } V3;
extern V3 D_004B7E40[];
extern f32 D_004B7E80[];
extern s32 D_004C283C;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003349E0();

void func_003351B0(void) {
    u8 *o;
    s32 i;
    s32 off;
    double k;
    off = 0;
    i = 0;
    do {
        if ((o = func_003DA750(0, 0x5B, 1)) == 0) return;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003349E0;
        *(s16 *)(o + 0xCC) = 0x1B;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x800C39;
        o[0x23] = i;
        *(V3 *)(o + 0x34) = *(V3 *)((u8 *)D_004B7E40 + off);
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + 65536.0 * (double)*(f32 *)((u8 *)D_004B7E80 + off) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (double)*(f32 *)((u8 *)D_004B7E80 + off + 4) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (double)*(f32 *)((u8 *)D_004B7E80 + off + 8) / 360.0) & 0xFFFF;
        *(f32 *)(o + 0x50) = 1.0f;
        *(f32 *)(o + 0x54) = 1.0f;
        *(f32 *)(o + 0x58) = 1.0f;
        *(f32 *)(o + 0x74) = 1.0f;
        *(f32 *)(o + 0x78) = 1.0f;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x80) = 1.0f;
        i++;
        off += 12;
    } while (i < 5);
}
