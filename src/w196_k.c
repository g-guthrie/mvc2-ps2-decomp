typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

void func_002EFF40(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00154790(f32 *, s32, s32, s32);
    extern void func_00183d50(u8 *);
    extern void func_003A9540(u8 *);
    extern void func_001E3710(u8 *, s32);
    f32 v[4];
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) == 0) func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        v[0] = -13.333333015441895f;
        if (*(s16 *)(p + 0x140) != 0) v[0] = -v[0];
        v[0] += *(f32 *)(p + 0x34);
        v[1] = 68.57142639160156f + *(f32 *)(p + 0x38);
        func_00154790(v, p[0x1E6], 0xF, 0);
        func_00183d50(p);
        func_003A9540(p);
        func_001E3710(p, 0x31);
        D_004F1F45[0] = 3;
        D_004F1F46[0] = 1;
    }
}
