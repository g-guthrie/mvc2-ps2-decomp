typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct G { u8 pad[0x1C]; s32 f1C; } G;
typedef struct H { u8 pad[0x7C]; s16 h7C[1]; } H;
typedef struct P {
    u8 pad0[2]; u8 b2; u8 pad3; u8 b4; u8 pad5[0x1E - 5]; s16 h1E; u8 pad20[3]; u8 b23; u8 b24; u8 pad25[0x50 - 0x25];
    f32 f50; f32 f54; u8 pad58[0x1B0 - 0x58]; u8 b1B0; u8 b1B1; u8 b1B2; u8 pad1B3[2]; u8 b1B5; u8 pad1B6[0x1C0 - 0x1B6];
    u16 h1C0; u8 pad1C2[0x1D8 - 0x1C2]; u32 w1D8;
} P;
extern G *D_004C2840;
extern H *D_004C2794;
extern void func_00175700(P *);
extern void func_001E7F60(P *);

void func_0036E3B0(P *p)
{
    if (D_004C2840->f1C % 14 == 0) {
        if (p->b23 < 4) {
            p->b1B0 = 0x42;
            p->b1B1 = 0x42;
            p->b1B5 = 0x3F;
            p->b1B2 = p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7C[p->b2]++;
        }
    }
    func_00175700(p);
    p->f54 += 0.2f;
    if (!(p->f54 < 1.0f))
        p->b24 = 0xB;
    if (!(p->f54 < 2.0f)) {
        *(u32 *)&p->f54 = 0;
        p->b24 = 0xA;
        p->h1E = p->h1E - 1;
        if (p->h1E == 0) {
            u32 t = p->b4;
            p->b4 = t + 1;
        }
    }
    p->f50 = 1.0f;
    if ((D_004C2840->f1C & 1) == 0)
        p->f50 = 0.8f;
    func_001E7F60(p);
}
