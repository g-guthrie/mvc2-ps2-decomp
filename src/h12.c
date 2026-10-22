typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00174470(const void *);
extern void func_003928B0(void *p);
extern void *D_00471BF0[];

void func_00391990(u8 *p) {
    if (func_00174470(p) == 0) {
        func_003928B0(p);
    } else {
        ((void (*)(u8 *))D_00471BF0[p[5]])(p);
    }
}

extern s8 func_00175700();
void func_0034B4A0(u8 *p) {
    if (func_00175700(p) < 0) {
        u32 t = p[5]; p[5] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x60) = 0x41892492;
    }
}

extern void func_00380C60(void *p, s32 b);
void func_0027CAF0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6]; p[6] = t + 1;
        if (p[0x1B7] == 0) {
            *(s16 *)(p + 0x1C) = 0x12;
        } else {
            *(s16 *)(p + 0x1C) = 0x1E;
        }
        func_00380C60(p, p[0x1B7]);
    }
}


extern void func_002D9B00(void *p);
void func_002D9C70(u8 *p) {
    if (p[0x215] != 0) func_002D9B00(p);
    if (p[0x212] == 0) {
        if ((*(s8 *)(p + 0x1EA) & 0xF) != 0) func_002D9B00(p);
    } else {
        if ((*(s8 *)(p + 0x1EA) & 0xF0) != 0) func_002D9B00(p);
    }
}

extern void func_003DAA40();
void func_003C72B0(u8 *p, u8 *q) {
    if (q[5] != 1 || *(u16 *)(p + 0xD8) != *(u16 *)(q + 0x168) || *(s8 *)(q + 0x160) != 1) {
        func_003DAA40();
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(q + 0x1DC) + 0x24);
        *(u8 *)(p + 0x31) = 8;
    }
}

typedef struct { f32 x, y, z; } V3;
extern s8 func_00175670();
extern s8 func_00175700();
void func_0019B010(u8 *p, u8 *q) {
    if (*(u16 *)(p + 0xD0) == *(u16 *)(q + 0x168)) {
        *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        if (func_00175670(p) >= 0) return;
    }
    {
        u32 t = p[4]; p[4] = t + 1;
        p[0x13C] = 0;
    }
}

extern int func_00174470(const void *);
extern void func_00350FD0(void *p);

extern u8 *func_003DA750(void *p, s32 a, s32 b);
extern void func_003D77C0();
void func_003D7A50(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u8 *q;
        u32 t = p[5]; p[5] = t + 1;
        q = func_003DA750(p, 1, 2);
        if (q != 0) {
            *(void **)(q + 0x10) = func_003D77C0;
            *(u32 *)(q + 0x18) = *(u32 *)(p + 0x18);
            q[0x20] = 1;
            *(s32 *)(q + 0xD4) = 0xFF;
            *(s32 *)(q + 0xD0) = 0xFF;
            *(u8 **)(q + 0x14) = p;
        }
    }
}

extern void func_001548D0(void *p, void *v, s32 z);
extern void func_001E3710(void *p, s32 a);
extern void func_00231840(void *p, void *q);
void func_00231A10(u8 *p, u8 *q) {
    u32 v[3];
    u32 t = p[7]; p[7] = t + 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    v[0] = 0xC2995555;
    v[1] = 0x43474924;
    func_001548D0(p, v, 0);
    func_001E3710(p, 0x23);
    func_00231840(p, q);
}

extern void func_00352670(void *p, s32 a, s32 b, s32 c);
void func_00213D70(u8 *p, u8 *q) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6]; p[6] = t + 1;
        p[0x151] = 0;
        q[0] = 0xB;
        q[1] = 0x20;
        *(s16 *)(q + 2) = 3;
        func_00352670(p, 0, 0, 0);
        q[4] = 0xFF;
        *(s16 *)(p + 0x1C) = 10;
    }
}

typedef struct {
    s32 n;
    s32 m;
    f32 d;
    u8 pad0[8];
    f32 o1;
    f32 o2;
    u8 pad1[16];
    u8 flag;
    u8 pad2[3];
} S32D450;
extern void func_0032D230(void *c);
void func_0032D450(u8 *p, s32 n, u8 flag, f32 x) {
    S32D450 c;
    c.n = n;
    c.m = c.n + c.n * (c.n - 1) / 2;
    c.d = x - *(f32 *)(p + 0x34);
    c.flag = flag;
    if (c.n == 0) {
        c.o2 = 0.0f;
        c.o1 = 0.0f;
    } else {
        func_0032D230(&c);
    }
    *(f32 *)(p + 0x5C) = c.o1;
    *(f32 *)(p + 0x68) = c.o2;
}

extern s32 func_0028BA50(void *p);
extern u8 D_00456A40[];
s32 func_0028B9C0(u8 *p) {
    u8 *q = p + 0x2B8;
    u32 a;
    u16 k;
    if (*(s8 *)(p + 0x539) != 0) return func_0028BA50(p);
    q[0xC] = 0;
    a = *(u16 *)(p + 0x35C);
    if ((a & 0x300) != 0) q[0xC] |= 1;
    if ((a & 0x60) != 0) q[0xC] |= 2;
    k = (*(u16 *)(p + 0x354) & 0x3C00) >> 10;
    return D_00456A40[k];
}

extern void func_001843A0(void *p);
extern void func_001CEA00(void *p, s32 a);
extern void func_003996C0(void *p, s32 a);

extern u8 D_00454AB0[];
extern s32 func_00189310(void *p, void *a, void *b);
extern s32 func_00273C20(void *p);
extern void func_0018A990(void *p, void *a);
extern void func_00186A60(void *p, s32 a);
s32 func_00273990(u8 *p) {
    if (func_00189310(p, D_00454AB0, p + 0x390) == 0) return 0;
    if (func_00273C20(p) == 0) return 0;
    func_0018A990(p, p + 0x390);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 4;
    func_00186A60(p, 0x15);
    *(u32 *)(p + 0x2B8) = 0;
    *(u32 *)(p + 0x2BC) = 0;
    return 1;
}

extern void func_00185870();
extern void func_00374000(void *p);
extern void func_001E3210(void *p, s32 a);
extern void func_001266A0(void *p, s32 a, s32 b);
extern void func_0015E630(void *p);
void func_00374150(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1C4);
    u8 *r;
    q[0x13C] = 0;
    q[0x159] = 0xFF;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    r = *(u8 **)(p + 0x18);
    r[0x20B] = 0xC3;
    func_00185870(p);
    func_00374000(p);
    func_001E3210(r, 0xA);
    func_001266A0(r, 1, 7);
    p[0] = 1;
    func_0015E630(p);
}
