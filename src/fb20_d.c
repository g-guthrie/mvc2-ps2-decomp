typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 x[32][4]; } T128;
typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 p0[0x34];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 p1[0x20];
    f32 f60;
} W;
typedef struct {
    u8 p0[7];
    u8 b7;
    u8 p1[0x1A];
    u8 b22;
    u8 p2[0x11];
    f32 f34;
    f32 f38;
    u8 p3[0x176];
    s8 b1B2;
    u8 p4[0x6D];
    W *w220;
    u8 p5[0x20C];
    f32 f430;
} A;
typedef struct { u8 p0[0xE]; s8 bE; } B;

extern T128 D_004595B0;

void func_002BCF40(A *a, B *b) {
    extern f32 func_00117078(f32);
    extern s32 func_00174170(void);
    extern s32 func_001748C0(f32 *, V3 *);
    extern void func_002BD190(A *, B *);
    T128 tab;
    V3 v;
    tab = D_004595B0;
    b->bE = a->b22;
    if (a->b1B2 != 0) {
        f32 d1, d2;
        if (171.42855834960938f + a->f430 < a->w220->f38) {
            d1 = func_00117078(a->w220->f34 - a->f34);
            d2 = func_00117078(a->w220->f38 - a->f38);
            if (d1 <= 346.6666564941406f) {
                if (d2 <= 274.28570556640625f) {
                    if (!(a->w220->f60 < 0.0f)) {
                        a->b22 = tab.x[a->b22][a->b7 - 1];
                        a->b22 += (func_00174170() & 3) - 1;
                        a->b22 &= 0x1F;
                        func_002BD190(a, b);
                        return;
                    }
                }
            }
        }
    }
    v = *(V3 *)&a->w220->f34;
    if (a->w220->f60 < 0.0f) {
        v.y -= 102.85713958740234f;
    }
    a->b22 = func_001748C0(&a->f34, &v);
    {
        s32 x = a->b22;
        s32 r = x % 8;
        s32 c = (r < 4) ? 0 : 1;
        a->b22 = x / 8 + c;
    }
    if (a->b22 == b->bE) {
        a->b22 += 0x10;
    }
    a->b22 &= 0x1F;
    func_002BD190(a, b);
}
