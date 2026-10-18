typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern u8 D_004C1AC0[4];
extern u8 D_004C1AC4[4];
extern void func_001757E0();
extern s32 D_004C1ACC;
static void func_003578A0(void) { D_004C1ACC = 1; }
static void func_00357B30(void) { D_004C1ACC = 2; }

void func_00357F20(u8 *p) {
    s32 n;
    s32 *d;
    s32 *s;
    u32 t;
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    t = p[4]; p[4] = t + 1;
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    do {
        *d++ = *s++;
    } while (--n > 0);
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
    p[0x24] = 10;
    p[0x1B0] = 0;
    p[0x1B1] = 0;
    if (p[0x20] == 2) {
        func_003578A0();
        func_001757E0(p, 0x15, D_004C1AC0[p[0x21]]);
    } else {
        func_00357B30();
        func_001757E0(p, 0x15, D_004C1AC4[p[0x21]]);
    }
}
