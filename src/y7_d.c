typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_004000D0(s32 a0) { return a0 + 0x58; }

s32 func_001044C8(s32 descriptor) { return -1; }

s32 func_001044D0(void) { return -1; }
typedef struct { f32 x, y, z; } V3;
extern s32 D_004C2838;

void func_0015DCA0(V3 *a, s16 b) {
    extern u8 *func_003DA750();
    extern void func_0015E060();
    u8 *o;
    if ((o = func_003DA750(0, 9, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0015E060;
        *(s16 *)(o + 0xCC) = 0xCD;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *a;
        *(u32 *)(o + 0xD0) = 0x800025;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        *(s32 *)(o + 0x74) = 0;
        *(s16 *)(o + 0x140) = b;
        *(s32 *)(o + 0x44) += (*(s16 *)(o + 0x140) != 0) ? 0x8000 : 0;
    }
}

void func_0015DA50(V3 *a, s32 b) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0015DE10(void);
    u8 *o;
    if ((o = func_003DA750(0, 8, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0015DE10;
        *(s16 *)(o + 0xCC) = 0xAA;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *a;
        *(u32 *)(o + 0xD0) = 0x800415;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        *(f32 *)(o + 0x74) = 1.0f;
        *(f32 *)(o + 0x78) = 0.0f;
        *(f32 *)(o + 0x7C) = 0.0f;
        *(f32 *)(o + 0x80) = 0.0f;
        *(f32 *)(o + 0x50) = 1.0f;
        *(f32 *)(o + 0x54) = 1.0f;
        *(f32 *)(o + 0x58) = 1.0f;
        *(s16 *)(o + 0x140) = b;
        *(s32 *)(o + 0x44) += *(s16 *)(o + 0x140) != 0 ? 0x8000 : 0;
    }
}
