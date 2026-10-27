typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004502C0[];
s32 func_002034A0(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    if (func_00189310(p, D_004502C0, p + 0x380) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x380);
    p[0x1B7] += (u8)(*(s8 *)(p + 0x212) * 2);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

typedef struct { u8 pad[0x4C]; s8 f4c; } G40;
extern G40 *D_004C2840;
extern u8 D_004C27D0;
extern s8 D_004C2758;
extern s8 D_004C2754;
extern s8 D_00583BDE[];
extern u8 D_0045E370[];
void func_0032E520(void) {
    extern void func_0032E410(void);
    extern s32 func_00417A40(void);
    s32 k = D_004C2840->f4c;
    if (k == 1) {
    } else if (k == 2) {
        D_004C27D0 = 0xB;
    } else if (k == 5) {
        D_004C27D0 = (D_004C2758 + D_004C2754) & 7;
    } else {
        func_0032E410();
        k = D_004C2840->f4c;
        if (k == 0 || k == 7) {
            if (D_00583BDE[0] != 0) {
                if ((func_00417A40() & 1) != 0) {
                    s32 x = D_004C27D0;
                    if (x <= (s8)(D_00583BDE[0] - 1)) D_004C27D0 = D_0045E370[(u8)x];
                }
            }
        }
    }
}

extern s8 D_004F7FC8[];
s32 func_00189790(u8 *p, u8 *q, u8 *r) {
    extern s32 func_00189830(u8 *, u8 *, u8 *);
    u32 h;
    if ((*(u16 *)(p + 0x35E) & (h = *(u16 *)(q + 8))) != 0) return 0;
    if (h != 0x1000 && h != 0x2000 && r[2] != p[0x1E6]) {
        return (u8)(r[0] = 0);
    }
    {
        u32 t = r[0];
        r[0] = t + 1;
    }
    r[1] = D_004F7FC8[p[2]] * 10 + 0xF;
    return func_00189830(p, q, r);
}
