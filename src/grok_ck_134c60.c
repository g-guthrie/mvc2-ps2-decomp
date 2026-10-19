typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct { float x, y, z; } Float3;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_00134E40(u8 *);
extern void func_00135140(u8 *);
extern u32 D_004C2834 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern Float3 D_0043E950[];

void func_00134C60(s32 mode)
{
    u8 *p;
    if ((p = func_003DA750(0, 0xE, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 16) = func_00134E40;
        *(s16 *)(p + 0xCC) = 0x55;
        *(u32 *)(p + 0x84) = D_004C2834;
        *(Float3 *)(p + 0x34) = D_0043E950[mode];
        *(u32 *)(p + 0xD0) = 0x10801;
        p[0x20] = (u8)mode;
        if (*(s8 *)(D_004C2840 + 0x4D) == 3) {
            *(void (**)(u8 *))(p + 16) = func_00135140;
            *(s16 *)(p + 0xCC) = 0x5F;
            *(u32 *)(p + 0x84) = D_004C2834;
        }
    }
}
