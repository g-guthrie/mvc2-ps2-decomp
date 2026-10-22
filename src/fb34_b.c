typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern f32 D_004F1F60[];
extern f32 D_004F1FC0[];
extern f32 D_004F1C00[];

void func_00152D20(u8 *p) {
    extern void func_00417950(f32, f32);
    extern void func_00417980(f32, f32, f32, f32 *, f32 *, f32 *);
    extern s32 func_00174F60(u8 *);
    f32 x, y, z;
    if ((s8)p[0x13C] != 0) {
        func_00417950(640.0f, 480.0f);
        func_00417980(*(f32 *)(p + 0x34), *(f32 *)(p + 0x38), *(f32 *)(p + 0x3C), &x, &y, &z);
        y -= 240.0f * D_004F1FC0[0];
        *(f32 *)(p + 0xF0) = x;
        *(f32 *)(p + 0xF4) = y;
        *(f32 *)(p + 0xF8) = 0.10000000149011612f * D_004F1F60[0] + D_004F1C00[(s8)p[0x24]];
        *(f32 *)(p + 0xFC) = 1.6666666269302368f * *(f32 *)(p + 0x50);
        *(f32 *)(p + 0x100) = 2.142857074737549f * *(f32 *)(p + 0x54);
        *(s32 *)(p + 0x114) = *(s32 *)(p + 0x48);
        *(s32 *)(p + 0x120) = *(s16 *)(p + 0x140);
        *(s32 *)(p + 0x11C) = 0;
        *(s16 *)(p + 0x144) = *(s16 *)(p + 0x4C);
        *(s16 *)(p + 0x146) = *(s16 *)(p + 0x4E);
        {
            f32 k = D_004F1F60[0] / 812.3572998046875f;
            *(f32 *)(p + 0xFC) /= k;
            *(f32 *)(p + 0x100) /= k;
        }
        if (p[0x15D] != 0) {
            u16 *q = (u16 *)(*(s32 *)(p + 0x178) + ((u32)p[0x15D] << 4));
            *(f32 *)(p + 0xFC) *= (f32)(u32)q[0] / 1000.0f;
            *(f32 *)(p + 0x100) *= (f32)(u32)q[1] / 1000.0f;
            *(s32 *)(p + 0x114) = (*(s32 *)(p + 0x114) + q[2]) & 0xFFFF;
            *(s16 *)(p + 0x144) = q[3];
            *(s16 *)(p + 0x146) = q[4];
            *(s32 *)(p + 0x120) ^= q[5];
        }
        {
            s32 r = func_00174F60(p);
            *(s32 *)(D_004C2840 + 0x24) += r;
            D_004F1C00[(s8)p[0x24]] += 0.0010000000474974513f * (f32)r;
        }
    }
}
