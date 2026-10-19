typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern s16 D_004C27A4;

s32 func_001D2390(u8 *p, s32 animation)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001D24A0(u8 *);
    extern void func_001D2680(u8 *);
    u8 *first;
    u8 *event;
    s32 i;
    if (D_004C27A4 < 14) return 0;
    first = func_003DA750(0, 3, 1);
    *(s16 *)(first + 0x26) = 0x2B03;
    first[0x21] = animation;
    *(u8 **)(first + 0x18) = p;
    *(void (**)(u8 *))(first + 0x10) = func_001D24A0;
    for (i = 0; i < 6; i++) {
        event = func_003DA750(0, 3, 1);
        *(s16 *)(event + 0x26) = 0x2B03;
        event[0x23] = i;
        event[0x20] = 0;
        event[0x21] = animation;
        *(u8 **)(event + 0x14) = first;
        *(void (**)(u8 *))(event + 0x10) = func_001D2680;
    }
    for (i = 0; i < 6; i++) {
        event = func_003DA750(0, 3, 1);
        *(s16 *)(event + 0x26) = 0x2B03;
        event[0x23] = i;
        event[0x20] = 1;
        event[0x21] = animation;
        *(u8 **)(event + 0x14) = first;
        *(void (**)(u8 *))(event + 0x10) = func_001D2680;
    }
    return 1;
}
