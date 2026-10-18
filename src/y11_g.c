typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { u8 pad[0x198]; u8 *tab[4]; } S;
extern u8 D_004461A0[];
extern u8 D_004BF47C[];
extern u8 D_00445E5C[];
extern s16 D_004D1802;
s32 func_00169CE0(u8 *a0, s32 a1, s32 a2) {
    extern s32 func_00174170();
    u8 *s0;
    u8 *a;
    u8 *t0;
    u8 **tab;
    switch (D_004461A0[a1]) {
    case 0:
        tab = (u8 **)(a0 + 0x198);
        a = tab[a2];
        t0 = a;
        if (a2 == 2) a = a + (a1 - 2) * 12;
        s0 = *(u8 **)a + (s32)t0;
        break;
    case 1:
        if (a2 != 2) return 0;
        s0 = *(u8 **)(D_004BF47C + a1 * 4);
        break;
    case 2:
        if (a2 != 2) return 0;
        s0 = *(u8 **)(D_00445E5C + a1 * 4);
        break;
    default: break;
    }
    return ((u32)func_00174170() & 0x1F) < s0[D_004D1802];
}
