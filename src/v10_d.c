typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;

extern u8 D_0044AF20[];
void func_001A2B40(u8 *p) {
    extern void func_00175910();
    extern void func_001757E0();
    s32 i;
    s32 n;
    n = *(s16 *)(p + 0x1E);
    i = 0;
    if (0 < n - 1) do {
        func_00175910(p, 0x17, (u8)(D_0044AF20[p[0x23]] + 0x10), p[0x22]);
        i++;
        p = *(u8 **)(p + 0xC);
    } while (i < n - 1);
    func_001757E0(p, 0x17, 0x14);
}
