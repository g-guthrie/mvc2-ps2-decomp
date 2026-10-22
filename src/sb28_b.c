typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u16 D_00478FF8[];
void func_003F7708(u8 *p)
{
    extern s32 func_00404400();
    u8 *q;
    u8 *src;
    u16 *o1, *o2;
    s32 n, i;
    q = p + 0x48;
    src = *(u8 **)q;
    if (*(s32 *)(p + 4) == 1 && func_00404400(*(s32 *)(p + 8)) == 0) {
        (*(s32 (**)())(p + 0x78))(*(s32 *)(p + 0x7C), p + 0x68, p + 0x6C, p + 0x70);
        n = *(s32 *)(q + 0x18) - *(s32 *)(q + 0x20);
        if (*(s32 *)(q + 0x24) < n) n = *(s32 *)(q + 0x24);
        if (*(s32 *)(q + 4) < n) n = *(s32 *)(q + 4);
        o1 = (u16 *)(*(u8 **)(q + 0x14) + *(s32 *)(q + 0x20) * 2);
        if (*(s8 *)(p + 0xE) == 2) {
            o2 = (u16 *)(*(u8 **)(q + 0x14) + (*(s32 *)(q + 0x1C) + *(s32 *)(q + 0x20)) * 2);
            for (i = 0; i < n; i++) {
                o1[i] = D_00478FF8[src[i * 2]];
                o2[i] = D_00478FF8[src[i * 2 + 1]];
            }
        } else {
            for (i = 0; i < n; i++) o1[i] = D_00478FF8[src[i]];
        }
        *(s32 *)(p + 4) = 2;
        *(s32 *)(p + 0x90) = n;
        *(s32 *)(p + 0x94) = n * (s8)p[0xE];
    }
    if (*(s32 *)(p + 4) == 2) {
        (*(void (**)())(p + 0x80))(*(s32 *)(p + 0x84), *(s32 *)(p + 0x94), *(s32 *)(p + 0x90));
        *(s32 *)(p + 4) = 3;
    }
}
