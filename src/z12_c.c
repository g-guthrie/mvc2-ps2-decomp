typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F20B0[];
void func_001E3630(u32 a) {
    extern void func_001741D0(u8 *, f32 *);
    extern s32 func_00118FA8(f32);
    extern void func_001E3D20(s32, s32, s32, s32);
    u32 i;
    s32 s1;
    s32 off;
    s32 v;
    u8 *e;
    f32 t[2];
    off = 0;
    i = 0;
    do {
        e = D_004F20B0 + off;
        if (e[1] == 0x18) {
            s1 = e[0x1B8];
            func_001741D0(e + 0x34, &t[0]);
            v = func_00118FA8(t[0] / 40.0f);
            if (v <= -1) v = 0;
            if (v >= 0x10) v = 0xF;
        }
        i++;
        off += 0x5B8;
    } while (i < 6);
    func_001E3D20(s1 + (s1 << 4), a & 0xFF, v, -1);
}
