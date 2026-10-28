typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[2]; u8 b2; u8 p3; u8 b4; u8 b5; u8 b6; u8 b7; u8 p8[0x1C-8]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PH;

typedef struct { u8 pad[0x54]; f32 f54; } PW;
void func_0036BCB0(PH *p) {
    *(f32 *)((u8 *)p + 0x118) -= 0.07999999821186066f;
    if ((double)(*(f32 *)((u8 *)p + 0x118)) < 0.1) {
        *(u32 *)((s32)p + 0x118) = 0x3DCCCCCD;
    }
    p->f34 += p->f5c;
    p->f5c += p->f68;
    ((PW *)p)->f54 += p->f60;
    p->f60 += p->f6c;
    if ((double)(((PW *)p)->f54) < 0.01) {
        p->b4++;
        ((u8 *)p)[0x13C] = 0;
        *(u32 *)((u8 *)p + 0x54) = 0x3C23D70A;
    }
}
