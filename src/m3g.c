typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C299C;
extern u8 *D_004C2998;
extern void (*D_004642E0[])(void);
extern void (*D_004642F0[])(void);

static void func_0037F1D0(u8 *p) {
    f32 k = 1.666666627f;
    f32 s;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    s = k * (f32)(s32)(D_004C299C[6] << 5);
    if (*(s16 *)(p + 0x140) == 0) s = -s;
    *(f32 *)(p + 0x34) += s;
}

void func_0037F230(u8 *p) {
    if (p[0x20] == 0) {
        D_004C299C = p + 0x88;
        D_004642E0[p[4]]();
    } else {
        D_004C299C = p + 0x88;
        D_004C2998 = *(u8 **)(p + 0x18) + 0x88;
        func_0037F1D0(p);
        D_004642F0[p[4]]();
    }
}
