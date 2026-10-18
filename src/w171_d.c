typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
extern u8 D_0044B290[];
void func_001A4FB0(u8 *p)
{
    extern void func_00175910(u8 *, s32, u8, s32);
    extern void func_00178F20(u8 *, s32);
    s32 i;
    s32 n;
    s32 r;
    r = 0;
    n = *(s16 *)(p + 0x1E);
    for (i = 0; i < n - 1; i++) {
        func_00175910(p, 0x17, D_0044B290[p[0x23]] + 0x55, p[0x22]);
        if (*(s8 *)(p + 0x13C) == 0 && r == 0) {
            r = 1;
            p[0x13C] = r;
        }
        p = *(u8 **)(p + 0xC);
    }
    func_00175910(p, 0xF, 5, ((p[0x22] + 2) & 0x1F) >> 2);
    func_00178F20(p, *(s32 *)(p + 0x1DC));
}
