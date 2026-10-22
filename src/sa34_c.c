typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2814;

void func_00141420(u8 *p) {
    extern void func_00170E60();
    extern void func_001412D0();
    s32 st[3];
    s32 *tab;
    u8 *q;
    s32 *r;
    if (p[0x23] != 0x34) {
        *(u16 *)(p + 0x26) += 0x24;
        if (*(u16 *)(p + 0x26) >= 0x168) *(u16 *)(p + 0x26) = 0;
        r = st;
        q = *(u8 **)(p + 0x84);
        st[0] = (s32)p;
        st[1] = 0;
        st[2] = 0;
        tab = *(s32 **)(q + 0x1C);
        func_00170E60(*(s32 *)(D_004C2814 + 0x14), tab[p[0x23] + 1], *(s32 *)(q + 0x14), tab[*(s16 *)(p + 0xCC)], func_001412D0, (s32 *)((s32)st + 0));
    } else {
        *(u16 *)(p + 0x26) += 1;
        if (*(u16 *)(p + 0x26) > 0x32) *(u16 *)(p + 0x26) = 0;
        *(u32 *)(p + 0xD0) |= 0x20000;
        *(u32 *)(p + 0xE0) = 0;
        *(f32 *)(p + 0xE4) = -(0.02f * (f32)(u32)*(u16 *)(p + 0x26));
    }
}
