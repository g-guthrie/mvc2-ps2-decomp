typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003BBDE0(u8 *p) {
    u8 *q;
    u8 *r;
    u8 *s = p + 208;
    u32 t = p[5];
    p[5] = t + 1;
    p[6] = 0;
    *(u32 *)s = *(u32 *)(p + 452);
    s[9] = 255;
    q = *(u8 **)(p + 24);
    p[316] = 0;
    r = q + 696;
    if (q[698] == 0) r[3] = 120;
    s[7] = r[2];
    { u32 t2 = r[2]; r[2] = t2 + 1; }
    s[10] = 0;
}

extern u32 func_00174170(void);
extern void func_001757E0(u8 *, s32, u8);
extern u8 D_0045D974[][4];

void func_0031B140(s8 *p) {
    if (p[337] != 0) {
        u32 r = func_00174170() & 3;
        func_001757E0((u8 *)p, 0, D_0045D974[p[337]][r]);
    }
}

void func_00376740(u8 *p) {
    u8 *q = *(u8 **)(p + 20);
    if (q[5] >= 4) {
        p[4] = 2;
    } else if (((s8 *)q)[434] != 0 && ((s8 *)q)[337] == 9) {
        u32 t = p[5];
        p[5] = t + 1;
        p[6] = 0;
        *(u32 *)(p + 452) = *(u32 *)(*(u8 **)(p + 20) + 452);
    }
}

extern void func_003DBBD0(u8 *, s32);


extern void func_00334B40(u8 *);

void func_00334AD0(u8 *p) {
    s32 n = *(s32 *)(p + 216) - 1;
    *(s32 *)(p + 216) = n;
    if (n == 0) {
        p[4] = 2;
        p[5] = func_00174170();
        p[5] = (u32)p[5] % 3u;
        func_00334B40(p);
    }
}

typedef struct { f32 f[3]; } V3;

void func_0036C6D0(u8 *p) {
    p[316] = 1;
    *(f32 *)(p + 52) = *(f32 *)(*(u8 **)(p + 20) + 52);
    *(f32 *)(p + 56) = *(f32 *)(*(u8 **)(p + 20) + 56);
    *(f32 *)(p + 60) = *(f32 *)(*(u8 **)(p + 20) + 60);
    *(s16 *)(p + 320) = *(s16 *)(*(u8 **)(p + 20) + 320);
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[36] = 0;
    *(u32 *)(p + 84) = 0;
    *(f32 *)(p + 280) = 1.0f;
    *(s16 *)(p + 30) = 3;
    func_001757E0(p, 23, 32);
}

extern void func_00175670(u8 *);

void func_001B72B0(u8 *p) {
    func_00175670(p);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    *(s16 *)(p + 28) = *(s16 *)(p + 28) - 1;
    if (*(s16 *)(p + 28) <= 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
}

extern s32 func_00185A90(u8 *);
extern s8 func_00175700(u8 *);
extern void func_00186A60(u8 *, s32);
extern void func_001E3C00(u8 *);
extern void func_00159A40(u8 *, s32);

void func_0017AEC0(u8 *p) {
    if (func_00185A90(p) == 0) {
        func_00175700(p);
        if ((((s8 *)p)[337] & 0xf) == 0) {
            p[525] = 2;
            func_00186A60(p, 14);
            p[493] = 0;
            func_001E3C00(p);
            func_00159A40(p + 52, 0);
        }
    }
}

extern void func_00179150(u8 *);
extern void func_00178F20(u8 *);


extern void func_00389950(u8 *, s32);

void func_003897F0(u8 *p) {
    func_00175700(p);
    if (((s8 *)p)[337] != 0) {
        u32 t = p[6];
        s16 v;
        p[6] = t + 1;
        v = *(s16 *)(p + 28) + 1;
        *(s16 *)(p + 28) = v;
        if ((v & 3) == 0) {
            func_00389950(p, 1);
        } else {
            func_00389950(p, 3);
        }
    }
}

void func_002EE2E0(u8 *p) {
    s32 n;
    if (((s8 *)p)[436] != 0) {
        *(s32 *)(p + 720) = *(s32 *)(p + 720) + 1;
    }
    n = *(s32 *)(p + 720) - 1;
    *(s32 *)(p + 720) = n;
    if (n <= 0) {
        *(s32 *)(p + 716) = 0;
        *(s32 *)(p + 724) = 0;
        *(s32 *)(p + 720) = 0;
        p[537] = 0;
        p[538] = 0;
        p[534] = 0;
    } else if (*(s32 *)(p + 724) == 2 && p[534] == 0 && *(s32 *)(p + 780) < 2) {
        *(s16 *)(p + 1016) = 3;
    }
}

extern u8 *func_001B3E30(u8 *, int, int);
extern void func_00126400(u8 *);
extern void func_001843A0(u8 *);

void func_0026A7C0(u8 *p) {
    func_00175700(p);
    if (((s8 *)p)[337] != 0) {
        u32 t;
        u8 *r;
        u8 *q;
        p[337] = 0;
        t = p[6];
        p[6] = t + 1;
        r = func_001B3E30(p, 9, 2);
        *(u8 **)(p + 20) = r;
        if (r == 0) {
            q = *(u8 **)(p + 476);
            q[316] = 1;
            *(f32 *)(q + 80) = 1.0f;
            *(f32 *)(q + 84) = 1.0f;
            *(u8 **)(q + 456) = p;
            q[522] = 1;
            func_00126400(q);
            func_001843A0(p);
        }
    }
}


void func_001D8F60(u8 *p, u8 *q) {
    if (*(u16 *)(q + 360) != *(u16 *)(p + 208)) {
        u32 t = p[4];
        p[4] = t + 1;
        p[316] = 0;
    } else {
        *(f32 *)(p + 52) = *(f32 *)(q + 52) + *(f32 *)(p + 92);
        *(f32 *)(p + 56) = *(f32 *)(q + 56) + *(f32 *)(p + 96);
        ((s8 *)p)[36] = ((s8 *)q)[36];
        if (func_00175700(p) < 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[316] = 0;
        }
    }
}

extern u8 *func_003DA750(s32, s32, s32);
extern void func_001D15E0(void);

void func_001D1550(u8 *a) {
    u8 *r = func_003DA750(0, 4, 1);
    if (r != 0) {
        *(void **)(r + 16) = func_001D15E0;
        *(u8 **)(r + 24) = a;
        r[32] = 0;
        *(s16 *)(r + 38) = 10755;
    }
    r = func_003DA750(0, 4, 1);
    if (r != 0) {
        *(void **)(r + 16) = func_001D15E0;
        *(u8 **)(r + 24) = a;
        r[32] = 1;
        *(s16 *)(r + 38) = 10755;
    }
}

extern void func_00183D50(u8 *);

void func_002E7600(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    if (*(f32 *)(p + 56) < *(f32 *)(p + 1072)) {
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        p[525] = 0;
        func_00183D50(p);
        func_001843A0(p);
    }
}

typedef struct { f32 m[16]; } Mtx;

void func_003DE0C0(Mtx *p) {
    Mtx t = *p;
    p->m[1] = t.m[4];
    p->m[2] = t.m[8];
    p->m[3] = t.m[12];
    p->m[4] = t.m[1];
    p->m[6] = t.m[9];
    p->m[7] = t.m[13];
    p->m[8] = t.m[2];
    p->m[9] = t.m[6];
    p->m[11] = t.m[14];
    p->m[12] = t.m[3];
    p->m[13] = t.m[7];
    p->m[14] = t.m[11];
}

extern void (*D_00472B40[])(u8 *, u8 *);
extern void func_003DAA40(void);

