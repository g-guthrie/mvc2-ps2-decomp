typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_00137BF0(u8 *);
extern void func_00170DF0(void *);
extern void func_0013B1C0(u8 *);
extern u8 *D_004C2924 __attribute__((section(".sdata")));
extern u32 D_004C2830 __attribute__((section(".sdata")));

void func_00137B00(u8 a, u8 b)
{
    u8 *p;
    if ((p = func_003DA750(0, 6, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 16) = func_00137BF0;
        p[0x20] = a;
        p[0x21] = b;
        *(u8 **)(p + 0xC8) = D_004C2924 + 0x88;
        *(s16 *)(p + 0xCC) = (a << 1) + 0x97;
        *(u32 *)(p + 0x84) = D_004C2830;
        *(u32 *)(p + 0x40) = 0;
        *(u32 *)(p + 0x44) = 0;
        *(u32 *)(p + 0x48) = 0;
        *(u32 *)(p + 0xD0) = 0x4830;
        *(u32 *)(p + 0x50) = 0x3F99999A;
        *(u32 *)(p + 0x54) = 0x3F99999A;
        *(u32 *)(p + 0x58) = 0x3F99999A;
        *(u32 *)(p + 0x74) = 0x3F800000;
        p[1] = 0xFF;
        func_00170DF0(*(void **)(p + 0x84));
        *(s32 *)(p + 0x48) = p[0x20] ? -0x2000 : 0x2000;
        func_0013B1C0(p);
    }
}
