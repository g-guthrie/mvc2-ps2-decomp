typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad[0x14];
    s16 h14;
} HzNode3EBC;

extern u16 D_0062BC34;

s32 func_003EBC20(u8 *a, u8 *s0) {
    extern s32 func_003EB960();
    extern void func_003EBA10(s32, u8 *);
    extern void func_003EB9C0(u8 *);
    u8 *s1 = a;
    HzNode3EBC *n;
    if (s1 == 0) {
        if ((s1 = (u8 *)func_003EB960()) == 0) {
            return 0;
        }
        func_003EBA10(0, s1);
        *(u16 *)(s1 + 0x14) = D_0062BC34;
    } else {
        if ((n = *(HzNode3EBC **)(s1 + 4)) != 0) {
            while ((s32)(n->h14 - *(s16 *)(s1 + 0x14)) < *(s16 *)(s0 + 0x10)) {
                func_003EB9C0((u8 *)n);
                if ((n = *(HzNode3EBC **)(s1 + 4)) == 0) {
                    break;
                }
            }
        }
    }
    *(s16 *)(s0 + 0x12) = *(s16 *)(s1 + 0x14);
    *(u8 **)(s1 + 8) = s0;
    *(u32 *)(s1 + 0xC) = *(u32 *)(s0 + 4);
    *(u32 *)(s1 + 0x10) = *(u32 *)(s0);
    *(s16 *)(s1 + 0x16) = *(s16 *)(s0 + 0x10);
    return 1;
}
