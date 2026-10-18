typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G1;

typedef struct { f32 a, b, c, d; } V4;
typedef struct { V3 pos; u16 hC; u8 bE; s8 bF; } E16;
extern E16 *D_00442B40[];
extern V4 D_004439B0;
extern s32 D_004C2804;

void func_00147750(u8 *p, u8 *a1, s32 idx) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00148950();
    u8 *o;
    E16 *e;
    s32 i;
    e = D_00442B40[idx];
    i = 1;
    for (;;) {
        o = func_003DA750(0, 0xD, 1);
        if (o == 0) break;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00148950;
        o[0x23] = (u8)(s32)a1;
        o[0x20] = p[0x20];
        o[0x21] = i;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u16 *)(o + 0xCC) = e->hC;
        *(s32 *)(o + 0x84) = D_004C2804;
        *(V3 *)(o + 0x34) = e->pos;
        *(V3 *)(o + 0x50) = *(V3 *)(p + 0x50);
        *(u32 *)(o + 0xD0) = 0x800431;
        *(V4 *)(o + 0x74) = D_004439B0;
        i++;
        if (e->bF < 0) break;
        e++;
    }
}
