typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_002C8B10(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_00185490(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    u16 h;
    f32 c;
    if ((s8)func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        func_00185490(p);
        if (*(s8 *)(p + 0x539) == 0) {
            h = *(u16 *)(p + 0x354);
            if ((h & 0x800) != 0) {
                p[0x1E6] = *(s16 *)(p + 0x140) = 0;
            } else if ((h & 0x400) != 0) {
                *(s16 *)(p + 0x140) = 1;
                p[0x1E6] = 1;
            }
        }
        if (p[0x1E6] != 0) c = -6.666666507720947f;
        else c = 6.666666507720947f;
        *(f32 *)(p + 0x5C) = c;
        if (p[0x1E6] != 0) c = 0.2083333283662796f;
        else c = -0.2083333283662796f;
        *(f32 *)(p + 0x68) = c;
        *(u32 *)(p + 0x60) = 0x41AB6DB6;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x15, 0xA);
    }
}
