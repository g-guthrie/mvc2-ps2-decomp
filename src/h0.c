typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00186A60();
void func_00225E50(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 1;
        p[0x1B7] = 0;
        break;
    case 1:
        p[0x1FD] = 0;
        p[0x1B7] = 0;
        break;
    case 2:
        p[0x1FD] = 0;
        p[0x1B7] = 0;
        break;
    }
    func_00186A60(p, 0x15);
}

void func_00208040(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 2;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 3;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 0x15);
}

extern int func_00175670(u8 *);
extern void func_00372290(u8 *, int);
void func_001B47D0(u8 *p) {
    if ((s8)func_00175670(p) < 0) {
        p[4] = 2;
        p = *(u8 **)(p + 0x18);
        func_00372290(p, 0);
        func_00372290(p, 1);
        func_00372290(p, 2);
    }
}

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_003A5930(u8 *, int);
extern void func_003A5900(u8 *, int);
void func_003A5870(u8 *p, int a) {
    func_003A5930(p, *(int *)(p + 0x14));
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        func_003A5900(p, a);
    }
}

extern void func_001843A0(u8 *);
extern void func_00399720();

extern void func_0016B0C0(u8 *, int, int);
int func_00167E70(u8 *p, int a) {
    func_0016B0C0(p, a, 0);
    func_0016B0C0(p, a, 1);
    {
        u32 t = p[0x451];
        p[0x451] = t + 1;
    }
    *(int *)(p + 0x460) = *(int *)(p + 0x4C8);
    *(s8 *)(p + 0x201) = *(s8 *)(p + 0x4C8);
    p[0x1B1] = 0;
    return 1;
}

extern u8 *D_004C2840;
extern void func_003DAA40(u8 *);
void func_003B9100(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        if (*(int *)(D_004C2840 + 0x1C) != 0) {
            p[0x13C] = 0;
        } else {
            p[0x13C] = 1;
            func_00175700(p);
        }
    } else {
        u32 t = p[4];
        p[4] = t + 1;
        p[5] = 0;
    }
}

extern void func_003C1530(u8 *);
extern void func_003C15B0(u8 *, u8 *);
extern void func_003C15F0(u8 *, u8 *);
void func_003C19B0(u8 *p, u8 *a) {
    s16 v;
    func_003C1530(p);
    func_003C15B0(p, a);
    func_003C15F0(p, a);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
}

extern u8 *func_003DA750();
extern void func_001981E0();
void func_00198170(u8 *p, int a) {
    u8 *r = func_003DA750(0, 3, 0);
    if (r) {
        *(void **)(r + 0x10) = func_001981E0;
        *(int *)(r + 0x18) = *(int *)(p + 0x18);
        *(u8 **)(r + 0x14) = p;
        r[1] = p[1];
        r[0x20] = a;
        r[0x21] = 0;
        *(s16 *)(r + 0x26) = 0x304;
    }
}

extern void func_0015D010(u8 *, u32 *);
extern void func_0018C6E0(u8 *);
void func_002FF620(u8 *p) {
    u32 v[3];
    p[0x1B4] = 10;
    func_001757E0(p, 15, 7);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    v[0] = 0xC1C80000;
    v[1] = 0x433C9249;
    v[2] = 0;
    func_0015D010(p, v);
    func_0018C6E0(p);
}

extern u8 D_00456DB0[];
extern void func_00294B20(u8 *, u8 *);
extern void func_00294BC0(u8 *);
extern void func_001C09A0(u8 *, int);
extern void func_00385A20(u8 *, int);
void func_00290B90(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        func_00294B20(p, D_00456DB0);
        func_00294BC0(p);
        func_001C09A0(p, 3);
        func_00385A20(p, 3);
    }
}

extern void func_00186A20(u8 *);
void func_002B5D10(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        func_00186A20(p);
    }
}

void func_001F17F0(u8 *p) {
    u8 *q;
    p[0x1FE] = 1;
    q = p + 0x2B8;
    p[0x201] = 2;
    p[0x209] = 2;
    p[0x206] = 3;
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        q[2] = 0;
        func_001757E0(p, 0xF, 0x12);
    }
}

typedef void (*Cb2)(u8 *, u8 *);
extern Cb2 D_004C1C70[2];
void func_0036B430(u8 *p) {
    D_004C1C70[p[5]](p, *(u8 **)(p + 0x18));
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x1B3)) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

extern void func_0039C710();
u8 *func_0039C690(u8 *p) {
    u8 *r = func_003DA750(p, 1, 2);
    if (r) {
        *(void **)(r + 0x10) = func_0039C710;
        *(u8 **)(r + 0x18) = p;
        r[0x1B2] = 0;
        r[0x1B3] = 0;
        r[0x20] = *(s8 *)(p + 0x98) + 5;
        *(s16 *)(r + 0x26) = 0x2800;
        {
            u32 v = (*(u8 **)(p + 0x18))[1];
            r[1] = v;
            *(s16 *)(r + 0x8A) = v;
        }
        *(u16 *)(r + 0x88) = *(u16 *)(p + 0x168);
        return r;
    }
    return 0;
}

