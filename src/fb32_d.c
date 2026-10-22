typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a, b; } H2;
typedef struct { H2 e[5]; } H5;
typedef struct {
    u8 pad0[0x370];
    u8 b370;
    u8 b371;
    u8 pad372[0x4F0 - 0x372];
    H5 h;
    u8 pad504[0x5B8 - 0x504];
} X3D2DC0;

extern H5 D_004F4480;
extern H2 D_004F4494[5];
extern H2 D_004F25B4[5];
extern H2 D_004F2B6C[5];
extern H2 D_004F3124[5];
extern H2 D_004F36DC[5];
extern H2 D_004F3C94[5];
extern H2 D_004F424C[5];
extern s8 D_004F7F3F;
extern s8 D_004F7F35;
extern X3D2DC0 D_004F20B0[];
extern H5 D_004F25A0[0x5B8 / 20 + 1];

#define COPY5(d, s) do { dd_ = (d); ss_ = (s); n_ = 5; do { *dd_++ = *ss_++; } while (--n_ > 0); } while (0)

void func_003D2DC0(void)
{
    extern void func_00128740(void);
    H5 l1;
    H2 l2[5];
    X3D2DC0 *P;
    H2 *dd_;
    H2 *ss_;
    s32 n_;
    s32 c;
    u16 s0;
    s32 k;

    l1 = D_004F4480;
    *(H5 *)D_004F25B4 = *(H5 *)&l1;
    *(H5 *)l2 = *(H5 *)D_004F4494;
    *(H5 *)D_004F2B6C = *(H5 *)l2;
    *(H5 *)D_004F3124 = *(H5 *)&l1;
    *(H5 *)D_004F36DC = *(H5 *)l2;
    *(H5 *)D_004F3C94 = *(H5 *)&l1;
    *(H5 *)D_004F424C = *(H5 *)l2;
    func_00128740();
    c = D_004F7F3F;
    if (c > 0) {
        P = &D_004F20B0[2 - c];
        switch (D_004F7F35) {
        case 0:
            s0 = 0;
            break;
        case 1:
            s0 = 0x1000;
            break;
        case 2:
            P->b370 = 0;
            s0 = 0x2000;
            P->b371 = 0;
            break;
        case 3:
            s0 = 0;
            break;
        }
        P->h.e[0].b = *(u16 *)&P->h.e[0].a;
        P->h.e[0].a = s0;
        P->h.e[1].a = ~P->h.e[0].b & P->h.e[0].a;
        P->h.e[1].b = P->h.e[0].b & ~P->h.e[0].a;
        k = D_004F7F3F;
        *(H5 *)((u8 *)D_004F25A0 + (4 - k) * 0x5B8) = P->h;
        *(H5 *)((u8 *)D_004F25A0 + (6 - k) * 0x5B8) = P->h;
    }
}
