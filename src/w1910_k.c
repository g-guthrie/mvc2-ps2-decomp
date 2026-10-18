typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_001EC9F0(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_00186A20(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001ECF90(u8 *);
    s32 g;
    u32 t;
    f32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        p[6] = 4;
        func_00186A20(p);
        v = (p[0x1E6] != 0) ? 3.3333332538604736f : -3.3333332538604736f;
        *(f32 *)(p + 0x5C) = v;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        *(s16 *)(p + 0x1E) = 1;
        func_001757E0(p, 0x16, 0xD);
        func_001ECF90(p);
        return;
    }
    g = *(s8 *)(p + 0x1B2);
    if (g != 0) {
        if (((s8)g & 1) == 0 && *(u8 *)(*(u8 **)(p + 0x1C4) + 0x216) == 0) {
            t = p[6];
            p[6] = t + 1;
            *(s16 *)(p + 0x1E) = 0;
            func_001757E0(p, 0x16, 0xA);
        }
    }
    func_001ECF90(p);
}
