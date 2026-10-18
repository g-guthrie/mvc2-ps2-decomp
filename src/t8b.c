typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { float x, y, z; } Float3;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0033E600();
extern void func_0032ECB0();
extern void func_0033C240();
extern void func_0032ED60(s32);
extern u32 D_004C283C;
extern Float3 D_004B8280;
extern Float3 D_0045ECE0[];
extern u8 D_004C27D0;

void func_0032ECC0(void) {
    u8 *p;
    s32 i = 0;
    do {
        func_0032ED60(i);
        i++;
    } while (i < 4);
    if ((D_004C27D0 & 0x1F) == 0) {
        if ((p = func_003DA750(0, 6, 1)) != 0) {
            p[0x13C] = 1;
            *(void **)(p + 0x10) = func_0032ECB0;
            *(s16 *)(p + 0xCC) = 0xF;
            *(u32 *)(p + 0x84) = D_004C283C;
            *(u32 *)(p + 0xD0) = 0x801;
            *(u32 *)(p + 0x34) = 0;
            *(u32 *)(p + 0x38) = 0x3DCCCCCD;
            *(u32 *)(p + 0x3C) = 0;
        }
    }
}
