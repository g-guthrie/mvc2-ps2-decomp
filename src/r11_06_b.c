/* r4_11: 19/38 register naming; named-local, table-local, K&R, s32 return, extern-order tried */
/* MW 3.0/3.0.3 -O3 -sdatathreshold 8: 19/38 words, pure register naming (retail temp v0, bases a1/v1) */
/* 3.0.3/3.0 -O3 -sdatathreshold 8 (needs D_004B3BB0, D_004B3B70, func_0015AF90 in symbol_addrs): 19/38 words, pure register naming (temp a1 vs retail v0; bases v1/v0 vs a1/v1) */
/* nearmiss func_0015AEF0: try.sh/try30.sh -O3 -sdatathreshold 8; right size, regs differ (retail lh v0; bases a1/v1; ours a1; v1/v0) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[4]; u8 b4; u8 pad5[0x17]; s16 s1C; s16 s1E; u8 pad20[0x54]; f32 f74; u8 pad78[0xC]; s32 w84; u8 pad88[0x44]; s16 sCC; u8 padCE[6]; s32 wD4; } B5A;
extern s16 D_004BF44C;
extern s32 D_004C2838;
extern s16 D_004B3BB0[];
extern f32 D_004B3B70[];

void func_0015AEF0(B5A *p)
{
    extern void func_0015AF90(B5A *);
    u32 t;
    f32 *b;
    s16 *a;
    if (p->wD4 != 0) {
        p->wD4 = p->wD4 - 1;
        return;
    }
    if (p->s1C != 0) {
        a = D_004B3BB0; b = D_004B3B70;
        p->sCC = D_004BF44C;
        p->w84 = D_004C2838;
        a += p->s1C - 1;
        p->s1E = *a;
        b += p->s1C - 1;
        p->f74 = *b;
    }
    t = p->b4;
    p->b4 = t + 1;
    func_0015AF90(p);
}
