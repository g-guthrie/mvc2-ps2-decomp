typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C1EA0[2];
extern u8 D_004D18A0[];

void residual_003A3B90(u8 *p, u8 *q, u8 *r) {
    extern s32 func_00175700(u8 *);
    extern void func_003A4250(u8 *);
    extern void func_00175910(u8 *, s32, s32, s32);
    u32 t;
    if ((s8)func_00175700(p) < 0) {
        t = p[5];
        p[5] = t + 1;
        *(s32 *)(p + 0xD0) = (p[0x1B7] != 0) ? 0x1E : 0x1B;
        p[0x14C] = 0x10;
        p[0x14D] = 0x10;
        p[0x14E] = 0x10;
        p[0x14F] = 0x10;
        *(s8 *)(r + 2) |= 1 << *(s8 *)(p + 0x20);
        r[4] = *(s8 *)(r + 4) - 1;
        *(f32 *)(p + 0x5C) = 1.6666666f * (f32)D_004C1EA0[p[0x1B7]] / 65536.0f;
        switch (*(s16 *)(p + 0x140)) {
 case 0: break;
 default: *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C); break;
 }
 func_003A4250(p);
    }
    if (q[5] != 0 || *(s16 *)(q + 0x434) == 0 || *(s8 *)(r + 3) == -1 || D_004D18A0[0] == 5) {
        p[5] = 4;
        *(s8 *)(r + 3) = -1;
        *(s8 *)(r + 2) |= 1 << *(s8 *)(p + 0x20);
        func_00175910(p, 0x17, 5, *(s8 *)(p + 0x151));
    }
}
