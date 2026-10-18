typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F20B0[];
extern u16 D_004C1C88[2];
extern void func_001757E0();
extern s32 func_00189310();
extern void func_0011D8F8();
extern void func_00186A60();
extern u8 D_00458AD0[];

void func_0012F060(s32 i) {
    u8 *p = D_004F20B0 + i * 0x5B8;
    if (i < 6) do {
        p[0x570] = i;
        i += 2;
        p += 0xB70;
    } while (i < 6);
}

s32 func_002ABF80(u8 *p) {
    if (func_00189310(p, D_00458AD0, p + 0x3C0) == 0) return 0;
    if (**(s8 **)(p + 0x420) < 3) return 0;
    func_0011D8F8(p + 0x380, 0, 8);
    func_0011D8F8(p + 0x390, 0, 8);
    func_0011D8F8(p + 0x398, 0, 8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0x14;
    func_00186A60(p, 0x1D);
    return 1;
}

extern void func_0039E450();

typedef struct O {
    u8 pad0[0x34];
    f32 f34;
    u8 pad1[0x152 - 0x38];
    u8 b152;
    u8 pad2[0x15B - 0x153];
    u8 b15b;
} O;

typedef struct P {
    u8 pad0[0x18];
    O *o;
    u8 pad1[0x34 - 0x1C];
    f32 f34;
    u8 pad2[0x9C - 0x38];
    u32 w9c;
} P;

void func_0039E2D0(P *p) {
    O *q;
    u8 b;
    p->f34 = p->o->f34;
    p->f34 += 1.66666662693f * (f32)p->w9c / 65536.0f;
    q = p->o;
    b = q->b15b;
    if (b != 0) {
        if ((s8)b < 0) {
            func_0039E450(p);
        } else {
            q->b152 = 8;
            p->o->b15b = 0;
        }
    }
}
