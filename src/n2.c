typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700();
extern s32 func_00175670();
extern int func_00174470(const void *);
extern s32 func_001AFC90();
extern void func_00186A60();
extern void func_001757E0();
extern void func_0014A700(f32, u16, s32, void *, s32, f32, f32, f32);
extern volatile u16 D_004F7F92;
extern u8 D_00443E78[];
extern void *func_003DA750();
extern void func_003802E0();
extern s32 func_00189310();
extern u8 D_00454120[];
extern s32 func_00191210();
extern void (*D_004543F0[])();
struct PS2IconFile;
extern struct PS2IconFile D_00465260;
extern s32 D_00471978[];
extern s32 func_0019B710();
extern void func_0019B740();
extern void func_00183d50();
extern void func_003C80C0();
extern u16 *D_004C26F8;
extern void func_001BAE90();
extern u8 *D_004C2840;
extern u8 D_00448EE0[];
extern void func_0018A990();
extern void func_0011D8F8();
typedef struct { u8 pad[0x24A]; s8 f; } S24A;
extern void func_00376AE0();
extern u8 *D_004C2818;
extern void func_00140F30();
extern void func_00170DF0();
typedef struct { f32 x, y, z; } V3;
extern u8 D_0044F260[];
extern void func_00168E80();
extern void func_001695A0();
extern s32 func_00169850();
extern void func_001EB470();
extern void func_00183920();
extern void func_001E3710();
extern f32 D_004B3380[];
extern void func_0016EDA0();
extern void func_0018F8C0();
extern void func_002A70B0();
extern void func_00175910();
extern void (*D_0044BDE0[])(u8 *);

s32 func_001AED10(u8 *p) {
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    if ((s8)func_00175670(p) < 0) return func_001AFC90(p);
}

void func_0026ED60(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
    case 2:
        p[0x1FD] = 1;
        break;
    case 1:
        p[0x1FD] = 2;
        break;
    }
    p[0x1B7] = 1;
    func_00186A60(p, 0x15);
}

void func_00231130(u8 *p, u8 *q) {
    u32 t = p[7];
    p[7] = t + 1;
    *(s16 *)(p + 0x140) ^= 1;
    *(s8 *)(p + 0x1E6) ^= 1;
    if (*(s16 *)(p + 0x140)) *(u32 *)(p + 0x5C) = 0xC1200000;
    else *(u32 *)(p + 0x5C) = 0x41200000;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    (*(u8 **)(q + 4))[0x24A] = 0;
    func_001757E0(p, 0x16, 4);
}

void func_00380270(u8 *a, s32 b, s32 c) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_003802E0;
        *(u8 **)(r + 0x18) = a;
        r[0x20] = b;
        r[0x23] = c;
    }
}

s32 func_0038D290(s32 a, s32 b) {
    switch (a) {
    case 0: return 0;
    case 1: return (s32)&D_00465260;
    case 2: return 0;
    case 3: return 0;
    case 4: return D_00471978[b];
    }
    return 0;
}

void func_00257910(u8 *p) {
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x20D] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183d50(p);
        func_001757E0(p, 0x14, 0x15);
    } else {
        func_00175700(p);
    }
}

void func_001EB6A0(u8 *p) {
    if (*(s8 *)(p + 0x151) < 0) {
        s16 v;
        p[0x151] = 0;
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            u32 t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x15, 5);
            return;
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_001EB470(p);
}

void func_0038FE00(u8 *p) {
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u32 *)(p + 0x5C) = 0xC0A00000;
        *(u32 *)(p + 0x68) = 0x3D555555;
        *(u32 *)(p + 0x60) = 0x404DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF092492;
        if (*(s16 *)(p + 0x140)) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
    func_00175700(p);
}

void func_0019B350(u8 *p) {
    if (p[5] == 0) {
        if (!func_0019B710(p, 9)) {
            if (!func_0019B710(p, 0x15)) { func_0019B740(p); return; }
        }
    }
    if ((s8)func_00175670(p) < 0) func_0019B740(p);
}

void func_00269270(u8 *p) {
    p[0x33C] = 5;
    if (p[6] != 0 && p[6] != 8) {
        p[0x216] |= 0x80;
        p[0x1FF] = 2;
        func_00191210(p);
    }
    D_004543F0[p[6]](p, (u8 *)((u32)p + 0x2B8));
}

void func_00318EC0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = p[0x269] == 6 ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x150)) {
        u32 t;
        p[0x150] = 0;
        func_003C80C0(p, 0, 1);
        t = p[6];
        p[6] = t + 1;
        p[0x2B8] = 0x10;
    }
}

void func_00242640(u8 *p) {
    f32 v[4];
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    {
        s8 a = p[0x151];
        if (a & 1) {
            *(s8 *)(p + 0x151) = a ^ 1;
            *(u32 *)&v[0] = 0xC1BAAAAA;
            *(u32 *)&v[1] = 0x432B6DB6;
            func_00183920(p, v);
        }
    }
    {
        s8 a = p[0x151];
        if (a & 2) {
            *(s8 *)(p + 0x151) = a ^ 2;
            func_001E3710(p, 0x16);
        }
    }
}

u8 *func_00376A50(u8 *p, s32 b) {
    s8 *q = (s8 *)(p + 0x2B8);
    u8 *r;
    if (*q >= 2) return 0;
    r = func_003DA750(0, 1, 1);
    if (r) {
        *(s16 *)(r + 0x26) = 0x1501;
        *(void **)(r + 0x10) = func_00376AE0;
        *(u8 **)(r + 0x18) = p;
        r[1] = p[1];
        r[0x20] = b;
        *q = *q + 1;
    }
    return r;
}

void func_002A7040(u8 *p) {
    func_002A70B0(p);
    if ((s8)func_00175700(p) < 0) {
        func_00186A60(p, 2);
        p[6] = 1;
        p[0x20D] = 2;
        *(s16 *)(p + 0x140) = p[0x1E6];
        func_00175910(p, 1, 1, 3);
    }
}

void func_001B5690(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
    } else if (q[0x1E4] != 0x1D) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        D_0044BDE0[p[6]](p);
    }
}

void func_001B4AD0(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175670(p);
    if (!func_00174470(p)) { p[4] = 2; return; }
}

void func_00144CB0(u8 *p) {
    f32 *b = D_004B3380 + 3;
    *(f32 *)(p + 0x34) = D_004B3380[0] + (f32)*(s16 *)(p + 0x1C) * (b[0] - D_004B3380[0]) / 30.0f;
    *(f32 *)(p + 0x38) = D_004B3380[1] + (f32)*(s16 *)(p + 0x1C) * (b[1] - D_004B3380[1]) / 30.0f;
    *(f32 *)(p + 0x3C) = D_004B3380[2] + (f32)*(s16 *)(p + 0x1C) * (b[2] - D_004B3380[2]) / 30.0f;
}

s32 func_001698C0(u8 *p) {
    if (p[0x496] == 0) {
        u8 *q = *(u8 **)(p + 0x220);
        if (q[5] == 0) {
            if (q[0x1E4] < 2) {
                func_00168E80(p);
                func_001695A0(p);
                return 1;
            }
            if (p[0x1E4] >= 5 && p[0x1E4] < 10) {
                func_00168E80(p);
                func_001695A0(p);
                return 1;
            }
        }
    }
    return func_00169850(p);
}
