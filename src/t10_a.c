typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();
extern void func_001757E0();
extern s32 func_00185980();
extern void func_00185640();
extern void func_00178F20();
extern void func_00179160();
extern void func_001E7F60();
extern u8 *func_003DA750();
extern void func_00396E30();
extern u8 *D_004C2794;
extern u8 D_004CAB79;
typedef struct { u8 a; u8 pad; u16 b; u32 c; } E8;
extern E8 D_004CA670[];
extern u8 D_004521D0[];
extern u8 D_0045A8C0[];
extern s32 func_00189310(void *p, void *q, void *r);
extern void func_0018A990();
extern void func_00186A60(void *p, s32 a);
extern void func_0039E450(void);
extern void func_001830D0(void *p, void *v, s32 a, s32 b);
extern u8 D_004D3170[];
extern s8 D_004C2798[2];

s32 func_0012DE70(u8 *p) {
    switch (D_004CAB79) {
    case 0: {
        E8 *e;
        u32 t;
        if (p[0xA] == p[0xB]) return 0;
        t = p[9];
        p[9] = t + 1;
        e = &D_004CA670[p[0xA]];
        p[8] = e->a;
        *(u32 *)p = e->b;
        *(u32 *)(p + 4) = e->c;
    }
    case 1:
        p[9] = 2;
        break;
    case 2: {
        u32 t, u, w;
        p[9] = 0;
        t = p[0xC];
        p[0xC] = t - 1;
        u = p[0xA];
        p[0xA] = u + 1;
        w = p[0xA];
        p[0xA] = w & 0xF;
    }
    }
    return 1;
}

s32 func_002337E0(u8 *p) {
    if (func_00189310(p, D_004521D0, p + 0x3A8) == 0) return 0;
    else {
    if (**(s8 **)(p + 0x420) == 0) return 0;
    else {
    if (p[0x20D] == 2) return 0;
    func_0018A990(p, p + 0x3A8);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 5;
    func_00186A60(p, 0x1D);
    return 1;
    }}
}

s32 func_002D97A0(u8 *p) {
    if (func_00189310(p, D_0045A8C0, p + 0x380) == 0) return 0;
    else {
    if (**(s8 **)(p + 0x420) == 0) return 0;
    else {
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s8 v = p[0x1E8];
            if (v != 0) return 0;
            p[0x1E8] = v + 1;
        }
    }
    func_0018A990(p, p + 0x380);
    p[0x26C] = 1;
    return 1;
    }}
}

