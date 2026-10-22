typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3F;

typedef struct { V3F a; V3F b; } EntF;
typedef struct {
    u8 p0[0x10];
    void *f10;
    u32 f14;
    u32 f18;
    s16 h1C;
    u8 p1E[2];
    u8 b20;
    u8 b21;
    u8 b22;
    u8 p23[0x11];
    V3F v34;
    u32 w40;
    u32 w44;
    u8 p48[8];
    u32 w50;
    u32 w54;
    u32 w58;
    u8 p5C[0x18];
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u32 w84;
    u8 p88[0x40];
    u8 *pC8;
    s16 hCC;
    u8 pCE[2];
    u32 wD0;
    u8 pD4[0x13C-0xD4];
    u8 b13C;
} OF;

extern EntF D_00440370[][3];
extern u32 D_004C2830;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0013BA40();
extern void func_0013BB80();

void func_0013B7D0(u8 *p) {
    u8 i;
    u8 *o;
    OF *oo;
    for (i = 0; i < 6; i++) {
        o = func_003DA750(0, 6, 1);
        if (o == 0) return;
        oo = (OF *)o;
        oo->b13C = 0;
        oo->f10 = (void *)func_0013BA40;
        oo->f18 = *(u32 *)(p + 0x18);
        oo->pC8 = p + 0x88;
        oo->f14 = *(u32 *)(p + 0x14);
        oo->b20 = p[0x20];
        oo->b21 = p[0x21];
        oo->b22 = i;
        oo->v34 = D_00440370[oo->b20][oo->b21].a;
        oo->w40 = 0xE001;
        oo->w44 = 0;
        oo->h1C = oo->b22 * 3 + 10;
        oo->wD0 = 0xC27;
        oo->f74 = 1.0f;
        switch (i) {
        case 4:
            oo->hCC = oo->b21 + 0x74;
            oo->w84 = D_004C2830;
            break;
        case 5:
            oo->f10 = (void *)func_0013BB80;
            oo->hCC = 0x77;
            oo->w84 = D_004C2830;
            oo->v34 = D_00440370[oo->b20][oo->b21].b;
            oo->w40 = 0;
            if (oo->b20 != 0) oo->w44 = 0x8000;
            oo->w50 = 0;
            oo->w54 = 0;
            oo->w58 = 0;
            oo->wD0 |= 0x10;
            break;
        default:
            oo->hCC = i + 0x70;
            oo->w84 = D_004C2830;
            break;
        }
        switch (oo->b21) {
        case 0:
            oo->f78 = 1.0f;
            oo->f7C = 0.5f;
            oo->f80 = 1.0f;
            break;
        case 1:
            oo->f78 = 0.0f;
            oo->f7C = 1.0f;
            oo->f80 = 0.0f;
            break;
        case 2:
            oo->f78 = 0.2f;
            oo->f7C = 0.82f;
            oo->f80 = 1.0f;
            break;
        }
    }
}
