typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00458590[];
extern u8 D_00458594[];
extern u8 D_00458598[];
extern u8 D_0045859C[];

void func_002A3980(u8 *p) {
    extern void func_00175700();
    extern void func_00186A20(u8 *);
    f32 v;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        func_00186A20(p);
        if (p[0x1E6] != 0) {
            v = *(f32 *)(D_00458590 + p[0x1B7] * 16);
        } else {
            v = -*(f32 *)(D_00458590 + p[0x1B7] * 16);
        }
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) {
            v = *(f32 *)(D_00458594 + p[0x1B7] * 16);
        } else {
            v = -*(f32 *)(D_00458594 + p[0x1B7] * 16);
        }
        *(f32 *)(p + 0x68) = v;
        *(f32 *)(p + 0x60) = *(f32 *)(D_00458598 + p[0x1B7] * 16);
        *(f32 *)(p + 0x6C) = *(f32 *)(D_0045859C + p[0x1B7] * 16);
    }
}
