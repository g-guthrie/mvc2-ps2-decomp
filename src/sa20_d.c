typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2840;
extern u32 D_004C2830;
extern V3 D_00440494[];
extern V3 D_00440440[];

void func_0013BF80(u8 *a) {
    extern u8 *func_003DA750();
    extern void func_0013C5B0();
    u8 *o;
    s32 i;
    u32 acc;
    s32 off;
    if (*(s8 *)(D_004C2840 + 0x85) == 7) {
        o = func_003DA750(a, 6, 3);
        if (o == 0) return;
        o[0x13C] = 1;
        *(u8 **)(o + 0x18) = a;
        *(u8 **)(o + 0xC8) = a + 0x88;
        *(s32 *)(o + 0x10) = (s32)func_0013C5B0;
        o[0x20] = 7;
        *(V3 *)(o + 0x34) = *D_00440494;
        *(s16 *)(o + 0xCC) = 0x61;
        *(u32 *)(o + 0x84) = D_004C2830;
        *(u32 *)(o + 0xD0) = 0x825;
        *(u32 *)(o + 0x74) = 0x3F800000;
        *(u32 *)(o + 0x44) = 0;
    } else {
        acc = 0;
        for (i = 0, off = 0; (s16)i < 7; i = (s16)(i + 1)) {
            o = func_003DA750(a, 6, 3);
            if (o == 0) return;
            o[0x13C] = 1;
            *(u8 **)(o + 0x18) = a;
            *(u8 **)(o + 0xC8) = a + 0x88;
            *(s32 *)(o + 0x10) = (s32)func_0013C5B0;
            o[0x20] = i;
            *(V3 *)(o + 0x34) = *(V3 *)((u8 *)D_00440440 + off);
            off += 12;
            *(s16 *)(o + 0xCC) = (s16)i + 0x5A;
            *(u32 *)(o + 0x84) = D_004C2830;
            *(u32 *)(o + 0x44) = acc;
            *(u32 *)(o + 0xD0) = 0x825;
            acc += 0xE39;
            *(u32 *)(o + 0x74) = 0;
        }
    }
}
