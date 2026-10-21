typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
/* IEEE-754 words initialized through native GPR stores, then updated as f32. */
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, s32, s32);
extern void func_001266A0(u8 *, s32, s32);

void func_0023DE30(u8 *p, u8 *context) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    {
        s16 timer = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = timer;
        if (timer != 0)
            return;
    }
    p[6]++;
    *(u8 *)context = 1;
    func_001266A0(p, 0, 0);
    p[0x169] = 0x16;
    p[0x168] = 4;
    func_001757E0(p, p[0x169], p[0x168]);
    {
        u8 state = p[0x20];
        if (state == 1)
            goto negativeVelocity;
        if (state == 0)
            goto positiveVelocity;
        *(u32 *)(p + 0x5C) = 0;
        goto velocityReady;
positiveVelocity:
        *(u32 *)(p + 0x5C) = 0x40555555;
        goto velocityReady;
negativeVelocity:
        *(u32 *)(p + 0x5C) = 0xC0555555;
velocityReady:
        ;
    }
    if (p[0x1E6] != 0)
        *(f32 *)(p + 0x5C) *= -1.0f;
    *(u32 *)(p + 0x60) = 0x41892492;
    *(u32 *)(p + 0x6C) = 0xBF892492;
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
}
