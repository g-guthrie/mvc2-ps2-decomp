typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x28];
    s8 initialized;
} GlobalState;

extern GlobalState *volatile D_004C2840 __attribute__((section(".sdata")));
extern u32 D_004F1CB4;
extern u32 D_004F1CB8;
extern u32 D_004F1CBC;

void func_0016CE90(void) {
    if (!D_004C2840->initialized) {
        D_004F1CB4 = 6;
        D_004F1CB8 = 0x18;
        D_004F1CBC = 0x00FFFFFF;
    }
}
