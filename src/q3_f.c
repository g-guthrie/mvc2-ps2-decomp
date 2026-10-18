typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u8 *D_004C2794;
extern u8 D_004F20B0[];

void func_00327C70(void) {
    u8 *e;
    s32 i, c, a, off;
    a = 0;
    i = 0;
    off = 0;
    c = *(s8 *)(D_004C2840 + 0x9C);
    do {
        e = D_004F20B0 + off;
        if (e[0] != 0) a = (s8)(a | *(s8 *)(e + 0x33C));
        off += 0x5B8;
        i++;
    } while (i < 6);
    if (a == 0) { if (c != 0) D_004C2794[0x76] = 0; }
    D_004C2840[0x9C] = D_004C2794[0x76];
}
