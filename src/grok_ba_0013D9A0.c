typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct { float value[3]; } F32Vector3;
typedef struct { F32Vector3 endpoints[2]; } F32VectorPair;
typedef struct { s8 b; u8 pad[0x5B7]; } Slot;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_0013DAA0(u8 *);
extern Slot D_004F25F0[];
extern u32 D_004C282C __attribute__((section(".sdata")));
extern F32VectorPair data_f32pair_004B16A0[6];

void func_0013D9A0(s32 i)
{
    u8 *p;
    s32 r = i % 3;
    if (r != 1) {
        if (D_004F25F0[i / 3 + 2 * r].b == r + 0x18)
            return;
    }
    if ((p = func_003DA750(0, 6, 1)) != 0) {
        p[0x13C] = 1;
        p[0x20] = i;
        *(void (**)(u8 *))(p + 16) = func_0013DAA0;
        *(s16 *)(p + 0xCC) = i + 1;
        *(u32 *)(p + 0x84) = D_004C282C;
        *(F32Vector3 *)(p + 0x34) = data_f32pair_004B16A0[i].endpoints[0];
        *(u32 *)(p + 0xD0) = 0x801;
        *(s16 *)(p + 0x1C) = 0;
    }
}
