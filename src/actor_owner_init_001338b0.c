typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16;
void func_001338B0(u8 *p, u8 *owner) {
    p[4]++;
    *(u16 *)(p+0x13e) = 0;
    *(u16 *)(p+0x144) = 0;
    *(u16 *)(p+0x140) = 0;
    p[0x14f] = 0;
    p[0x14e] = 0;
    p[0x20] = 0;
    if (*(s8 *)(owner+0x539) != 0) p[0x14e] = 0xff;
}
