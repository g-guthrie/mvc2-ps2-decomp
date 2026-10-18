typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef signed int s32;
typedef struct { u8 p0[0x1E]; s16 h1E; u8 p1[0x541 - 0x20]; u8 b541; u8 p2[0x5B8 - 0x542]; } E;
extern E D_004F20B0[];
void func_0032E350(s8 a) {
    E *s0 = &D_004F20B0[a];
    extern s32 func_0032DAB0(E *, E *, s32);
    s0->h1E = 0;
    while (s0->h1E < 3) {
        s32 r = func_0032DAB0(s0, &D_004F20B0[a + s0->h1E * 2], 0x200);
        D_004F20B0[a + s0->h1E * 2].b541 = r;
        s0->h1E++;
    }
}
