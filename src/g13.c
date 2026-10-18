typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_00198820(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(u32 *)(p + 0x34) = 0x42D55555;
    *(u32 *)(p + 0x38) = 0x434DB6DB;
    if (*(s16 *)(q + 0x140) == 0) *(float *)(p + 0x34) = -*(float *)(p + 0x34);
    *(float *)(p + 0x34) += *(float *)(q + 0x34);
    *(float *)(p + 0x38) += *(float *)(q + 0x38);
    p[0x24] = 10;
    p[0x13C] = 0;
}

extern u8 *func_003DA750();
extern void func_0034A720();
void func_0034A6B0(u8 *a, u8 b) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o) {
        *(void **)(o + 0x10) = func_0034A720;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        o[0x20] = b;
        *(s16 *)(o + 0x26) = 0x303;
    }
}

extern s8 func_00175670();
typedef struct { float x, y, z; } V3;
void func_001BD1C0(u8 *p, u8 *q) {
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if (func_00175670(p) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}
extern s8 func_00175700();
extern void func_001757E0();
extern s32 func_001C47D0();
void func_00325380(u8 *p) {
    s16 v;
    u32 t, u;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        t = p[6];
        p[6] = t + 1;
        u = p[0x168];
        p[0x168] = u + 1;
        func_001757E0(p, 0x15, (u8)(u + 1));
    }
}
void func_001C44D0(u8 *p, u8 *q) {
    if (func_00175700(p) < 0) {
        if (func_001C47D0(p, q)) {
            p[6] = 4;
            p[7] = 0;
        } else {
            p[6] = 3;
            p[7] = 0;
        }
    }
}
extern void func_0018D580();
void func_0018D930(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1C8);
    if (q) {
        u8 t = q[3];
        if (t == 0 || t == 1) {
            u32 i = p[0x1B6] & 0x7F;
            *(u8 **)(p + 0x1D0) = *(u8 **)(q + 0x184) + i * 28;
            if (*(u32 *)(p + 0x1D0)) func_0018D580(p, q);
        }
    }
}
extern void func_00186A60();
void func_00207FD0(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 2; p[0x1B7] = 1; break;
    case 1:
        p[0x1FD] = 3; p[0x1B7] = 1; break;
    case 2:
        p[0x1FD] = 0; p[0x1B7] = 1; break;
    }
    func_00186A60(p, 0x15);
}
void func_0026AD90(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0: p[0x1FD] = 1; p[0x1B7] = 0; break;
    case 1: p[0x1FD] = 0; p[0x1B7] = 0; break;
    case 2: p[0x1FD] = 2; p[0x1B7] = 0; break;
    }
    func_00186A60(p, 0x15);
}
extern void func_00183920();
void func_00323A90(u8 *p) {
    u32 v[4];
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        t = p[6] + 1;
        p[6] = t;
        v[0] = 0xC23AAAAA;
        v[1] = 0x42092492;
        func_00183920(p, v, t);
    }
}

extern void func_0016B0C0();
extern void func_00154790();
extern void func_001E3210();
extern void func_0037D220();
extern s32 func_001745B0();
extern void func_001843A0();

s32 func_00167E00(u8 *p, u8 *q) {
    u32 t;
    if (p[0x425]) return 1;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    t = p[0x451];
    p[0x451] = t + 1;
    *(u32 *)(p + 0x460) = *(u32 *)(p + 0x4C8);
    return 1;
}

void func_001549B0(u8 *p, float *q) {
    u8 *r = *(u8 **)(p + 0x1DC);
    float v[3];
    if (*(s16 *)(p + 0x140)) {
        v[0] = *(float *)(p + 0x34) - q[0];
    } else {
        v[0] = *(float *)(p + 0x34) + q[0];
    }
    v[1] = *(float *)(p + 0x38) + q[1];
    v[2] = *(float *)(p + 0x3C);
    func_00154790(v, *(s16 *)(r + 0x140), 1, 0);
}

