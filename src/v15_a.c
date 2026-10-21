typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u16 D_004F4484;
extern u16 D_004F4498;
extern u32 D_004636B0[];

void func_003C33B0(u8 *p, u8 *q) {
    extern void func_001E7F60();
    extern void func_001757E0();
    if (*(s16 *)(p + 0x1C) == 0) {
        { u32 t = p[4]; p[4] = t + 1; }
    } else {
        func_001E7F60();
        if (*(s8 *)(p + 0x1B2) != 0) {
            { u32 t = p[5]; p[5] = t + 1; }
            p[0x13C] = 1;
            p[0x13C] = 0;
            func_001757E0(p, 0x16, 6);
        }
    }
}

void func_00363900(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (q[4] >= 2) {
        u32 t = p[4]; p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            u32 t = p[4]; p[4] = t + 1;
            p[0x13C] = 0;
        } else {
            ((void (*)(u8 *, u8 *))D_004636B0[p[0x20]])(p, q);
        }
    }
}

typedef float f32;
extern f32 D_004CD178[];
extern f32 D_004CD17C[];
extern s8 D_004F7FC8[];
extern u8 D_00457CA0[];

void func_001E43F0(u16 idx, u32 n) {
    f32 z = 0.0f;
    f32 d = n;
    f32 v = D_004CD17C[idx * 5] / d;
    f32 r;
    if (v != z) r = -v; else r = -1.0f;
    D_004CD178[idx * 5] = r;
}

typedef struct { u8 pad0[2]; u8 b2; u8 pad1[0x1E6 - 3]; u8 b1e6; u8 pad2[0x35E - 0x1E7]; u16 m; } P89;
typedef struct { u8 pad[8]; u16 f; } Q89;

void func_002A8BF0(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    extern void func_00183D90();
    if ((s8)func_00175700() < 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151) != 0) {
        func_00183D90(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}

typedef struct { f32 x, y, z; } V3_15;
extern u8 D_0045BA30[];

void func_001F48A0(u8 *p) {
    extern s32 func_00175700();
    f32 z = 0.0f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x60) < z) {
        u32 t = p[7]; p[7] = t + 1;
        *(u32 *)(p + 0x68) = 0x40F00000;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
}

void func_0017E4B0(u8 *p) {
    extern void func_00190D50();
    extern void func_0018F730();
    extern void func_00186CE0();
    *(u32 *)(p + 0x1D0) = (u32)(*(u8 **)(*(u8 **)(p + 0x1DC) + 0x184)) + (p[0x1B5] & 0x7F) * 28;
    func_00190D50(p, *(u8 **)(p + 0x1DC));
    func_0018F730(p);
    *(u16 *)(p + 0x140) = p[0x1E6];
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(s16 *)(p + 0x1FA) = 0x30;
    p[0x209] = 0x30;
    p[0x1F7] = 0x64;
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V3_15 *)(p + 0x50) = *(V3_15 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_00186CE0(p, 0x17);
}

void func_0019AD20(u8 *p, u8 *q) {
    extern void func_00175670();
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        u32 t = p[5]; p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBF092492;
    }
}

void func_00251E60(u8 *p) {
    extern s32 func_00175700();
    extern void func_001AD170();
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        { u32 t = p[6]; p[6] = t + 1; }
        p[0x151] = 0;
        p[0x20D] = 2;
        *(f32 *)(p + 0x5C) = (p[0x1E6] != 0) ? -10.0f : 10.0f;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x411A4924;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001AD170(p, 0xE, 0);
    }
}

extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_002A5280(u8 *p, u8 *q) {
    extern s32 func_00175700();
    extern void func_001E3210();
    extern void func_001757E0();
    s32 k;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700();
    k = *(s8 *)(q + 8);
    switch (k) {
    case 0:
        break;
    case 1: {
        u32 t = p[7]; p[7] = t + 2;
        *(s16 *)(p + 0x1C) = 0x17;
        func_001757E0(p, 0x16, 5);
        break;
    }
    case 2:
        func_001E3210(p, 0x17);
    default: {
        u32 t = p[7]; p[7] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        break;
    }
    }
}

void func_00177B90(u8 *p) {
    extern s32 func_00175700();
    extern s32 func_001864A0();
    extern void func_00177D50();
    f32 z = 0.0f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x13C) == 0) {
        u32 t = p[6]; p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x1E;
    } else {
        func_00175700();
        if (*(f32 *)(p + 0x60) <= z) {
            if (func_001864A0(p) != 0) func_00177D50(p);
        }
    }
}

void func_00266F80(u8 *p) {
    extern s32 func_00267B00();
    extern s32 func_00267E40();
    extern s32 func_00267D70(u8 *, s32);
    extern void func_00267E20();
    extern s32 func_00175700();
    extern void func_001E3710();
    if (func_00267B00(p) != 0) return;
    if (func_00267E40(p) != 0) return;
    if (func_00267D70(p, 0) == 0) func_00267E20(p);
    func_00175700(p);
    {
        s32 c = *(s8 *)(p + 0x151);
        if (c == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        } else if ((s8)c == 1) {
            p[0x151] = 2;
            D_004F1F45 = 1;
            D_004F1F46 = 1;
            func_001E3710(p, 0x35);
        }
    }
}

