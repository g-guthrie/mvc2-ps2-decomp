/* s5d: MW 3.0.3, ./try.sh src/s5d_b.c "-O3 -Op -sdatathreshold 8" (also 3.0). static func_001448E0 is the real callee and address predecessor (credited in src/z10_b.c); with it MW fills the beq slot with addiu v1. */
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;typedef float f32;
typedef struct { f32 x, y, z; } V3_1448E0;
extern V3_1448E0 D_004B3200[];
static void func_001448E0(u8 *p) {
    V3_1448E0 *a = &D_004B3200[p[0x20] * 2];
    V3_1448E0 *b = &D_004B3200[p[0x20] * 2 + 1];
    *(f32 *)(p + 0x34) = a->x + (f32)*(s16 *)(p + 0x1C) * (b->x - a->x) / 90.0f;
    *(f32 *)(p + 0x38) = a->y + (f32)*(s16 *)(p + 0x1C) * (b->y - a->y) / 90.0f;
    *(f32 *)(p + 0x3C) = a->z + (f32)*(s16 *)(p + 0x1C) * (b->z - a->z) / 90.0f;
    *(f32 *)(p + 0x34) /= 10.0f;
    *(f32 *)(p + 0x38) /= 10.0f;
    *(f32 *)(p + 0x3C) /= 10.0f;
}
typedef struct { u8 pad[2]; s8 b; } G;
typedef struct { u8 pad[0x1C]; s16 a; s16 c; u8 p2[0xD0-0x20]; u32 d0; u8 p3[0xC]; u32 e0; f32 e4; } P;
extern G *D_004C2840;
void func_00144BF0(P *p) {
    extern void func_003DAA40(); 
    
    if (D_004C2840->b != 5) { func_003DAA40(); return; }
    if (p->a != 0x5A) { p->a++; func_001448E0((u8*)p); return; }
    p->c++;
    if (p->c >= 200) p->c = 0;
    p->d0 |= 0x20000;
    p->e0 = 0;
    p->e4 = 1.0f - 0.005f * (f32)p->c;
}
