typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 D_004D18B8[];
extern u32 D_004D18C4[];
extern u32 D_004C25D4;
extern u32 D_004C25D0;
extern s8 D_004F1F40[];
extern void (*D_004BF318[2])(void);

void func_001237A0(void) {
    D_004C25D4 = D_004D18B8[0];
    D_004C25D0 = D_004D18C4[0];
    D_004BF318[D_004F1F40[0]]();
}

u32 func_00292E20(u8 *p) {
    u32 x = p[34];
    u8 *q;
    u8 *r;
    u32 v = p[723];
    u8 t = v - 1;
    p[723] = t;
    q = p + 696;
    if (t == 0) {
        r = *(u8 **)(q + 20);
        q[12] = r[0];
        x = r[2];
        if (p[486] != 0) {
            x = (-(s8)x) & 0x1F;
        }
        q[27] = r[4];
        *(u8 **)(q + 20) = r + 6;
    }
    return x;
}

extern void func_00186A60();

void func_002620E0(u8 *p) {
    s32 m;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    m = *(s8 *)(p + 1245);
    switch (m) {
    case 0:
        p[509] = 2;
        p[439] = 0;
        break;
    case 1:
        p[509] = 0;
        p[439] = 1;
        break;
    case 2:
        p[509] = 2;
        p[439] = 0;
        break;
    }
    func_00186A60(p, 21);
}

void func_0023EEC0(u8 *p) {
    s32 m;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    m = *(s8 *)(p + 1245);
    switch (m) {
    case 0:
        p[509] = 2;
        break;
    case 1:
        p[509] = 0;
        p[6] = 0;
        break;
    case 2:
        p[509] = 0;
        p[32] = 1;
        p[33] = 2;
        p[6] = 1;
        break;
    }
    p[439] = 0;
    func_00186A60(p, 21);
}

extern u8 D_00583B94[];
extern u8 D_00583B96[];
extern u8 D_004B1220[];
extern u8 D_004B1221[];

void func_00137EC0(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    D_00583B94[*(s8 *)(p + 1336)] = D_004B1220[*(s8 *)(q + 1344) * 2];
    D_00583B96[*(s8 *)(p + 1336)] = D_004B1221[*(s8 *)(q + 1344) * 2];
}

extern u8 *func_003DA750();
extern void func_00329290();

u8 *func_00329220(u32 a, u32 b, u8 c) {
    u8 *p = func_003DA750(0, 12, 0);
    if (p != 0) {
        *(void **)(p + 16) = func_00329290;
        *(u32 *)(p + 24) = a;
        *(u32 *)(p + 20) = b;
        p[32] = c;
        *(s16 *)(p + 38) = 0x600;
    }
    return p;
}

extern s32 func_00175700();
extern void func_001843A0();

void func_002FA6C0(u8 *p, u8 *q) {
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 337) != 0) {
        p[337] = 0;
        q[12] = *(s8 *)(p + 439) + 1;
    }
}

extern void func_00175C00();
extern void func_001E3710();

void func_002E2D30(u8 *p) {
    s8 r;
    p[1036] = 2;
    p[828] = 5;
    r = func_00175700(p);
    if (r < 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
        func_00175C00(p, 0);
        func_001843A0(p);
        func_001E3710(p, 58);
    }
}

extern void func_0036AB90();

u8 *func_0036AA70(u8 *a, u8 b, u8 c) {
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        *(void **)(p + 16) = func_0036AB90;
        *(u32 *)(p + 24) = *(u32 *)(a + 24);
        *(u8 **)(p + 20) = a;
        p[32] = b;
        p[35] = c;
        *(s16 *)(p + 320) = *(s16 *)(*(u8 **)(p + 20) + 320);
    }
    return p;
}

extern s32 func_0016B240();
extern void func_0016B0C0();

s32 func_00165B00(u8 *p, u32 b) {
    if (func_0016B240(p, 4) == 0) {
        return 0;
    }
    func_0016B0C0(p, b, 0);
    func_0016B0C0(p, b, 1);
    p[487] = *(s8 *)(p + 1224);
    p[1210] = *(s8 *)(p + 1210) | 2;
    return 0;
}

extern s32 func_00175670();
extern void func_001B5350();

void func_001B41B0(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (p[209] != q[361] || *(s8 *)(q + 337) == 0) {
        p[4] = 2;
    } else {
        s8 r = func_00175670(p);
        if (r < 0) {
            p[4] = 2;
        }
        func_001B5350(q, p);
    }
}

extern void func_003A9300();

u8 *func_003A9280(u8 *a, u32 b) {
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        *(void **)(p + 16) = func_003A9300;
        *(u8 **)(p + 24) = a;
        *(u32 *)(p + 208) = b;
        *(s16 *)(p + 38) = 12035;
        if (a[3] == 0) {
            p[32] = 0;
        } else {
            p[32] = *(s8 *)(a + 32) + 1;
        }
    }
    return p;
}

