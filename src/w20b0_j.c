typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 v, w, x; } T6;
extern u8 *D_004C2840;

void func_0012BE30(u8 *a, s32 idx) {
    extern s32 func_00417A40();
    extern s32 func_00131830(s32, s32);
    s32 s0, s1, s2;
    u32 m;
    u8 *q;
    s2 = 0;
    s1 = func_00417A40() % 0x3B;
    s0 = 0;
    do {
        if (s1 >= 0x18 && s1 < 0x1B) {
            s1++;
        } else {
            if (s1 >= 0x20) q = D_004C2840 + 0x34; else q = D_004C2840 + 0x30;
            if ((*(u32 *)q & (1 << s1)) != 0) {
                if (func_00131830(s1, 0) == 0) break;
            }
            s1++;
            if (s1 >= 0x3B) s1 = 0;
        }
        s0++;
    } while (s0 < 0x3B);
    if (s0 != 0x3B) {
        ((s16 *)(a + 0x14))[idx] = s1;
        s0 = 0;
        do {
            if (func_00131830(s0, 0) != 0) s2++;
            s0++;
        } while (s0 <= 0x3A);
        ((T6 *)(a + 0x1C))[idx].v = (s2 + 1) * 100;
    } else {
        ((s16 *)(a + 0x14))[idx] = -1;
    }
}
