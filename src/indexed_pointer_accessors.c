typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

u8 *func_0040EF70(u8 *base, s32 index) {
    u32 object = *(u32 *)(base + ((u32)index << 2) + 8);
    return *(u8 **)(object + 8);
}

u8 *func_0040EF88(u8 *base, s32 index) {
    u32 object = *(u32 *)(base + ((u32)index << 2) + 8);
    return *(u8 **)(object + 4);
}

void func_0040FCE8(u8 *base, s32 i, s32 j, s32 value) {
    *(s32 *)(base + (((u32)i << 1) + (u32)j) * 4 + 40) = value;
}
