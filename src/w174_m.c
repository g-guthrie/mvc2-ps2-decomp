typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern u8 D_004BF3F0[4];
extern s32 D_004C27E8;
extern s32 D_004C27FC;
extern f32 D_00443E20[];
extern f32 D_00443DE0[];

void func_00149FA0(void) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0014A0E0(void);
    extern void func_0014A130(u8 *, s32);
    extern void func_0014A2A0(u8 *, s32);
    u8 *o;
    s32 i;
    s32 off;
    off = 0;
    for (i = 0; i < 4; i++) {
        if ((o = func_003DA750(0, 0xD, 1)) == 0) return;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0014A0E0;
        switch (i) {
        case 1:
            *(s16 *)(o + 0xCC) = D_004BF3F0[i];
            *(s32 *)(o + 0x84) = D_004C27E8;
            *(V3 *)(o + 0x50) = *(V3 *)D_00443E20;
            break;
        default:
            *(s16 *)(o + 0xCC) = D_004BF3F0[i];
            *(s32 *)(o + 0x84) = D_004C27FC;
            *(u32 *)(o + 0x50) = 0x3F800000;
            *(u32 *)(o + 0x54) = 0x3F800000;
            *(u32 *)(o + 0x58) = 0x3F800000;
            break;
        }
        *(s32 *)(o + 0xD0) = 0x411;
        *(u32 *)(o + 0x34) = 0xC10CCCCD;
        *(f32 *)(o + 0x38) = *(f32 *)((u8 *)D_00443DE0 + off);
        *(u32 *)(o + 0x3C) = 0xC14FD70A;
        o[0x20] = i;
        func_0014A130(o, i);
        func_0014A2A0(o, i);
        off += 4;
    }
}
