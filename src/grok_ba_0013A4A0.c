typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct { float x, y, z; } Float3;

extern void *func_003DA750(void *, s32, s32);
extern void func_0013A5B0(u8 *);
extern void func_0032DE90(u8 *, s16, float, float);
extern u32 D_004C2830 __attribute__((section(".sdata")));

void func_0013A4A0(u8 *owner, u8 mode)
{
    u8 *p;
    if ((p = (u8 *)func_003DA750(0, 6, 1)) != 0) {
        *(u8 **)(p + 0x18) = owner;
        *(u8 **)(p + 0x14) = *(u8 **)(owner + 0x14);
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 16) = func_0013A5B0;
        p[0x20] = owner[0x20];
        p[0x21] = owner[0x21];
        p[0x22] = mode;
        if (mode < 2) {
            *(s16 *)(p + 0xCC) = owner[0x20] + 0x6E;
            *(u32 *)(p + 0x84) = D_004C2830;
        } else {
            *(s16 *)(p + 0xCC) = owner[0x20] + 0xB7;
            *(u32 *)(p + 0x84) = D_004C2830;
        }
        *(Float3 *)(p + 0x34) = *(Float3 *)(owner + 0x34);
        *(u32 *)(p + 0x40) = *(u32 *)(owner + 0x40);
        *(u32 *)(p + 0x44) = *(u32 *)(owner + 0x44);
        *(u32 *)(p + 0x48) = *(u32 *)(owner + 0x48);
        *(u32 *)(p + 0xD0) = 0x809;
        if (mode)
            func_0032DE90(p, (s16)(p[0x20] + 0x6E), 0.1875f, 0.0f);
    }
}
