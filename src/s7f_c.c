/* func_0016DA30: MW 3.0 (try30.sh) -O4 -Op -sdatathreshold 8. The +1 row test is a ternary with an inclusive upper bound. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f0, f4, f8; u32 fC; f32 f10, f14, f18; u32 f1C; s32 f20; f32 f24, f28, f2C, f30; } G6DA30;
extern G6DA30 D_004CB100[];
extern G6DA30 *D_004C267C;
extern f32 D_004F7FD0[];
extern f32 D_004F7FD4[];

void func_0016DA30(s32 a, u16 *p, f32 x, f32 y, f32 z, f32 s) {
    extern void func_003DF490();
    f32 ky, kx, u, w;
    u16 c;
    ky = 24.0f * s;
    D_004C267C = D_004CB100;
    y -= 16.0f;
    x += D_004F7FD0[0];
    y += D_004F7FD4[0];
    D_004C267C->f0 = x;
    D_004C267C->f4 = y;
    D_004C267C->f8 = z;
    D_004C267C->f18 = z;
    D_004C267C->fC = 0x3F800000;
    D_004C267C->f1C = 0x3F800000;
    while ((c = *p) != 0xFFFF) {

        if (c < 0x65 || (c < 0x70 && c >= 0x68) || c >= 0xB0) {
            kx = 22.0f * s;
            u = 0.046875f * (c & 0xF);
            w = (c >= 0x110 && c <= 0x11D) ? 0.046875f * (1.0f + (c >> 4)) : 0.046875f * (c >> 4);
            D_004C267C->f24 = u;
            D_004C267C->f2C = 0.046875f + u;
            D_004C267C->f28 = w;
            D_004C267C->f30 = 0.046875f + w;
        } else {
            kx = 11.0f * s;
            u = 0.046875f * (c & 0xF);
            w = 0.046875f * (c >> 4);
            D_004C267C->f24 = 0.01171875f + u;
            D_004C267C->f2C = (0.046875f + u) - 0.01171875f;
            D_004C267C->f28 = w;
            D_004C267C->f30 = 0.046875f + w;
        }
        D_004C267C->f10 = D_004C267C->f0 + kx;
        D_004C267C->f14 = D_004C267C->f4 + ky;
        D_004C267C->f20 = (c > 0xFF) ? -1 : a;
        func_003DF490(D_004C267C);
        D_004C267C->f0 += kx;
        p++;
    }
}
