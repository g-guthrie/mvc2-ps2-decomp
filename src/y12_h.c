typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 a, b; } P2;
extern P2 D_004B3AF0[];
extern volatile s32 D_004C2838;
extern volatile s32 D_004BF44C;
void func_0015B160(u8 *p) {
    extern s32 func_00153AA0();
    extern void func_00170DA0();
    P2 *t = D_004B3AF0;
    if (*(s16 *)(p + 0x1C) != 0) {
        s32 n, g, h;
        f32 x, y;
        n = func_00153AA0();
        g = D_004C2838;
        h = D_004BF44C;
        func_00170DA0(g, h + 1, n, *(s16 *)(p + 0xCC));
        t += *(s16 *)(p + 0x1C) - 1;
        y = t->b;
        x = t->a;
        *(f32 *)(p + 0xE0) = x;
        *(f32 *)(p + 0xE4) = y;
        *(u32 *)(p + 0xD0) |= 0x20000;
    }
}