extern void func_00183D50();
void func_002000A0(u8 *p) {
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
        func_001757E0(p, 1, 3);
    }
}

extern void func_00372310();
void func_00372290(u8 *p, int a) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_00372310;
        r[0x20] = a;
        r[0x1B7] = p[0x1B7];
        *(u8 **)(r + 0x18) = p;
        r[1] = p[1];
        *(s16 *)(r + 0x26) = 0x1400;
        *(u16 *)(r + 0xD0) = *(u16 *)(p + 0x168);
        (*(s16 *)(p + 0x2D6))++;
    }
}

extern void func_00282700();

extern void func_00175C00(u8 *, int);
void func_00213E80(u8 *p, u8 *q) {
    s16 v;
    q[4] = 0xFF;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        q[4] = 0;
        func_00175C00(p, 0);
        func_001757E0(p, 0x16, 6);
    }
}

void func_0019ED50(u8 *p, u16 *q) {
    u8 *r = *(u8 **)(p + 0x18);
    p[0x13C] = 0;
    if (*(u16 *)(r + 0x168) != *q) {
        u32 t = p[4];
        p[4] = t + 1;
    } else if (*(s8 *)(r + 0x151)) {
        p[0x13C] = 1;
        *(s16 *)(p + 0x140) = *(s16 *)(r + 0x140);
        *(s8 *)(p + 0x31) = -1;
        *(f32 *)(p + 0x34) = *(f32 *)(r + 0x34) + *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38) + *(f32 *)(p + 0x60);
        func_00175700(p);
    }
}

extern void func_0028AA50(u8 *, u8 *);
void func_0028A9C0(u8 *p, u8 *q) {
    u32 t = q[0x18];
    q[0x18] = t + 1;
    *(s16 *)(p + 0x1C) = 6;
    q[0x19] = 0;
    if (p[0x1E6] == 0) {
        *(u32 *)(p + 0x5C) = 0x40855555;
    } else {
        *(u32 *)(p + 0x5C) = 0xC0855555;
    }
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x16, 8);
    func_0028AA50(p, q);
}

extern void func_003B2E60(u8 *, u8 *);
void func_003B2DD0(u8 *p, u8 *q) {
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        func_003B2E60(p, q);
    }
}

extern u8 *func_0039C5B0(u8 *, int);
extern void func_0039D100(u8 *);
void func_0039D070(u8 *p) {
    u8 *r;
    --*(s16 *)(p + 0x1C);
    if (*(s16 *)(p + 0x1C) < 0) {
        r = func_0039C5B0(p, 1);
        if (r) {
            u32 t;
            *(s16 *)(p + 0x1C) = 6;
            r[0x22] = p[0x22];
            t = p[0x22];
            p[0x22] = t + 1;
            --*(s16 *)(p + 0x1E);
            if (*(s16 *)(p + 0x1E) <= 0) {
                u32 t2 = p[5];
                p[5] = t2 + 1;
                func_0039D100(p);
            }
        }
    }
}

extern u32 D_00451AF0[];
extern int func_001E7FD0();

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B8050;
extern int D_004C283C;
extern void func_00337630();
void func_00337660(u8 *p) {
    u8 *r = func_003DA750(0, 6, 1);
    if (r) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = func_00337630;
        *(s16 *)(r + 0xCC) = 0x2C;
        *(int *)(r + 0x84) = D_004C283C;
        *(u8 **)(r + 0x14) = p;
        *(int *)(r + 0xD0) = 0x800;
        *(V3 *)(r + 0x34) = D_004B8050;
        *(u8 **)(r + 0xC8) = p + 0x88;
    }
}

extern void func_00185870(u8 *, u8 *);
void func_00200DB0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x2B8);
    u8 *a3 = p + 0x2B8;
    if (*(f32 *)(p + 0x38) > *(f32 *)(q + 0x38)) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s8 *)(a3 + 0xE) = -1;
        *(f32 *)(q + 0x38) = *(f32 *)(p + 0x38);
        func_001757E0(p, 0x16, 0x11);
        p[0x20B] = 0xC5;
        func_00185870(p, q);
    } else {
        func_00175700(p);
    }
}

extern s16 D_0044E9D0[];
extern u8 D_0044E9F0[][8];
extern void func_00175910(u8 *, int, int, int);
void func_001DBCD0(u8 *p) {
    if (*(s16 *)(p + 0x1C) >= D_0044E9D0[p[0x20]]) {
        u32 t;
        *(s16 *)(p + 0x1C) = D_0044E9D0[p[0x20]];
        t = p[5];
        p[5] = t + 1;
    }
    func_00175910(p, 0x12, D_0044E9F0[p[0x20]][*(s16 *)(p + 0x1C)], *(s8 *)(p + 0x151) & 0x7F);
    p[0x152] = *(s8 *)(p + 0x1E);
}
