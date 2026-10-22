typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004F20B0[];
extern u8 D_00583B92[];
extern u8 D_00583BC4[];
extern s8 D_004C27C0;
extern u8 D_004C27C4;

void func_0032ADC0(u8 *p) {
    extern void func_0032D970(u8 *);
    extern void func_00137EC0(u8 *);
    extern void func_001E60B0(s32);
    extern void func_001E6490(s32);
    extern void func_00137B00(s32, s32);
    extern void func_00139D00(u8 *, s32);
    u8 i;
    s32 j;
    s32 b;
    p[4] = 4;
    *(u8 **)(p + 0x18) = D_004F20B0 + (*(s8 *)(p + 0x538) + *(s16 *)(p + 0x1E) * 2) * 0x5B8;
    if ((D_00583B92[*(s8 *)(p + 0x538)] & 7) != 7) {
        func_0032D970(p);
        func_00137EC0(p);
        D_004C27C4 = 1;
        D_004C27C0 |= *(s8 *)(p + 0x538) + 1;
        func_001E60B0(*(s8 *)(p + 0x538) + *(s16 *)(p + 0x1E) * 2);
        func_001E6490(*(s8 *)(p + 0x538) + *(s16 *)(p + 0x1E) * 2);
        D_00583BC4[*(s8 *)(p + 0x538)] = *(s8 *)(p + 0x1E) + 1;
        func_00137B00(p[0x538], p[0x1E]);
    } else {
        *(s16 *)(p + 0x1E) = 2;
        p[4] = 10;
        i = 0;
        j = 0;
        for (; i < 3; i++) {
            *(u8 **)(p + 0x18) = D_004F20B0 + (*(s8 *)(p + 0x538) + j) * 0x5B8;
            b = *(s8 *)(p + 0x538);
            func_00139D00(D_004F20B0 + (b + j) * 0x5B8, (u8)b);
            j += 2;
        }
    }
}
