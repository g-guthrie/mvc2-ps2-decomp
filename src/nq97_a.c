typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[0x16];
    s16 h1C;
    u8 pad1E[0x3E];
    f32 f5c;
    u32 u60;
    u8 pad64[4];
    f32 f68;
    u32 u6C;
    u8 pad70[0x140 - 0x70];
    s16 s140;
} HM4CP;

typedef struct {
    u8 pad0[0x1E];
    s16 h1E;
    u8 pad20[0x1E4 - 0x20];
    u8 b1E4;
    u8 pad1E5[0x1FD - 0x1E5];
    u8 b1FD;
} HM4CR;

typedef struct {
    u8 pad0[0xE];
    u8 bE;
    u8 pad0F;
    s16 h10;
} HM4CA;

void func_00370D40(u8 *pp) {
    HM4CP *p = (HM4CP *)pp;
    HM4CR *r = *(HM4CR **)((s32)pp + 0x18);
    HM4CA *a = (HM4CA *)((u8 *)r + 0x2B8);
    if (r->h1E == 0) {
        p->b5 = 5;
        { f32 k; switch (p->s140) { default: k = -15.833333015441895f; break; case 0: k = 15.833333015441895f; break; } p->f5c = k; }
        { f32 k; switch (p->s140) { default: k = -0.3125f; break; case 0: k = 0.3125f; break; } p->f68 = k; }
        p->u60 = 0;
        p->u6C = 0;
        p->h1C = 0x3C;
        return;
    }
    if (r->b1E4 != 0x1D || r->b1FD != 5) {
        p->b5 = 5;
        { f32 k; switch (p->s140) { default: k = -15.833333015441895f; break; case 0: k = 15.833333015441895f; break; } p->f5c = k; }
        { f32 k; switch (p->s140) { default: k = -0.3125f; break; case 0: k = 0.3125f; break; } p->f68 = k; }
        p->u60 = 0;
        p->u6C = 0;
        p->h1C = 0x3C;
        a->bE = 0;
    } else {
        s16 t = p->h1C;
        p->h1C = t - 1;
        if (t != 0) return;
        { u32 b = p->b5; p->b5 = b + 1; }
        p->h1C = 0x78;
        p->h1C += a->h10 * 2;
    }
}
