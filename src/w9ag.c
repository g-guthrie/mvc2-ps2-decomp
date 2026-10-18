typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_004BF864[2])(void *);
void func_001B2780(u8 *p) {
    u8 *s = *(u8 **)(p + 0x18);
    D_004BF864[p[5]](p);
    if (*(s8 *)(s + 0x1B3) != 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}


extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern u32 D_004C283C;

typedef struct { f32 x, y, z; } V3;
extern V3 D_0045FA18;
void func_00340000(void);
void func_0033FF70(u8 *p) {
    u8 *r = func_003DA750(0, 6, 0);
    if (r != 0) {
        r[0x13C] = 1;
        *(u32 *)(r + 0x10) = (u32)func_00340000;
        *(s16 *)(r + 0xCC) = 0x15;
        *(u32 *)(r + 0x84) = D_004C283C;
        *(V3 *)(r + 0x34) = D_0045FA18;
        *(u32 *)(r + 0x44) = 0xE001;
        *(u32 *)(r + 0xD0) = 0x805;
        *(u8 **)(r + 0x18) = p;
    }
}
