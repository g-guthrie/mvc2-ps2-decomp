typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[6]; u8 b6; u8 pad7[0x2D]; f32 f34; f32 f38; u8 pad3c[0x20];
    f32 f5C; f32 f60; u8 pad64[4]; f32 f68; f32 f6C; u8 pad70[0xE1];
    s8 b151; s8 b152; u8 pad153[8]; u8 b15B; u8 pad15c[0x3DD]; s8 b539;
} S202;

void func_00202860(S202 *p)
{
    extern void func_00175700(S202 *);
    extern void func_001E3710(S202 *, s32);
    extern s32 func_0018AAC0(S202 *);
    extern s32 func_001864a0(S202 *);
    extern void func_001757E0(S202 *, s32, s32);
    f32 old, nw;
    f32 z = 0.0f;
    u32 t;
    func_00175700(p);
    old = p->f5C;
    p->f34 += old;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    nw = p->f5C;
    if ((nw > z && old < z) || (nw < z && old > z)) {
        p->f5C = 0;
        p->f68 = 0;
    }
    if (p->b15B != 0) {
        p->b15B = 0;
        func_001E3710(p, 0x16);
    }
    if (func_0018AAC0(p) != 0) {
        if (p->b539 == 0) {
            if (p->b151 != 0) {
                p->b151 = 0;
                p->b152 = 1;
            }
        } else {
            if (p->b151 != 0) {
                p->b151 = 0;
                if (p->b152 != 1) p->b152 = p->b152 - 1;
            }
        }
    }
    if (func_001864a0(p) != 0) {
        t = p->b6;
        p->b6 = t + 1;
        func_001757E0(p, 0xF, 3);
    }
}
