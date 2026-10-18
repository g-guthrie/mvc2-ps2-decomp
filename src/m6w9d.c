typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


extern s8 D_00460DC0[];
extern V3 D_00460D90[];
extern s32 D_004C283C[1];
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00344A30();
void func_00344990(s32 idx) {
    u8 *o = func_003DA750(0, 0x5B, 0);
    if (o != 0) {
        V3 *e;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00344A30;
        *(s16 *)(o + 0xCC) = D_00460DC0[0] + 0x40;
        *(s32 *)(o + 0x84) = D_004C283C[0];
        *(u32 *)(o + 0xD0) = 0x800981;
        e = &D_00460D90[idx];
        *(V3 *)(o + 0x34) = *e;
    }
}

extern u16 *D_004C2718;
extern u8 D_004BFA74[8];
extern void func_001CF720();
extern void func_001754A0(void *, s32, s32);
extern void func_001CF780(void *);
extern void func_001CF6A0(void *);
void func_001CF3A0(u8 *p) {
    p[0x13C] = 1;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*D_004C2718 == *(u16 *)(*(u8 **)(p + 0x18) + 0x168) && *(s8 *)(*(u8 **)(p + 0x18) + 0x161) != 0) {
        func_001CF720(p);
        func_001754A0(p, 0x1B, D_004BFA74[*(s8 *)(*(u8 **)(p + 0x18) + 0x161)]);
    } else {
        func_001CF780(p);
        func_001CF6A0(p);
    }
}

typedef struct { f32 a, b; } P2;
extern P2 D_004B3BD0[];
extern s32 D_004C2838[1];
extern s32 func_00153AA0();
extern void func_00170DA0(s32, s32, s32, s16);
void func_0015E2F0(u8 *p) {
    P2 *e = D_004B3BD0;
    e += *(s16 *)(p + 0x1C);
    if (*(s32 *)(p + 0xDC) != 0) {
        s32 r = func_00153AA0();
        func_00170DA0(D_004C2838[0], 0x66, r, *(s16 *)(p + 0xCC));
    } else {
        s32 r = func_00153AA0();
        func_00170DA0(D_004C2838[0], 0x67, r, *(s16 *)(p + 0xCC));
    }
    {
        f32 y = e->b;
        f32 x = e->a;
        *(f32 *)(p + 0xE0) = x;
        *(f32 *)(p + 0xE4) = y;
    }
    *(u32 *)(p + 0xD0) |= 0x20000;
}

extern s32 func_00175700(void *);
typedef struct { u8 pad[0x74]; s8 tab[2]; s8 x76; } G;
extern G *D_004C2794;
extern void func_00183210(void *, void *, s32);
void func_00252790(u8 *p) {
    u32 v[4];
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        t += 1;
        p[6] = t;
        p[0x151] = 0;
        v[0] = 0xC1855555;
        v[1] = 0x42EBB6DB;
        v[2] = 0;
        func_00183210(p, v, 1);
        p[0x33B] = D_004C2794->tab[p[2]];
        D_004C2794->x76 = D_004C2794->tab[p[2]] | (p[2] << 4);
        p[0x33C] = 0x10;
    }
}
