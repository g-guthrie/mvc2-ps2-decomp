typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G84;
extern G84 *D_004C2794;
extern u16 *D_004C29AC;

void func_00384C40(u8 *p) {
    extern void func_003859F0(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *q;
    s32 v;
    s8 r;
    if (*D_004C29AC != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_003859F0(p);
        return;
    }
    q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (p[0x1B7] != 0) {
        p[0x1B3] = 0;
        v = *(s8 *)(p + 0x1B2);
        if (v != 0 && ((s8)v & 1) == 0 && p[0x15B] != 0) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x15B] = 0;
        }
    }
    r = func_00175700(p);
    if (r < 0) {
        p[4]++;
        (*(u8 **)(p + 0x18))[7] = 2;
    } else if (*(s8 *)(p + 0x1B3) == 0) {
        func_001E7F60(p);
    }
}

extern s8 D_004C27BC;
extern u8 D_004CA610[];
extern u32 D_004C2618;
extern s32 D_004C2608;

s32 func_0012E1A0(u8 *p) {
    extern s32 func_00418020();
    extern void func_0011D740(s32, s32, s32);
    s32 s;
    s32 v;
    u8 *e;
    u8 a;
    u32 t;
    if (D_004C27BC != 0) return 0;
    a = p[0x11];
    switch (a) {
    case 0:
        if (p[0x12] == p[0x13]) return 0;
        p[0x11] = a + 1;
        e = D_004CA610 + p[0x12] * 12;
        *(s32 *)p = *(s32 *)(e + 4);
        *(s32 *)(p + 4) = *(s32 *)e;
        *(s32 *)(p + 8) = *(s32 *)(e + 8);
        *(s32 *)(p + 0xC) = 0;
    case 1:
        v = 0x3A98 - func_00418020();
        s = (u32)v / D_004C2618;
        D_004C2608 = v;
        if (s <= 0) return 0;
        s = s << 12;
        if (*(s32 *)(p + 8) <= s) {
            s = *(s32 *)(p + 8);
            *(s32 *)(p + 8) = 0;
            p[0x11] = 0;
            t = p[0x14];
            p[0x14] = t - 1;
            t = p[0x12];
            p[0x12] = t + 1;
            t = p[0x12];
            p[0x12] = t & 7;
        } else {
            *(s32 *)(p + 8) = *(s32 *)(p + 8) - s;
        }
        *(s32 *)(p + 0xC) = *(s32 *)(p + 0xC) + s;
        func_0011D740(*(s32 *)p, *(s32 *)(p + 4), s);
        *(s32 *)(p + 4) = *(s32 *)(p + 4) + s;
        *(s32 *)p = *(s32 *)p + s;
        break;
    default:
        return 0;
    }
    return 1;
}

extern s16 D_0044C250[];
extern s16 D_0044C252[];
extern s16 D_0044C254[];

void func_001BD230(u8 *p, u8 *q) {
    extern void func_00175670(u8 *);
    u32 t;
    s16 h;
    if (*(s8 *)(q + 0x151) == 0 || q[0x1E4] != 0x16) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        return;
    }
    func_00175670(p);
    h = *(s16 *)(q + 0x140);
    *(s16 *)(p + 0x140) = h;
    if (h == 0) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * (f32)D_0044C250[*(s8 *)(q + 0x150) * 3];
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 1.6666666269302368f * (f32)D_0044C250[*(s8 *)(q + 0x150) * 3];
    }
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.142857074737549f * (f32)D_0044C252[*(s8 *)(q + 0x150) * 3];
    *(s32 *)(p + 0x48) = D_0044C254[*(s8 *)(q + 0x150) * 3];
    if (*(s8 *)(q + 0x150) >= 2) {
        *(s8 *)(p + 0x24) = 7;
    }
}
