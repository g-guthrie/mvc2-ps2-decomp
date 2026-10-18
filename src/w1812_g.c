typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x18]; u8 *e[2][3]; } T27;
extern T27 D_004D18A0;
extern u8 D_004D18D8, D_004D18D9;
void func_00327750(void) {
    extern void func_001E3710(u8 *, s32);
    u8 *o;
    s32 m1 = 0, m2 = 0;
    s32 i, j;
    s32 old = D_004D18D8;
    s32 bit;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            o = D_004D18A0.e[i][j];
            if (o[0] != 0 && (o[0x269] == 4 || o[0x269] == 5)) m1 |= 1 << o[2];
            if (o[0] != 0 && o[0x269] == 8) m2 |= 1 << o[2];
        }
    }
    D_004D18D8 = m1;
    D_004D18D9 = m2;
    for (i = 0; i < 2; i++) {
        o = D_004D18A0.e[i][0];
        bit = 1 << o[2];
        if ((old & bit) != 0 && (D_004D18D8 & bit) == 0) {
            s16 h;
            func_001E3710(o, 0x52);
            h = *(s16 *)(o + 0x4F0) & 0xBFF0;
            *(s16 *)(o + 0x356) = h;
            *(s16 *)(o + 0x354) = h;
        }
    }
}
