typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_00139E80();
extern u8 *D_004C2924;
extern s32 D_004C2830;
extern s32 D_0043FC40[];
extern s32 D_0043FC44[];

void func_00139D00(u8 *a, s32 b) {
    u8 *o;
    s32 i;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00139E80;
        *(u8 **)(o + 0xC8) = D_004C2924 + 0x88;
        o[0x20] = b;
        i = (u8)b;
        *(s16 *)(o + 0xCC) = i + 0x44;
        *(s32 *)(o + 0x84) = D_004C2830;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + 65536.0 * (double)*(s32 *)((u8 *)D_0043FC40 + i * 472 + *(s8 *)(a + 0x540) * 8) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (double)*(s32 *)((u8 *)D_0043FC44 + i * 472 + *(s8 *)(a + 0x540) * 8) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = 0;
        *(s32 *)(o + 0xD0) = 0x806;
        o[1] = *(s8 *)(a + 0x540);
    }
}
