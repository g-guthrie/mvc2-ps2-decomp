typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 a; u8 b; u8 pad[4]; u8 g; } S37;
void func_0037F480(u8 *p) {
    extern s8 *D_004C2998;
    extern S37 *D_004C299C;
    extern void func_001757E0();
    u32 v;
    if (D_004C299C->a != *D_004C2998) {
        D_004C299C->a = *D_004C2998;
        v = (u8)(D_004C299C->a * 3);
        if (D_004C299C->g != 0)
            v = (u8)(v + D_004C299C->b);
        func_001757E0(p, 0x19, (u8)v);
    }
    if (D_004C299C->a >= 4) {
        *(u32 *)(p + 0x50) = 0x40033333;
        *(u32 *)(p + 0x54) = 0x40000000;
    } else if (D_004C299C->a == 3) {
        *(u32 *)(p + 0x50) = 0x40033333;
        *(u32 *)(p + 0x54) = 0x3F800000;
    } else {
        *(u32 *)(p + 0x50) = 0x3F866666;
        *(u32 *)(p + 0x54) = 0x3F800000;
    }
}
