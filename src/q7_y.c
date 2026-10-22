typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern u8 D_004D18E6;

void func_00323490(u8 *p) {
    extern void func_001266A0();
    extern s32 func_00174170();
    extern void func_001757E0();
    extern void func_00175700();
    extern void func_003CD090();
    extern int func_00174470(const void *);
    u32 t = p[6];
    if (t == 0) {
        s32 v;
        p[6] = t + 1;
        func_001266A0(p, 1, 0);
        v = func_00174170() & 1;
        if (D_004D18E6 == 0) v = 0;
        p[7] = v;
        func_001757E0(p, 0x13, (u8)v);
    } else {
        s32 s;
        func_00175700(p);
        if (p[7] != 0) {
            p[0x209] = 2;
            p[0x208] = 2;
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                func_003CD090(p, 0);
            }
            if (*(s8 *)(p + 0x150) != 0) {
                s32 d = 10;
                if (*(s16 *)(p + 0x140) == 0) d = -10;
                *(f32 *)(p + 0x34) += (f32)d;
            }
            if (func_00174470(p) == 0) {
                *(s16 *)(p + 0x140) = *(s16 *)(p + 0x140) ^ 1;
                s = func_00174170() & 1;
                func_001757E0(p, 0x13, (u8)(s + 3));
                func_003CD090(p, s);
            }
        }
    }
}