extern void func_0019B110();

void func_0021B200(u8 *p) {
    s8 r;
    p[1036] = 2;
    p[828] = 5;
    r = func_00175700(p);
    if (r >= 0) {
        if ((*(s8 *)(p + 337) & 2) != 0) {
            func_0019B110(p, 7);
        }
    } else {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
        func_001843A0(p);
    }
}

extern void func_00176160();

void func_003BE240(u8 *p, u8 *q) {
    s8 r = func_00175700(p);
    if (r < 0) {
        p[36] = 0;
        func_00176160(q, 3, 8, 1);
    }
    if (*(s8 *)(p + 337) != 0) {
        p[36] = 15;
        func_00176160(q, 3, 5, 1);
    }
}

typedef struct { u32 w[16]; } S64;
extern void func_003DE230();

void func_003DE320(S64 *p, u32 b) {
    S64 tmp = *p;
    func_003DE230(&tmp, b, p);
    *p = tmp;
}

extern void (*D_0044D8B0[])(u8 *);

void func_001CA4D0(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    u32 t = q[347] >> 1;
    if (t != p[33]) {
        p[33] = t;
        p[5] = 0;
    }
    D_0044D8B0[p[32]](p);
    if (q[0] != 0 && *(s8 *)(q + 316) != 0) {
        p[316] = 1;
    } else {
        p[316] = 0;
    }
}

extern void func_003B9500();

u8 *func_003B9310(u8 *a, u8 b, u8 c) {
    u8 *p = func_003DA750(a, 1, 2);
    if (p != 0) {
        *(void **)(p + 16) = func_003B9500;
        *(float *)(p + 52) = *(float *)(a + 52);
        *(float *)(p + 56) = *(float *)(a + 56);
        *(u8 **)(p + 24) = a;
        *(u32 *)(p + 20) = *(u32 *)(a + 20);
        p[1] = (*(u8 **)(a + 20))[1];
        *(s16 *)(p + 38) = 13571;
        p[32] = b;
        p[33] = c;
    }
    return p;
}

typedef struct { float x, y, z; } V3;
extern s32 D_004C283C;
extern V3 D_004B82E8;
extern void func_00345450(u8 *);
extern void func_00170DF0(u32);

void func_003453C0(void) {
    u8 *p = func_003DA750(0, 11, 1);
    if (p != 0) {
        p[316] = 1;
        *(void **)(p + 16) = func_00345450;
        *(s16 *)(p + 204) = 47;
        *(s32 *)(p + 132) = D_004C283C;
        *(s32 *)(p + 208) = 0x800C01;
        *(V3 *)(p + 52) = D_004B82E8;
        *(u32 *)(p + 120) = 0;
        *(u32 *)(p + 124) = 0;
        *(u32 *)(p + 128) = 0;
        func_00170DF0((u32)*(u32 *)(p + 132));
    }
}

extern s16 *D_004C2794;

void func_0034B240(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    u16 z;
    if (q[617] == 3) {
        p[437] = 49;
        z = *(u16 *)(p + 448) = 0;
        p[434] = z;
        *(u32 *)(p + 472) = 0;
        (&D_004C2794[62])[p[2]]++;
    } else {
        p[437] = 48;
        z = *(u16 *)(p + 448) = 0;
        p[434] = z;
        *(u32 *)(p + 472) = 0;
        (&D_004C2794[62])[p[2]]++;
    }
    func_001757E0(p, 21, 18);
}

extern void func_00185490();
extern void func_00201260();

void func_00201370(u8 *p) {
    u16 z;
    u32 t;
    if (p[617] == 6) {
        p[1028] = 255;
        p[1029] = 16;
    }
    t = p[7];
    p[7] = t + 1;
    func_00185490(p);
    p[437] = 59;
    z = *(u16 *)(p + 448) = 0;
    p[434] = z;
    *(u32 *)(p + 472) = 0;
    (&D_004C2794[62])[p[2]]++;
    func_001757E0(p, 22, 14);
    func_00201260(p);
}

extern s32 func_001E7FD0();

s32 func_002E3880(u8 *p) {
    s32 r;
    if (*(s8 *)(p + 710) == 0 && p[525] != 1 && (*(u16 *)(p + 526) & 0xC00) != 0 && p[439] != 0) {
        r = func_001E7FD0(p);
        if (r != 0) {
            if (p[530] == 0) {
                p[523] = 0;
            } else {
                p[523] = 1;
            }
            *(u16 *)(p + 696) = *(u16 *)(p + 526);
        }
        return r;
    }
    return 0;
}

extern s32 D_0062BFD8[];
extern s32 D_0062BBE4[];
extern s32 D_0062BBB4[];

s32 func_003DC950(void) {
    s32 i = D_0062BFD8[0] ^ 1;
    while (D_0062BBE4[i] != 0 || D_0062BBB4[i] != 0) {
        __asm__("nop;nop;nop;nop;nop;nop");
    }
    return 1;
}