void func_0023D8B0(u8 *p, u8 *q) {
    extern s32 func_00175700();
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700();
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        { u32 t = p[6]; p[6] = t + 1; }
        p[0x20D] = 2;
        if (p[0x1E6] == 0) {
            *(u32 *)(p + 0x5C) = 0xC0D55555;
            *(u32 *)(p + 0x68) = 0x3E200000;
        } else {
            *(u32 *)(p + 0x5C) = 0x40D55555;
            *(u32 *)(p + 0x68) = 0xBE200000;
        }
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0x3F892492;
        q[2] = 0x46;
        *(s16 *)(p + 0x1C) = 0x18;
        *(s16 *)(p + 0x1E) = 3;
    }
}

void func_002AEC70(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    extern void func_00183D50();
    u32 *a3, *t0, *t1, *t2;
    func_00175700(p);
    a3 = (u32 *)(p + 0x5C); t1 = (u32 *)(p + 0x68); t0 = (u32 *)(p + 0x60); t2 = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6]; p[6] = t + 1;
        *a3 = 0; *t0 = 0; *t1 = 0; *t2 = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        func_001757E0(p, 0x15, 5);
        func_00183D50(p);
    }
}

void func_0023BAE0(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    extern void func_001A31D0();
    u32 *v1, *a1;
    func_00175700(p);
    v1 = (u32 *)(p + 0x60); a1 = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *v1 = 0;
        *a1 = 0;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        p[0x169] = 0x12;
        p[0x168] = 1;
        func_001757E0(p, p[0x169], p[0x168]);
        func_001A31D0(p, 2, 0);
        func_001A31D0(p, 2, 1);
        { u32 t = p[6]; p[6] = t + 1; }
    }
}

void func_001C9A20(u8 *p) {
    extern void func_001754A0();
    u8 *q = *(u8 **)(p + 0x18);
    s16 h;
    p[0x22] = 0xB;
    *(s16 *)(p + 0x1C) = 0x18;
    *(s16 *)(p + 0x1E) = 0x10;
    p[0x31] = 0x12;
    *(u32 *)(p + 0x48) = 0x8000;
    *(u32 *)(p + 0x34) = 0x43610000;
    *(u32 *)(p + 0x38) = 0x44326492;
    *(u32 *)(p + 0x5C) = 0xC0555555;
    *(u32 *)(p + 0x68) = 0xBBD55555;
    *(u32 *)(p + 0x60) = 0xC14DB6DB;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    h = *(s16 *)(q + 0x140);
    *(s16 *)(p + 0x140) = h;
    if (h != 0) {
        *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(q + 0x38);
    func_001754A0(p, 0x1B, 0x2B);
}

extern u8 D_004F20B0[];
extern u8 D_004F2668[];
extern u8 D_004F20B5[];
extern u8 D_004F20B6[];
extern u8 D_004F20B7[];
extern u8 D_004F266D[];
extern u8 D_004F266E[];
extern u8 D_004F266F[];
extern u8 *D_004C2840;
typedef struct { u8 p0[3]; u8 f3; u8 pad[0x88-4]; s8 f88; s8 f89; u8 pad2[0x91-0x8A]; u8 f91; u8 f92; } G32;
extern s32 D_004C2928;

void func_00253AF0(u8 *p) {
    extern s32 func_00175700();
    extern void func_00178F20();
    extern void func_001757E0();
    u8 *q;
    func_00175700(p);
    q = *(u8 **)(p + 0x1DC);
    if (*(s8 *)(q + 0x211) != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    } else {
        *(f32 *)(q + 0x34) += *(f32 *)(q + 0x5C);
        *(f32 *)(*(u8 **)(p + 0x1DC) + 0x5C) += *(f32 *)(*(u8 **)(p + 0x1DC) + 0x68);
    }
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[6]; p[6] = t + 1;
            *(s16 *)(p + 0x1C) = 2;
            p[0x22] = 0;
            func_00178F20(p, *(u8 **)(p + 0x1DC));
            func_001757E0(p, 0xF, 2);
        }
    }
}

void func_00315850(u8 *p) {
    extern s32 func_00175700();
    extern void func_001757E0();
    extern void func_00183D50();
    u32 *v1, *a3, *a2, *t0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        v1 = (u32 *)(p + 0x5C); a3 = (u32 *)(p + 0x68); a2 = (u32 *)(p + 0x60); t0 = (u32 *)(p + 0x6C);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            *v1 = 0;
            *a2 = 0;
            *a3 = 0;
            *t0 = 0;
            func_001757E0(p, 0xF, 2);
            func_00183D50(p);
            { u32 t = p[6]; p[6] = t + 1; }
        }
    }
}

extern s8 D_004D1960[];
extern u8 D_004D1970[];
