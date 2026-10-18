typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00458A60[];
extern u8 D_00458A70[];
extern u8 D_00458B00[];
extern u8 D_00458B10[];

extern s32 D_004C2840;
static s32 func_002AB9A0(u8 *p) {
    return D_004C2840 != 0;
}

s32 func_002ABDA0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    u8 *t;
    if (*(u32 *)(p + 0xD0) == 0) {
        if (*(s8 *)(p + 0x539) != 0 && p[0x20D] == 2) t = D_00458A70;
        else t = D_00458A60;
    } else {
        if (*(s8 *)(p + 0x539) != 0 && p[0x20D] == 2) t = D_00458B10;
        else t = D_00458B00;
    }
    if (func_00189310(p, t, p + 0x398) == 0) return 0;
    if (func_002AB9A0(p) == 0) return 0;
    func_0018A990(p, p + 0x398);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    if (p[0x20D] != 2) p[0x1FD] = 5;
    else p[0x1FD] = 7;
    func_00186A60(p, 0x15);
    return 1;
}
