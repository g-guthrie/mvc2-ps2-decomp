typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static s32 func_0028A490(u8 *p) { return p[0x20] != 0; }

void func_0028A530(u8 *p, u8 *q) {
    extern s8 func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0028B0B0(u8 *);
    if (q[0x18] == 0) {
        q[0x18] = q[0x18] + 1;
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
        q[0x19] = 1;
        func_001757E0(p, 0x16, 0xA);
    }
    if (func_0028A490(p) != 0) {
        q[0x18] = 0;
        func_0028A530(p, q);
    } else {
        if ((s8)func_00175700() < 0) {
            p[7] = 0;
            q[0x18] = 0;
            q[0x19] = 0;
            func_001757E0(p, 0x16, 8);
        }
        func_0028B0B0(p);
    }
}
