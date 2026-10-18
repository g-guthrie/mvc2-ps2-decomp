typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern s32 func_00175700(u8 *);
extern void func_001E3270(u8 *, s32, f32);
extern s32 func_001757E0(u8 *, s32, s32);
void func_002029D0(u8 *p) {
    u8 *motion = p + 0x2B8;
    s16 timer;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    {
        f32 current = *(f32 *)(p + 0x60);
        f32 zero = 0.0f;
        if (current < zero) {
        *(f32 *)(p + 0x6C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        *(u32 *)(p + 0x5C) = 0x3F555555;
        *(u32 *)(p + 0x60) = 0x3F892492;
        if (*(s16 *)(p + 0x140) == 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
    }
    timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0) {
        p[6]++;
        *(u32 *)(p + 0x5C) = 0x40D55555;
        *(u32 *)(p + 0x68) = 0xBDD55555;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        motion[0x1C] = 0;
        func_001E3270(p, 31, 32.0f);
        func_001757E0(p, 15, 2);
    }
}
