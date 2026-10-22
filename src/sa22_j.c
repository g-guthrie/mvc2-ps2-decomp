typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct S {
    u8 pad0[0x38];
    f32 f38;
    u8 pad3C[0x24];
    f32 f60;
    u8 pad64[0x8];
    f32 f6C;
    u8 pad70[0x147];
    u8 b1B7;
    u8 pad1B8[0x1A6];
    u16 h35E;
    u8 pad360[0xD0];
    f32 f430;
} S;
void func_0020C2F0(S *a, u8 *b)
{
    extern s32 func_0020D2F0();
    extern void func_0020D250();
    extern s32 func_00175700();
    u32 h;
    f32 lim;
    f32 *x, *y;
    if (func_0020D2F0(a, b) != 0) {
        func_0020D250(a, b, 5);
        return;
    }
    h = a->h35E;
    if ((h & 0x300) != 0) {
        a->b1B7 = (h & 0x100) != 0 ? 1 : 0;
        func_0020D250(a, b, 3);
    } else if ((h & 0x60) != 0) {
        if ((h & 0x1000) != 0) {
            func_0020D250(a, b, 6);
        } else {
            a->b1B7 = (h & 0x20) != 0 ? 1 : 0;
            func_0020D250(a, b, 4);
        }
        return;
    } else if ((h & 0x800) != 0) {
        func_0020D250(a, b, 2);
    } else if ((h & 0x2000) == 0) {
        func_0020D250(a, b, 0);
    } else {
        x = &a->f60;
        y = &a->f6C;
        a->f38 += a->f60;
        a->f60 += a->f6C;
        if (!(a->f38 < (lim = 788.5714111328125f + a->f430))) {
            a->f38 = lim;
            *x = 0;
            *y = 0;
        }
        func_00175700(a);
    }
}
