typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u16 D_004B7120[];
void func_00207510(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001E3270(u8 *, s32, f32);
    extern void func_001757E0(u8 *, s32, s32);
    extern u8 *func_0034B070(u8 *, s32);
    u8 *o;
    u32 t;
    f32 f;
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        func_001E3710(p, 0x30);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        h = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = h;
        if (h >= 8) {
            func_001E3270(p, 0x18, 4.0f);
            t = p[6];
            p[6] = t + 1;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            if (p[0x20D] != 2) {
                func_001757E0(p, 0x16, 7);
                return;
            } else {
                func_001757E0(p, 0x16, 9);
            }
        } else {
            if ((o = func_0034B070(p, 1)) != 0) {
                f = 1.6666666269302368f * (f32)(u32)D_004B7120[*(s16 *)(p + 0x1C)];
                *(f32 *)(o + 0x34) = f;
                if (*(s16 *)(p + 0x140) == 0) *(f32 *)(o + 0x34) = -*(f32 *)(o + 0x34);
                *(f32 *)(o + 0x34) += *(f32 *)(p + 0x34);
            }
        }
    }
}
