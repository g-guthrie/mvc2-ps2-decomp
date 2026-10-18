typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x34]; f32 f34; } PF;

void func_00266280(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001B3E30(u8 *, s32, s32);
    u8 *a;
    f32 k;
    u32 t;
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(u32 *)(p + 0x48) = 0xE000;
    if (func_00175700(p) < 0) {
        p[0x151] = 0;
        k = 106.66666412353516f;
        t = p[6];
        p[6] = t + 1;
        a = *(u8 **)(p + 0x14);
        *(u32 *)(p + 0x48) = 0x4000;
        *(f32 *)(p + 0x34) = *(f32 *)(a + 0x34) - k;
        if (*(s16 *)(p + 0x140) != 0) {
            ((PF *)p)->f34 = k + ((PF *)a)->f34;
        }
        v = *(s16 *)(a + 0x1C) - 1;
        *(s16 *)(a + 0x1C) = v;
        switch (p[0x20]) {
        case 0x18:
            *(f32 *)(p + 0x38) = 154.28570556640625f + *(f32 *)(a + 0x38);
            func_001B3E30(p, 0x12, 5);
            break;
        case 0x14:
            *(f32 *)(p + 0x38) = 137.14285278320312f + *(f32 *)(a + 0x38);
            func_001B3E30(p, 0x11, 5);
            break;
        case 0x10:
            *(f32 *)(p + 0x38) = 154.28570556640625f + *(f32 *)(a + 0x38);
            func_001B3E30(p, 0x10, 5);
            break;
        }
    }
}
