typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern V3 D_0043FBA0[];
extern u8 D_00583B92[];
extern u8 D_00583B90[];
extern s32 D_004C2830;
extern s8 D_004C27C0;
extern s8 D_004C27C4;
extern u8 *D_004C2840;

void func_00139380(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00139540(void);
    extern void func_001E60B0(s32);
    u8 *o;
    if ((o = func_003DA750(0, 6, 0)) != 0) {
        o[0x13C] = 1;
        *(void (**)(void))(o + 0x10) = func_00139540;
        *(u8 **)(o + 0x18) = p;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(s32 *)(o + 0x14) = *(s32 *)(p + 0x14);
        o[0x20] = p[0x20];
        o[0x21] = p[0x21];
        *(V3 *)(o + 0x34) = D_0043FBA0[p[0x20]];
        *(s16 *)(o + 0xCC) = p[0x20] * 3 + p[0x21] + 0x4C;
        *(s32 *)(o + 0x84) = D_004C2830;
        *(s32 *)(o + 0x40) = 0;
        *(s32 *)(o + 0x44) = 0;
        *(s32 *)(o + 0x48) = 0;
        *(s32 *)(o + 0xD0) = 0x805;
        if (D_00583B92[p[0x20]] & (1 << p[0x21])) {
            o[4] = 6;
            D_004C27C4 = 1;
            D_004C27C0 |= *(s8 *)(o + 0x20) + 1;
            func_001E60B0(o[0x20] + o[0x21] * 2);
            if (o[0x20] == 0) *(s32 *)(o + 0x44) = 0x8000;
            if (*(s8 *)(D_004C2840 + 0x85) == 7) {
                D_00583B90[o[0x20]] = 1;
            } else if (o[0x21] == 2) {
                D_00583B90[o[0x20]] = 1;
            }
        } else {
            *(s16 *)(o + 0x1C) = p[0x21] * 10;
        }
    }
}
