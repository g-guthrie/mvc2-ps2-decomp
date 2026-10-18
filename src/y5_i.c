typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_i;
typedef struct { u8 b0; u8 pad[0x5B7]; } E5b8_i;
extern E5b8_i D_004F20B0[];
extern u8 D_004F24D5[];
extern V3_i D_0043DF58;
extern u32 D_004C2834;

void func_00132400(u8 *a, s32 b)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00133140(u8 *);
    u8 *o;
    if ((o = func_003DA750(0, 0xE, 1)) != 0) {
        s16 h;
        o[0x13C] = 1;
        *(void (**)(u8 *))(o + 0x10) = func_00133140;
        h = 0x6A;
        if (b & 1) h = 0x6B;
        *(s16 *)(o + 0xCC) = h;
        *(u32 *)(o + 0x84) = D_004C2834;
        *(V3_i *)(o + 0x50) = D_0043DF58;
        *(u32 *)(o + 0xD0) = 0x10C11;
        *(u32 *)(o + 0x34) = 0;
        *(u32 *)(o + 0x38) = 0;
        *(u32 *)(o + 0x3C) = 0xBE000000;
        *(u8 **)(o + 0xC8) = a + 0x88;
        o[0x20] = b;
        o[0x21] = D_004F24D5[b * 0x5B8];
        *(u8 **)(o + 0x18) = (u8 *)D_004F20B0 + b * 0x5B8;
        *(u8 **)(o + 0x14) = a;
    }
}
