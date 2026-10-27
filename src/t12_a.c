typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 b[10]; } E10;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_001B9DD0();
extern s8 func_00175700(u8 *p);
extern void func_001843A0(u8 *p);
extern void func_003C4910(u8 *p, s32 a, s32 b);
extern E10 D_004B8700[];
extern void func_0039C3F0();
extern void func_0039C4D0(u8 *p, u8 *q, void *r);
extern void func_001830D0(u8 *p, u32 *v, s32 a, s32 b);
extern int func_00174470(const void *);
extern void func_003C80A0(u8 *p, u8 *q);
extern void func_00158C70(u8 *p, s32 n);
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_0035A560(u8 *p, u8 *q);
extern void func_00184540(u8 *p);
extern void func_001D5670(u8 *p, s32 a, s32 b);
extern void func_003A5D90(u8 *p, s32 a, s32 b);

u8 *func_001B9D50(u8 *a, s32 b) {
    u8 *o;
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = func_001B9DD0;
        *(u8 **)(o + 0x18) = a;
        *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
        *(s16 *)(o + 0x26) = 0x1700;
        o[0x20] = b;
        *(u16 *)(o + 0xD0) = *(u16 *)(*(u8 **)(o + 0x18) + 0x168);
        return o;
    }
    return 0;
}

void func_00318760(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != p[0x22]) {
        p[0x1B2] = 0;
        p[0x22] = *(s8 *)(p + 0x151);
    }
    if (p[0x15B] & 2) {
        p[0x15B] = p[0x15B] & 0xFD;
        func_003C4910(p, 10, 0);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}

void func_0039BD10(u8 *p) {
    u8 *q;
    u8 *r;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    r = (u8 *)((s32)q + 0x2B8);
    func_0039C3F0(p);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
        return;
    }
    if (p[0x20] == 0) r[2] = 1;
    func_0039C4D0(p, q, &D_004B8700[p[0x1B7] + p[0x20] * 2]);
    *(s16 *)(p + 0x1E) = 0x20;
}

void func_00325520(u8 *p) {
    u32 v[4];
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h <= 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        { u32 t = p[6]; p[6] = t + 1; }
        *(s16 *)(p + 0x1C) = 0x78;
        *(s16 *)(p + 0x1E) = 10;
        v[0] = 0;
        v[1] = 0x425EDB6D;
        func_001830D0(p, v, 1, 0x78);
    }
}

void func_003C6EB0(u8 *p, u8 *q) {
    s16 h;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) != 0) {
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h < 0) {
            *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1E);
            func_00158C70(p + 0x34, -1);
        }
    } else {
        func_003C80A0(p, q);
    }
}

void func_0035A640(u8 *p, u8 *q) {
    u32 t = p[5];
    u8 *g = *(u8 **)(p + 0x18);
    p[5] = t + 1;
    p[6] = 0;
    if (*(s16 *)(g + 0x140) == 0) {
        *(u32 *)(p + 0x5C) = 0x41200000;
        *(u32 *)(p + 0x68) = 0x3F555555;
    } else {
        *(u32 *)(p + 0x5C) = 0xC1200000;
        *(u32 *)(p + 0x68) = 0xBF555555;
    }
    *(u32 *)(p + 0x60) = 0x41CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    p[0x169] = 0x17;
    p[0x168] = 7;
    func_001757E0(p, p[0x169], p[0x168]);
    func_0035A560(p, q);
}

void func_002EC2D0(u8 *p, u8 *context_unused) {
    s8 f;
    if (func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    f = *(s8 *)(p + 0x151);
    if (f & 2) {
        *(s8 *)(p + 0x151) = f & ~2;
        func_001D5670(p, 6, 0);
        func_001D5670(p, 6, 1);
    }
    f = *(s8 *)(p + 0x151);
    if (f & 1) {
        *(s8 *)(p + 0x151) = f & ~1;
        func_003A5D90(p, 0, 0);
        func_003A5D90(p, 0, 1);
    }
}