void func_001BE230(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        p[0x13C] = 1;
        *(s16 *)(p + 0x1C) = 10;
        if ((1 << p[0x20]) & 0x3F55555) func_001E3210(p, 0x14);
    }
}

u8 *func_0037D1B0(u8 *p) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o == 0) return 0;
    *(void **)(o + 0x10) = func_0037D220;
    *(u8 **)(o + 0x18) = p;
    *(s16 *)(o + 0x26) = 0x1705;
    *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
    o[1] = p[1];
    *(u32 *)(p + 0x2E4) = 1;
    return o;
}

void func_001C43A0(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    u32 t;
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (func_001745B0(p) == 0) {
        r[3] = 0;
        t = p[4];
        p[4] = t + 1;
        p[7] = 0;
        p[6] = 0;
        p[5] = 0;
    }
}

void func_002FA410(u8 *p) {
    u32 v[4];
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151)) {
        *(s8 *)(p + 0x151) = 0;
        v[0] = 0x424EAAAA;
        v[1] = 0x42F00000;
        v[2] = 0;
        func_00183920(p, v);
    }
}

extern void func_003B1130();
extern void func_00374A60();
extern void func_00184540();

void func_003B1530(u8 *p, u8 *q) {
    u32 t;
    func_00175700(p);
    *(s16 *)(p + 0x1C) += 1;
    func_003B1130(p, 1, *(s16 *)(p + 0x1C) & 1, *(s16 *)(p + 0x1C) & 3);
    if (q[0x2B8]) {
        t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, 6);
    }
}

void func_003749E0(u8 *a, u8 b) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o) {
        *(void **)(o + 0x10) = func_00374A60;
        o[1] = a[1];
        *(s16 *)(o + 0x26) = 0x1403;
        o[0x20] = b;
        *(u8 **)(o + 0x18) = a;
        *(u16 *)(o + 0xD0) = *(u16 *)(a + 0x168);
        o[0xD1] = a[0x169];
        o[0xD0] = a[0x168];
    }
}

void func_001FF120(u8 *p) {
    p[0x2C4] = 0;
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (func_00175700(p) < 0) func_00184540(p);
}

void func_001C76E0(u8 *p) {
    s16 v;
    u32 t;
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[7];
        p[7] = t + 1;
        p[0x22] = 0x30;
        *(float *)(p + 0x70) = *(float *)(p + 0x38);
    }
    func_00175700(p);
}
void func_002CDA00(u8 *p) {
    float old = *(float *)(p + 0x60);
    float nv;
    *(float *)(p + 0x38) += old;
    nv = (*(float *)(p + 0x60) += *(float *)(p + 0x6C));
    if (old > 0.0 && nv < 0.0) *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
}

extern void func_0029FA00();
extern s32 func_001864a0();
extern void func_001865B0();
extern void func_0018C6E0();
extern void func_0015D010();
extern void func_001266A0();

void func_0029FE70(u8 *p) {
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    func_00175700(p);
    func_0029FA00(p);
    if (func_001864a0(p)) func_001865B0(p);
}

void func_00315540(u8 *p) {
    u32 v[4];
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 6);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    v[0] = 0xC2D55555;
    v[1] = 0x42CDB6DB;
    v[2] = 0;
    func_0015D010(p, v);
    func_001266A0(p, 1, 1);
}

extern void func_00162740();
extern s16 D_004B40A0[];
extern float D_004B4060[];
void func_001626C0(u8 *a, u8 *b) {
    s32 i = *(s32 *)(b + 0xDC);
    float *y = D_004B4060;
    s16 *x = D_004B40A0;
    b[0x13C] = 1;
    x += i * 8;
    y += i * 8;
    x += *(s16 *)(b + 0x1C);
    *(s16 *)(b + 0x1E) = *x;
    y += *(s16 *)(b + 0x1C);
    *(float *)(b + 0x74) = *y;
    b[4] = 2;
    *(float *)(b + 0x34) = *(float *)(a + 0x34) + *(float *)(b + 0x5C);
    *(float *)(b + 0x38) = *(float *)(a + 0x38) + *(float *)(b + 0x60);
    func_00162740(a, b);
}
