typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { f32 a, b, c, d; } V4;
extern u8 D_004BF33C[4];
extern u8 *D_004C2834;
extern V3 D_0043DFC0[];
extern V3 D_0043DF58[];
extern V4 D_0043E150[];
extern u8 *D_004CAB90[];

void func_001325A0(u8 *o, s16 *h, s32 idx) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001331E0();
    extern void func_001324F0(u8 *);
    u8 *n;
    if (*h != 0) {
        if ((n = func_003DA750(0, 0xD, 1)) != 0) {
            n[0x13C] = 1;
            *(void **)(n + 0x10) = (void *)func_001331E0;
            *(u32 *)(n + 0x84) = *(u32 *)(D_004C2834 + 0x14) + D_004BF33C[o[2]] * 180;
            *(s16 *)(n + 0xCC) = D_004BF33C[o[2]];
            *(u8 **)(n + 0x84) = D_004C2834;
            *(V3 *)(n + 0x34) = D_0043DFC0[o[2]];
            *(V3 *)(n + 0x50) = D_0043DF58[0];
            n[2] = o[2];
            *(u8 **)(n + 0x18) = o;
            *(u32 *)(n + 0xD0) = 0x10C11;
            *(s16 **)(n + 0xD4) = h;
            *(s16 *)(n + 0x1C) = *h;
            *(V4 *)(n + 0x74) = D_0043E150[idx];
            func_001324F0(n);
            D_004CAB90[o[0x1B8]] = n;
        }
    }
}
