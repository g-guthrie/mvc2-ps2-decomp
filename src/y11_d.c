typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F54D0[];
void func_00176160(u8 *o, s32 a1, s32 index, s32 cnt) {
    u16 n = (u16)index;
    u8 *d;
    u16 *s;
    u16 *t;
    s32 i, j;
    d = D_004F54D0 + (*(s16 *)(o + 0x13E) + a1) * 0x30;
    s = (u16 *)(*(u8 **)(o + 0x174) + ((*(s8 *)(o + 0x30) * 0x80 + 0x300) * 2) + n * 0x20);
    i = 0;
    if (0 < cnt) do {
        *(s32 *)(d + 8) = 1;
        t = (u16 *)(d + 0x10);
        j = 0;
        do {
            t[0] = s[0]; t[1] = s[1]; t[2] = s[2]; t[3] = s[3];
            t[4] = s[4]; t[5] = s[5]; t[6] = s[6]; t[7] = s[7];
            j += 8;
            s += 8;
            t += 8;
        } while (j < 0x10);
        i++;
        d += 0x30;
    } while (i < cnt);
}

void func_00176090(u8 *o, s32 a1, u16 n, s32 cnt) {
    u8 *d;
    u16 *s;
    u16 *t;
    s32 i, j;
    d = D_004F54D0 + (*(s16 *)(o + 0x13E) + a1) * 0x30;
    s = (u16 *)(*(u8 **)(o + 0x174) + ((o[0x25] * 8 + n) * 0x20));
    i = 0;
    if (0 < cnt) do {
        *(s32 *)(d + 8) = 1;
        t = (u16 *)(d + 0x10);
        j = 0;
        do {
            t[0] = s[0]; t[1] = s[1]; t[2] = s[2]; t[3] = s[3];
            t[4] = s[4]; t[5] = s[5]; t[6] = s[6]; t[7] = s[7];
            j += 8;
            s += 8;
            t += 8;
        } while (j < 0x10);
        i++;
        d += 0x30;
    } while (i < cnt);
}
