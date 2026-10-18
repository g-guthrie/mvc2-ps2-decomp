typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 D_004CD1D8[];
extern u8 D_004CD1E6[];
extern s32 D_004C28B8;
extern void func_0012DA40(s32, s32, s32);
extern s32 func_001E5870(s32, s32);
void func_001E2330(void) {
    if (D_004CD1D8[0] != 0x3E) {
        func_0012DA40(0x3E, D_004C28B8 + 0x160000, 1);
        D_004CD1D8[0] = 0x3E;
        D_004CD1E6[0] = func_001E5870(D_004C28B8 + 0x160000, 5);
    }
}

extern f32 D_0044E430[];
extern s32 func_00175700();
extern s32 func_00118FA8(f32);
void func_001D5560(s8 *p) {
    func_00175700(p);
    p[0x24] = func_00118FA8(D_0044E430[p[0x151] >> 1]);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = ((u8 *)p)[5];
            ((u8 *)p)[5] = t + 1;
        }
    }
    p[0x13C] = ((u8 *)p)[0x15B] ? 0 : 1;
}

extern s32 func_001757E0(u8 *, s32, s32);
void func_00197EE0(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(u32 *)(p + 0x5C) = 0xC1555555;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0;
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        func_001757E0(p, 0x14, 8);
    }
}

void func_001D54D0(s8 *p, s8 *q) {
    func_00175700(p);
    p[0x24] = func_00118FA8(D_0044E430[p[0x151] >> 1]);
    if (q[0x2C0] != 0) {
        u32 t = ((u8 *)p)[5];
        ((u8 *)p)[5] = t + 1;
        *(s16 *)(p + 0x1C) = 10;
    } else {
        p[0x13C] = ((u8 *)p)[0x15B] ? 0 : 1;
    }
}

extern u8 D_004D18A0[];
extern void func_00186CE0(u8 *, s32);
void func_00179500(u8 *p) {
    func_00175700(p);
    if (D_004D18A0[0] > 2) {
        p[4] = 1;
        p[7] = 0;
        p[6] = 0;
        p[5] = 0;
        *(s8 *)(p + 0x1B1) = -0x80;
        if ((*(u32 *)(p + 0x428) & 0x6000000) == 0) {
            p[0x1E6] = p[2] ? 0 : 1;
            *(s16 *)(p + 0x140) = p[0x1E6];
        }
        p[0x1E4] = 0;
        func_00186CE0(p, 0);
    }
}

extern void func_001843A0(u8 *);
void func_0024A040(u8 *p) {
    u32 *a = (u32 *)(p + 0x5C);
    u32 *b = (u32 *)(p + 0x68);
    s8 r;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    r = func_00175700(p);
    if (r < 0) func_001843A0(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        *a = 0;
        *b = 0;
    }
}

extern s32 func_001864A0();
extern void func_00183D50(u8 *);
void func_001F6070(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864A0(p) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x14, 0);
        func_00183D50(p);
    }
}

extern u8 D_004F7FC0[];
extern u8 D_004F7D10[];
void func_003D4880(void) {
    u8 *d;
    u8 *src;
    s32 i;
    s32 off;
    u8 *s;
    src = D_004F7FC0;
    i = 0;
    off = 0;
    do {
        d = D_004F7D10 + off;
        s = src + off;
        d[0] = 0;
        d[1] = i;
        d[2] = (((s8 *)src)[6] >> i) & 1;
        d[3] = ((s8 *)src)[8 + i];
        d[4] = s[0x20];
        d[5] = s[0x22];
        d[6] = s[0x24];
        d[7] = s[0x26];
        d[0xA] = s[0x28];
        d[8] = s[0x2A];
        d[0xB] = s[0x2C];
        d[9] = s[0x2E];
        off += 0x10;
        i++;
    } while (i < 2);
}

typedef struct { f32 x, y, z; } V3;
extern u8 *func_003DA750();
extern s32 D_004C2838;
extern void func_00160EB0();
void func_00160D10(V3 *pos) {
    u8 *o = func_003DA750(0, 9, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_00160EB0;
        *(s16 *)(o + 0xCC) = 0xDD;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *pos;
        *(u32 *)(o + 0xD0) = 0x800035;
        *(s16 *)(o + 0x1C) = 0;
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        *(u32 *)(o + 0x74) = 0;
        *(u32 *)(o + 0x78) = 0;
        *(u32 *)(o + 0x7C) = 0;
        *(u32 *)(o + 0x80) = 0;
    }
}

extern u32 D_004BF658[2];
extern void func_001A2200(u8 *, u8 *);
extern void func_001A09B0(u8 *);
extern void func_001A23D0(u8 *, u8 *);
extern void func_001A2310(u8 *, u8 *);
void func_001A2050(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    func_001A2200(p, q);
    {
        u32 t = p[4];
        p[4] = t + 1;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(r + 0x24);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(r + 0x28);
    *(u32 *)(p + 0x1C4) = D_004BF658[p[0x20]];
    func_001A09B0(p);
    func_001A23D0(p, q);
    func_001A2310(p, q);
}

void func_002A6840(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 0xF, 5);
    }
}

extern void func_0015D010(u8 *, u32 *);
void func_00285C70(u8 *p) {
    u32 v[3];
    if (p[0x22] & 1) {
        s16 a = p[0x1E6] ^ 1;
        s16 b;
        *(s16 *)(p + 0x140) = a;
        p[0x1E6] = a;
        b = (*(u8 **)(p + 0x1DC))[0x1E6] ^ 1;
        *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = b;
        (*(u8 **)(p + 0x1DC))[0x1E6] = b;
    }
    v[0] = 0x413AAAAA;
    v[2] = 0;
    v[1] = 0x433C9249;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 0);
}

extern void func_001266A0(u8 *, s32, s32);
extern void func_0018C6E0(u8 *);
extern void func_001E3210(u8 *, s32);
void func_0020F510(u8 *p) {
    u32 v[3];
    if ((p[0x22] & 1) == 0) {
        u32 t = p[0x1E6];
        p[0x1E6] = t ^ 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    p[0x1B4] = 10;
    v[0] = 0xC2C15555;
    v[2] = 0;
    v[1] = 0x43009249;
    func_0015D010(p, v);
    func_0018C6E0(p);
    func_001E3210(p, 5);
    func_001757E0(p, 0xF, 5);
}
