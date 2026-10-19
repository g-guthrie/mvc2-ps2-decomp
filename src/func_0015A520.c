typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

void func_0015A520(u8 *p) {
    if (*(s32 *)(p + 0xD4)) {
        *(s32 *)(p + 0xD4) -= 1;
    } else {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            p[0x13C] = 1;
            p[4]++;
            *(s16 *)(p + 0x1C) = 4;
        }
    }
}
