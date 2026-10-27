typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3[2];
    u8 b5;
    u8 pad6[0x1C - 6];
    s16 h1C;
    u8 pad1E[0x34 - 0x1E];
    f32 f34;
    f32 f38;
    u8 pad3C[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6c;
    u8 pad70[0x140 - 0x70];
    s16 h140;
    u8 pad142[0x150 - 0x142];
    u8 b150;
    u8 pad151[0x15B - 0x151];
    u8 b15B;
    u8 pad15C[0x1B2 - 0x15C];
    s8 b1B2;
    s8 b1B3;
    s8 b1B4;
    u8 b1B5;
    u8 pad1B6[0x1C0 - 0x1B6];
    u16 h1C0;
    u8 pad1C2[0x1D8 - 0x1C2];
    s32 w1D8;
} P3C5DD0;

typedef struct { u8 pad[0x7C]; s16 h7C[1]; } G3C5DD0;
extern G3C5DD0 *D_004C2794;
extern f32 D_004F1FCC[];
extern f32 D_004F1FC8[];

void func_003C5DD0(P3C5DD0 *p, u8 *q)
{
    extern void func_003C5B20();
    extern void func_001E3210();
    extern void func_001757E0();
    extern void func_0018D930();
    extern void func_003C5780();
    extern void func_001E7F60(u8 *);
    extern int func_00175700(u8 *);
    extern void func_003C80A0();
    s32 v;
    s16 h;
    if (p->b5 != 0) {
        func_003C5B20(p, q);
        return;
    }
    if (p->b1B3 != 0) {
        p->b5 = p->b5 + 1;
        func_001E3210(q, 1);
        func_001757E0(p, 0x14, 9);
        func_0018D930(p);
        func_003C5780(p);
        return;
    }
    if (p->b1B4 != 0) {
        s32 t = p->b1B4 - 1;
        p->b1B4 = t;
        func_001E7F60((u8 *)p);
        return;
    }
    func_00175700((u8 *)p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    h = p->h1C;
    if (h != 0 && p->b15B != 0 && p->b1B2 != 0) {
        p->h1C = h - 1;
        p->b1B5 = p->b15B;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7C[p->b2]++;
        p->b150 = 0;
    }
    v = 0;
    if (p->h140 != 0) {
        if (106.666664f + D_004F1FCC[0] <= p->f34) v = 1;
    } else {
        if (!(D_004F1FC8[0] - 106.666664f < p->f34)) v = 1;
    }
    if (v) func_003C80A0(p, q);
    else func_001E7F60((u8 *)p);
}
