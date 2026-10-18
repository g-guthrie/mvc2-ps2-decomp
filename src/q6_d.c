typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0044AF20[];

void func_001A0540(u8 *p) {
    extern void func_00175910(u8 *, s32, u8, s32);
    extern void func_00178F20(u8 *, s32);
    s32 i;
    s32 flag = 0;
    s32 n = *(s16 *)(p + 0x1E);
    i = 0;
    if (0 < n - 1) do {
        func_00175910(p, 0x17, D_0044AF20[p[0x23]] + 0x10, p[0x22]);
        if (*(s8 *)(p + 0x13C) == 0 && flag == 0) {
            flag = 1;
            p[0x13C] = flag;
        }
        p = *(u8 **)(p + 0xC);
        i++;
    } while (i < n - 1);
    func_00175910(p, 0xF, 0xA, ((p[0x22] + 2) & 0x1F) >> 2);
    func_00178F20(p, *(s32 *)(p + 0x1DC));
}
