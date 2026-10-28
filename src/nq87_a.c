typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 b5;
    u8 pad6[0x16];
    s16 h1C;
    u8 pad1E[0x16];
    f32 f34;
    f32 f38;
    u8 pad3C[0x20];
    f32 f5C;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6C;
    u8 pad70[0x60];
    s8 bD0[2];
    u8 padD2[0xE0];
    s8 b1B2;
    s8 b1B3;
} S_003C0FF0;

extern s16 D_00475C70[];

void func_003C0FF0(S_003C0FF0 *p) {
    extern void func_00175700();
    extern void func_00174910();
    extern void func_001E7F60();
    s8 *q;
    s16 v;
    s8 c;
    q = p->bD0;
    func_00175700(p);
    p->f34 += p->f5C;
    p->f5C += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6C;
    v = p->h1C - 1;
    p->h1C = v;
    if (v == 0) {
        u32 t = p->b4;
        p->b4 = t + 1;
        return;
    }
    c = q[0] - 1;
    q[0] = c;
    if (c == 0) {
        q[0] = 2;
        if (q[1] != 0) {
            q[1]--;
        }
        func_00174910(p, D_00475C70[q[1]]);
    }
    switch (p->b1B3) { default: { u32 t = p->b5; p->b5 = t + 1; p->h1C = 0x10; } break; case 0: func_001E7F60(p); if (p->b1B2 != 0) { u32 t = p->b5; p->b5 = t + 1; p->h1C = 0x10; } break; }
}
