typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00187D70();
extern s32 func_001884C0();
extern void func_001843A0();
extern s8 func_00175700();

void func_0017B760(u8 *a) {
    if (*(s8 *)(a + 0x1F1) >= 0) {
        if (func_00187D70() != 0) return;
        if (func_001884C0(a) != 0) return;
        if (*(u16 *)(a + 0x354) & 0x360) {
            func_001843A0(a);
            return;
        }
    }
    if (func_00175700(a) < 0) {
        *(s32 *)(a + 0x5C) = 0;
        *(s32 *)(a + 0x60) = 0;
        *(s32 *)(a + 0x68) = 0;
        *(s32 *)(a + 0x6C) = 0;
        func_001843A0(a);
    }
}

extern u8 *func_003DA750();
extern void func_0037CF40();
extern void func_0037CC50();

u8 *func_0037CBB0(u8 *a) {
    u8 *o;
    if (*(s8 *)(a + 0x1B2) != 0) {
        if ((o = func_003DA750(0, 3, 0)) == 0) return 0;
        *(void **)(o + 0x10) = (void *)func_0037CF40;
    } else {
        if ((o = func_003DA750(0, 1, 0)) == 0) return 0;
        *(void **)(o + 0x10) = (void *)func_0037CC50;
    }
    *(u8 **)(o + 0x18) = a;
    *(s16 *)(o + 0x26) = 0x1704;
    *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
    return o;
}
