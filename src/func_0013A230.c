typedef unsigned char u8;
typedef signed int s32;

void func_0013A230(u8 *p) {
    if (p[0x20]) {
        *(s32 *)(p + 0x48) -= 0x200;
        if (*(s32 *)(p + 0x48) <= 0) {
            p[4]++;
            *(s32 *)(p + 0x48) = 0;
        }
    } else {
        *(s32 *)(p + 0x48) += 0x200;
        if (*(s32 *)(p + 0x48) >= 0x10000) {
            p[4]++;
            *(s32 *)(p + 0x48) = 0;
        }
    }
}
