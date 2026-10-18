typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00447280[];
extern s16 D_00447460[];
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_00181F10(u8 *p) {
    s16 *tab;
    s32 i;
    f32 v;
    tab = D_00447280;
    if (p[0x216] & 0x80) {
        tab = D_00447460;
    }
    i = ((*(u16 *)(p + 0x35E) & 0x400) >> 10) + (p[1] << 1);
    tab += i;
    if (p[0x1E6] != 0) {
        v = 1.6666666269302368f * (f32)*tab / 256.0f;
        *(f32 *)(p + 0x5C) = v;
    } else {
        v = -(1.6666666269302368f * (f32)*tab / 256.0f);
        *(f32 *)(p + 0x5C) = v;
    }
    if (p[0x214] != 0) {
        *(f32 *)(p + 0x5C) *= 1.25f;
    }
    if ((p[0x216] & 0x80) != 0 || p[1] == 0x34 || p[1] == 0x18) {
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            D_004F1F45 = 1;
            D_004F1F46 = 1;
        }
        if (*(s8 *)(p + 0x151) != 0) {
            *(s32 *)(p + 0x5C) = 0;
        }
    }
}
