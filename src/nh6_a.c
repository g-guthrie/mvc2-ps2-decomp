typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0041ABF0(u8 *p, u8 *q) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    s16 h;
    u8 c;
    u8 *s;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) return;
    h = *(s16 *)(q + 0x140);
    s = *(u8 **)(p + 0x14);
    c = *(s8 *)s++ * 2;
    if (h != 0) c = (0x20 - (s8)c) & 0x1F;
    p[0x22] = c;
    if ((s16)(*(s16 *)(p + 0x1C) = *s++) != 0xFF) *(u8 **)(p + 0x14) = s;
}
