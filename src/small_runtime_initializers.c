typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

void func_00400CE8(s32 *p, s32 value) {
    p[5] = (s32)((u32)value << 11);
}

s32 func_00400B98(s32 *p, s32 *out1, s32 *out2) {
    *out1 = p[7];
    *out2 = p[6];
    return 1;
}

s32 func_00400BB8(u8 *p, s32 first, s32 second) {
    *(s32 *)(p + 28) = first;
    *(s32 *)(p + 24) = second;
    return 1;
}

void func_00408EC8(u8 *p) {
    *(s32 *)(p + 0x3C) = 0;
    p[1] = 1;
}

void func_004052C0(u8 *p) {
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 8) = 0;
    *(s32 *)(p + 12) = 0;
    p[1] = 1;
}

void func_004044B0(s32 *p) {
    if (p[3] == 3) p[3] = 0;
}
