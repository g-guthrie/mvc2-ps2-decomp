typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;

void func_0033DB90(void) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0033DB80();
    extern s32 D_004C283C;
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033DB80;
        *(s16 *)(o + 0xCC) = 0x25;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x800820;
        *(f32 *)(o + 0x78) = 1.0f;
        *(f32 *)(o + 0x80) = 1.0f;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x74) = 0.5f;
    }
}
