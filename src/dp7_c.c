typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* MW 3.0.3: ./try.sh src/sa4_b.c "-O3 -Op -sdatathreshold 8" */
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 a, b; } V2;
extern V3 D_004B77A0[];
extern V2 D_004B7810[];
extern u8 *D_004C2840;
extern s32 D_004C283C;

typedef struct { u8 pad[0x1C]; s16 h; } PH;
void func_0032EF10(u8 *p) {
    extern s32 func_00417A40();
    s32 i;
    u32 t, u4;
    s32 r;
    f32 one;
    s16 h = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0x78) return;
    ((PH *)p)->h = 0x78;
    t = *(u32 *)(D_004C2840 + 0x94);
    if (t > 0x1F4 && t < 0x3E8) return;
    if (t > 0xDAC) return;
    u4 = p[4];
    p[4] = u4 + 1;
    p[5] = 0;
    *(s16 *)(p + 0x1C) = 0;
    r = func_00417A40();
    *(s16 *)(p + 0xCC) = r % 4 + 3;
    *(s32 *)(p + 0x84) = D_004C283C;
    i = (u32)func_00417A40() % 9;
    *(V3 *)(p + 0x34) = D_004B77A0[i];
    *(s32 *)(p + 0x44) = (s32)D_004B7810[i].a;
    *(s32 *)(p + 0x48) = (s32)D_004B7810[i].b;
    *(u32 *)(p + 0x78) = 0x3F800000;
    *(u32 *)(p + 0x7C) = 0x3F800000;
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
}
