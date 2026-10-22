typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004C1F68[2];
extern s8 D_004C1F69[2];

void func_003B0160(u8 *p, u8 *q) {
    extern s32 fptosi(f32);
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_00174910(u8 *, s32);
    extern void func_003B07D0(u8 *, u8 *);
    s16 *s0;
    s32 v;
    s0 = (s16 *)(p + 0xD0);
    if (p[7] == 0) {
        p[7]++;
        s0[2] = fptosi(1.6666666269302368f * (f32)D_004C1F68[p[0x1B7] * 2]);
        if (*(s16 *)(p + 0x140) != 0) s0[2] = -s0[2];
        s0[3] = fptosi(1.6666666269302368f * (f32)D_004C1F69[p[0x1B7] * 2]);
    } else {
        if (*(s16 *)(p + 0x140) == 0) p[0x22]--;
        else p[0x22]++;
        p[0x22] &= 0x1F;
        if (*(s16 *)(p + 0x140) != 0) v = 0xC - p[0x22] / 2;
        else v = p[0x22] / 2 - 4;
        func_00175910(p, 0x17, 3, v & 0xF);
        s0[0] += s0[2];
        s0[1] += s0[3];
        *(f32 *)(p + 0x34) = (f32)s0[0];
        *(f32 *)(p + 0x38) = (f32)s0[1];
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_00174910(p, 0xFA0);
    }
    func_003B07D0(p, q);
}
