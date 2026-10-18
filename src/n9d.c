typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
#define P(t,o) (*(t*)(p+(o)))
#define Q(t,o) (*(t*)(*(u8**)(p+0x18)+(o)))

extern u8 *D_004D3690[];
extern void func_00151A90(u8 *, s32);
void func_00151A20(s32 a) {
    u8 *n = D_004D3690[(u8)a];
    if (n) {
        do {
            func_00151A90(n, a);
            n = *(u8 **)(n + 0xC);
        } while (n);
    }
}
