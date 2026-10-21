typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2840;
extern s8 D_004C2864;
extern s8 D_004C285C;
extern s8 D_004C286C;
extern u8 D_004BF397[5];
extern V3 D_004439C0[];

void func_001486B0(u8 *p) {
    extern void func_0012AD00();
    s32 b;
    u32 k;
    if (p[0x20] == *(s16 *)(D_004C2840 + 8)) {
        func_0012AD00(p);
        *(u32 *)(p + 0x78) = 0x3F800000;
        *(u32 *)(p + 0x7C) = 0x3F800000;
        *(u32 *)(p + 0x80) = 0x3F800000;
    } else {
        u32 t = 0x3F333333;
        *(s16 *)(p + 0x1E) = 0;
        *(u32 *)(p + 0x78) = t;
        *(u32 *)(p + 0x7C) = t;
        *(u32 *)(p + 0x80) = t;
        *(u32 *)(p + 0x74) = 0x3F800000;
    }
    k = p[0x20];
    if (k == 1) b = D_004C2864;
    else if (k == 3) b = D_004C285C;
    else b = D_004C286C ^ 1;
    *(V3 *)(p + 0x34) = D_004439C0[D_004BF397[k] + b];
}
