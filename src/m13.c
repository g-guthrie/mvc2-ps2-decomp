typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern s32 func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_00183920(u8 *, f32 *);
extern void func_0016EDA0(s32, s32);
extern void func_00158470(u8 *);
extern void func_00158710(u8 *);
extern void func_001589A0(u8 *);
extern void func_00158BD0(u8 *);
extern u8 D_004D18D3;

void func_00158C70(u8 *p, s32 a) {
    if (a >= 0) {
        D_004D18D3 = 1;
        func_0016EDA0(a, 4);
    }
    func_00158470(p);
    func_00158710(p);
    func_001589A0(p);
    func_00158BD0(p);
}

void func_002EA1F0(u8 *p, u8 *q) {
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
            u32 t = p[7];
            p[7] = t + 1;
            q[0] = 1;
        }
    }
}

extern u32 D_004F1CC8;
extern u32 D_0044484C;
extern u32 D_0044485C;
extern u32 D_0044486C;
extern u32 D_0044487C;
extern u8 D_00444840[];
extern void func_00417FF0(s32);
extern void func_00123090();
extern void func_00417AE0(s32, u8 *);

void func_00153750(void) {
    u32 v = D_004F1CC8;
    D_0044484C = v;
    D_0044485C = v;
    D_0044486C = v;
    D_0044487C = v;
    func_00417FF0(0);
    func_00123090();
    func_00417AE0(4, D_00444840);
}

void func_00204AB0(u8 *p) {
    if (*(f32 *)(p + 0x6C) == 0.0f) {
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
    }
}

extern void func_001E7F60(u8 *);
extern void func_003B6380(u8 *, u8 *);

void func_003B6400(u8 *p, u8 *q) {
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        u32 t = p[5];
        p[5] = t + 1;
    }
    func_001E7F60(p);
    func_003B6380(p, q);
}

void func_002B3F70(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(s16 *)(p + 0x1C) -= 1;
    if (*(s16 *)(p + 0x1C) <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
    }
}

void func_00387B40(u8 *p, u8 *q) {
    if (q[4] >= 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else if ((s8)func_00175700(q) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

void func_002856C0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        f32 v[3];
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u32 *)&v[0] = 0x42695555;
        *(u32 *)&v[1] = 0x431A4924;
        *(u32 *)&v[2] = 0;
        func_00183920(p, v);
    }
}

extern void func_0025D8E0(u8 *);

void func_0025D650(u8 *p) {
    switch (p[0x1FC]) {
    case 1:
        func_0025D8E0(p);
        break;
    case 0:
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    }
}

extern u8 *func_003DA750(s32, u8, s32);
extern void func_001A3A90();

void func_001A3A10(u8 *p, u8 a, u8 b) {
    u8 *r = func_003DA750(0, 3, 1);
    if (r != 0) {
        *(s16 *)(r + 0x26) = 0xE00;
        r[0x20] = a;
        r[0x21] = b;
        *(void **)(r + 0x10) = func_001A3A90;
        *(u8 **)(r + 0x18) = p;
        *(s16 *)(r + 0x1C) = p[0x169];
    }
}

void func_00215040(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151) == 2) {
        u8 *q;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1E6] = p[0x1E6];
        q[0x1B5] = 0x21;
    }
}

extern void func_001DD4F0();

extern void func_0016F4D0(s32, s32);
extern void func_0016F530(s32, s32, s32, s32, s32, s32);

void func_0016F5B0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    func_0016F4D0(c, d);
    func_0016F530(a, b, c, d, e, f);
}

void func_002A6470(u8 *p) {
    f32 v;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x20D] = 2;
        if (p[0x1E6] != 0) {
            v = -10.0f;
        } else {
            v = 10.0f;
        }
        *(f32 *)(p + 0x5C) = v;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBF092492;
    }
}

extern void func_00248320();
extern void func_00360530(u8 *, s32, s32);

void func_00316980(u8 *p, u8 *q) {
    if (q[0x16] == 0) {
        if (*(f32 *)(p + 0x34) > (f32) * (s16 *)(q + 0x1C)) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(q + 0x18);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
            q[0x16] = 1;
        }
    } else {
        if (*(f32 *)(p + 0x34) < (f32) * (s16 *)(q + 0x1C)) {
            *(f32 *)(p + 0x5C) = *(f32 *)(q + 0x18);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
            q[0x16] = 0;
        }
    }
}

typedef struct {
    f32 x, y, z, w;
} V4;

extern s8 D_004F7F30;
extern s8 D_004F7F32;
extern V4 D_00476B70;
extern V4 D_00476B60;
extern void func_003DAA40(u8 *);

extern s32 func_00174470(u8 *);
extern s32 func_00174780(u8 *);
extern void (*D_00473C60[])(u8 *, u8 *);

void func_003B0030(u8 *p, u8 *q) {
    if (func_00174470(p) == 0 || func_00174780(p) == 0) {
        p[4] = 3;
    } else if (*(f32 *)(q + 0x430) > *(f32 *)(p + 0x38)) {
        p[4] = 2;
        p[6] = 0;
        p[7] = 0;
    } else {
        D_00473C60[p[6]](p, q);
    }
}

extern s32 func_001864a0(u8 *);
extern void func_00183d50(u8 *);

void func_001F5D40(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00183d50(p);
        func_001757E0(p, 1, 3);
    } else {
        func_00175700(p);
    }
}

s32 func_0021E010(u8 *p) {
    switch (p[0x1FC]) {
    case 2:
    case 1:
    case 0:
        if ((s8)func_00175700(p) < 0) {
            return func_001843A0(p);
        }
        break;
    case 0xFF:
        if ((s8)func_00175700(p) < 0) {
            return func_001843A0(p);
        }
        break;
    }
}

extern void func_0015D010(u8 *, f32 *);

void func_002CB930(u8 *p) {
    f32 v[3];
    p[0x1B4] = 10;
    if ((p[0x22] & 1) != 0) {
        s16 t = p[0x1E6] ^ 1;
        *(s16 *)(p + 0x140) = t;
        p[0x1E6] = t;
        t = p[0x1E6] ^ 1;
        *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
        (*(u8 **)(p + 0x1DC))[0x1E6] = t;
    }
    *(u32 *)&v[0] = 0x42555555;
    *(u32 *)&v[1] = 0x43892492;
    *(u32 *)&v[2] = 0;
    func_0015D010(p, v);
    func_001757E0(p, 0xF, 1);
}


void func_001DD470(u8 *p, u16 n) {
    u8 k = 3;
    u8 *r;
    if (n >= 3) {
        k = 4;
    }
    r = func_003DA750(0, k, 0);
    if (r != 0) {
        *(void **)(r + 0x10) = func_001DD4F0;
        *(u8 **)(r + 0x18) = p;
        r[1] = p[1];
        r[0x20] = n;
        *(s16 *)(r + 0x26) = 0x3603;
        *(u32 *)(r + 0xD0) = *(u16 *)(p + 0x168);
        r[0x22] = 0;
    }
}
