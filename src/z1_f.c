typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004BFFF0[2];
extern u8 D_004BFFE8[2];

void func_002245F0(u8 *p) {
    extern s32 func_001841C0();
    extern u32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0019C780(u8 *, s32);
    u32 t = p[6];
    s32 c;
    s32 r;
    s16 h;
    p[6] = t + 1;
    if (func_001841C0(p) >= 2) {
        if (p[0x20] == 1) {
            func_001757E0(p, 0x13, 4);
        } else {
            func_001757E0(p, 0x13, 2);
        }
        return;
    }
    c = D_004BFFF0[p[0x20]];
    if (p[0x20] == 0) {
        *(s16 *)(p + 0x1C) = func_00174170() % 3;
        h = *(s16 *)(p + 0x1C);
        c = D_004BFFE8[h];
        if (h != 2) func_0019C780(p, h & 0xFF);
    }
    func_001757E0(p, 0x13, c);
}
