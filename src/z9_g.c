typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;

typedef struct {
    u8 p0[2]; u8 b2; u8 pad3; u8 b4; u8 pad5[0x1C - 5]; s16 s1c; u8 pad1e[0x38 - 0x1E];
    f32 f38; u8 pad3c[0x60 - 0x3C];
    f32 f60; u8 pad64[0x6C - 0x64]; f32 f6c;
    u8 pad70[0x1B2 - 0x70]; u8 b1b2; u8 pad1b3[2]; u8 b1b5; u8 pad1b6[0x1C0 - 0x1B6];
    u16 h1c0; u8 pad1c2[0x1D8 - 0x1C2]; u32 w1d8;
} A1;

void func_00360410(A1 *p) {
    extern void func_00175700();
    extern void func_001E7F60();
    s16 v;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700();
    func_001E7F60(p);
    if ((p->s1c & 7) == 0) {
        p->b1b5 = 0x3C;
        p->b1b2 = p->h1c0 = 0;
        p->w1d8 = 0;
        D_004C2794->f7c[p->b2]++;
    }
    if (p->s1c == 8) {
        p->b1b5 = 0x3D;
        p->b1b2 = p->h1c0 = 0;
        p->w1d8 = 0;
        D_004C2794->f7c[p->b2]++;
    }
    v = p->s1c;
    p->s1c = v - 1;
    if (v == 0) p->b4++;
}
