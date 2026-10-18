typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_003BCFB0(u8 *p) {
    u8 *a = p + 0xD0;
    u8 *q;
    if (*(s8 *)(p + 0x1B3) == 0) return 0;
    if (*(u8 *)(*(u8 **)(p + 0x18) + 0x2BA) != 0) return -1;
    if (a[9] == 0) return -1;
    q = *(u8 **)a;
    if (q[5] != 3) return -1;
    if (q[0x247] == 9) {
        *(s16 *)(q + 0x1F8) = 0;
        q[0x24D] = 0;
        return -1;
    }
    if (q[0x247] == 0x17) {
        *(s16 *)(q + 0x1F8) = 0;
        q[0x24D] = 0;
    }
    return -1;
}
