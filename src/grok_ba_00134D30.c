typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct { float x, y, z; } Float3;
typedef struct { u8 pad[0x428]; u32 flags; u8 rest[0x5B8 - 0x42C]; } Ent;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_00134EA0(u8 *);
extern Ent D_004F20B0[];
extern u32 D_004C2834 __attribute__((section(".sdata")));
extern Float3 D_0043E970[];
extern Float3 D_0043E988;

void func_00134D30(s32 i)
{
    u8 *p;
    if (D_004F20B0[i].flags & 0x7000000)
        return;
    if ((p = func_003DA750(0, 0xD, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 16) = func_00134EA0;
        *(s16 *)(p + 0xCC) = 0x60;
        *(u32 *)(p + 0x84) = D_004C2834;
        *(Float3 *)(p + 0x34) = D_0043E970[i];
        *(u32 *)(p + 0xD0) = 0x10C11;
        p[0x20] = i;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        *(Float3 *)(p + 0x50) = D_0043E988;
        *(u32 *)(p + 0x80) = 0x3F800000;
        *(u32 *)(p + 0x7C) = 0x3F800000;
        *(u32 *)(p + 0x78) = 0x3F800000;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0x46AAAA00;
        *(u32 *)(p + 0x70) = 0x472AAA00;
    }
}
