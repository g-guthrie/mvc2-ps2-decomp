/* gr9: MW 3.0.3 -O3 -Op -sdatathreshold 8 (also exact on 3.0) */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1F4C[];
extern u8 D_004D18E8[];
extern u8 D_004D18E5[];
extern u8 *D_004C2840;

typedef struct { u8 pad0[0x1C]; s16 h1C; u8 pad1[0x16]; f32 f34; f32 f38; f32 f3C; } Pb;

void func_00160710(Pb *p)
{
    extern void func_00160B80(Pb *);
    extern void func_003DAA40(void);
    extern void func_001E4340(s32);
    s32 h;
    s16 k;
    p->f34 = D_004F1F4C[0];
    h = p->h1C;
    switch (h) { default: {
        k = h;
        if (k < 0xB) {
            p->h1C = h + 1;
            func_00160B80(p);
            return;
        } else if (k < 0x24) {
            p->f3C += 200.0f;
            p->h1C += 1;
            func_00160B80(p);
        } else if (k < 0x3D) {
            p->f3C += 400.0f;
            p->h1C += 1;
            func_00160B80(p);
        } else if (k < 0x56) {
            p->f3C += 800.0f;
            p->h1C += 1;
            func_00160B80(p);
        } else if (k < 0x6F) {
            p->f3C += 1200.0f;
            p->h1C += 1;
            func_00160B80(p);
        } else if (k < 0x88) {
            p->f3C += 1600.0f;
            p->h1C += 1;
            func_00160B80(p);
        } else if (k < 0xA1) {
            p->f3C += 2000.0f;
            p->h1C += 1;
            func_00160B80(p);
        } else if (k < 0xBA) {
            p->f3C += 1000.0f;
            p->h1C += 1;
            func_00160B80(p);
        } else {
            func_003DAA40();
            if (D_004D18E8[0] == 8 && *(s8 *)(D_004C2840 + 0x8F) == 0) {
                if (D_004D18E5[0] == 2) {
                    func_001E4340(0x3C);
                }
            } else {
                func_001E4340(0x3C);
            }
            return;
        }
    } break; case 0:
        func_00160B80(p);
        p->h1C += 1;
        break;
    }
}
