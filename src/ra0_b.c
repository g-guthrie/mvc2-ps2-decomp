typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_002F51F0(u8 *p, u16 *q) {
    extern void func_001757E0(u8 *, s32, s32, s32);
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    t = p[6];
    p[6] = t + 1;
    p[0x1B7] = *q = 2;
    func_001757E0(p, 0x15, 0x18, 2);
}
