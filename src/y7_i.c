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
extern f32 D_004F1FC8, D_004F1FCC;

void func_0027E920(u8 *a) {
    extern s8 func_00175700();
    extern void func_00280330(void *);
    extern void func_00381F30();
    V3 v;
    if (func_00175700(a) < 0) {
        func_00280330(a);
        return;
    }
    if (*(s8 *)(a + 0x151) != 0) {
        *(s8 *)(a + 0x151) = 0;
        v = *(V3 *)(a + 0x34);
        if (*(s16 *)(a + 0x140) != 0) {
            v.x += 320.0f * *(f32 *)(a + 0x50);
        } else {
            v.x -= 320.0f * *(f32 *)(a + 0x50);
        }
        v.y = *(f32 *)(a + 0x430) - 40.0f;
        func_00381F30(a, &v, 4, 0);
    }
}

