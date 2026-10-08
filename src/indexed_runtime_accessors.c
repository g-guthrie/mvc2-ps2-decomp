typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;

void func_003FF5F0(u8 *base, s32 index, s32 value) {
    *(s32 *)(base + ((u32)index << 2) + 12) = value;
}

s32 func_00404CA8(u8 *base, s32 index) {
    return *(s32 *)(base + ((u32)index << 2) + 12);
}

s32 func_004052F8(u8 *base, s32 index) {
    u32 address = ((u32)index << 4) + (u32)base + 0xB4;
    return *(s32 *)address;
}

s8 func_00405308(u8 *base, s32 index) {
    return *(s8 *)(base + ((u32)index << 4) + 0xB0);
}

s32 func_0040EE98(u8 *base, s32 index) {
    u32 address = ((u32)index << 2) + (u32)base + 0x38;
    return *(s32 *)address;
}
