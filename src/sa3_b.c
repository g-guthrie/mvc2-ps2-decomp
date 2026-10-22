typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/sa3_b.c "-O4,p -sdatathreshold 8" */
typedef struct { f32 x, y, z; } Float3;
typedef struct { u8 pad[0x428]; u32 flags; u8 rest[0x5B8 - 0x42C]; } Ent_b;
typedef struct { f32 a, b, c, d; } Float4;

extern void *func_003DA750(void *, s32, s32);
extern void func_00132C70(u8 *);
extern void func_00131AA0(u8 *);
extern void func_003DAA40(u8 *);
extern Ent_b D_004F20B0[];
extern u32 D_004C2834 __attribute__((section(".sdata")));
extern Float3 D_0043DEA0[];
extern Float3 D_0043DF58;
extern Float4 D_0043E120;

void func_00131F90(s32 a, s32 b)
{
    u8 *p;
    s32 v;
    if ((p = func_003DA750(0, 0xD, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 16) = func_00132C70;
        v = 0x3F;
        if (a != 0) v = 0x48;
        *(s16 *)(p + 0xCC) = v;
        *(u32 *)(p + 0x84) = D_004C2834;
        *(Float3 *)(p + 0x34) = D_0043DEA0[(a << 1) + b];
        *(Float3 *)(p + 0x50) = D_0043DF58;
        *(u32 *)(p + 0xD0) = 0x10C11;
        p[0x20] = a;
        p[0x21] = b;
        p[0x22] = 0;
        *(Ent_b **)(p + 0x18) = D_004F20B0 + a;
        *(f32 *)(p + 0x80) = 1.0f;
        *(f32 *)(p + 0x7C) = 1.0f;
        *(f32 *)(p + 0x78) = 1.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x6C) = 21845.0f;
        *(f32 *)(p + 0x70) = 43690.0f;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        if ((((Ent_b *)*(u8 **)(p + 0x18))->flags & 0x7000000) != 0) {
            p[0x13C] = 0;
            *(void (**)(u8 *))(p + 16) = func_00131AA0;
            *(Float4 *)(p + 0x74) = D_0043E120;
            if (b != 0) func_003DAA40(p);
        }
    }
}
