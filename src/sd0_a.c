typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 x[0x31]; } S31;
typedef struct { u8 pad[0x14]; u8 *x14; } PA;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;

void func_003762B0(u8 *p) {
    extern void func_00376A40(u8 *);
    extern void func_0018D930(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *a1;
    PA *pa = (PA *)p;
    if (p[4] == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        *(S31 *)(p + 0xEC) = *(S31 *)(*(u8 **)(p + 0x18) + 0xEC);
        p[0x13C] = 1;
        p[2] = (*(u8 **)(p + 0x18))[2];
        p[1] = (*(u8 **)(p + 0x18))[1];
        *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
        p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
        p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
        p[0x13C] = 0;
        p[0x1B0] = 0;
        p[0x1B1] = 0x44;
    }
    if ((*(u8 **)(p + 0x18))[0x425] != p[0x23]) {
        func_00376A40(p);
        return;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(pa->x14 + 0x34);
    a1 = pa->x14;
    if (*(s8 *)(a1 + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0 || a1[5] > 1 || a1[4] > 1) {
        if (*(s8 *)(p + 0x1B3) != 0) func_0018D930(p);
        func_00376A40(p);
    } else {
        *(V4 *)(p + 0x150) = *(V4 *)(a1 + 0x150);
        *(f32 *)(p + 0x160) = *(f32 *)(a1 + 0x160);
        *(s32 *)(p + 0x1D4) = *(s32 *)(pa->x14 + 0x1D4);
        a1 = pa->x14;
        if (a1[4] == 1 && a1[5] == 1) func_001E7F60(p);
    }
}
