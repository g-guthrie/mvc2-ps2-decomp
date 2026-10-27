typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


extern u8 D_004F1F40[];
extern float D_004F1FC0;
extern u8 D_0044A2E0[];
extern u8 D_00473B90[];
extern void func_004142F0(u8 *);
extern void func_00417770(float, float);
extern void func_00134230(u8 *, u8 *);
extern void func_00334C40(u8 *);
extern void func_001227A0(void *, u32);
extern void func_001757E0(u8 *, s32, u32);
extern void func_001CA8F0(u8 *);
extern void func_003AE8A0(u8 *);

extern u32 D_00583BA0;
extern u32 D_00583BA4;
extern u32 D_00583BA8;
extern u32 D_00583BAC;

static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 220) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        } else {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        }
    }
}

static void func_00137860(u8 *a, s8 *b, u32 *c) {
    if (a[0x21] >= 0x20) {
        *c = D_00583BA4 | D_00583BAC;
        *b = *(s8 *)(a + 0x21) - 0x20;
    } else {
        *c = D_00583BA0 | D_00583BA8;
        *b = a[0x21];
    }
}

void func_00123060(void) {
    func_004142F0(D_004F1F40);
    func_00417770(0.0f, D_004F1FC0);
}

void func_0014FE90(u8 *p) {
    func_0014E770(p);
    *(s8 *)(p + 0x13C) = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
    *(float *)(p + 0x74) = *(float *)(*(u8 **)(p + 0x18) + 0x74);
}

void func_00133EE0(u8 *p, u8 *q) {
    s32 v = *(s16 *)(p + 0x1C);
    if (v >= 30) {
        func_00134230(p, q);
    } else {
        *(s16 *)(p + 0x1C) = v + 1;
    }
}

void func_001378C0(u8 *p) {
    s8 c;
    u32 m;
    func_00137860(p, &c, &m);
    if ((m & (1 << c)) == 0) {
        p[0x13C] = 0;
    } else {
        p[0x13C] = 1;
    }
}

s32 func_00334BF0(u8 *p) {
    if (*(float *)(p + 0x74) == 0.0f) {
        *(u32 *)(p + 0x74) = 0x3F800000;
    }
    *(u32 *)(p + 0x50) = 0x3F4CCCCD;
    p[6] = 1;
    func_00334C40(p);
    return 0;
}

void func_001227F0(void *from, void *to, u32 angle) {
    float *a = (float *)from;
    float *b = (float *)to;
    float t[3];
    t[0] = b[0] - a[0];
    t[1] = b[1] - a[1];
    t[2] = b[2] - a[2];
    func_001227A0(t, angle);
}

void func_00178E60(u8 *p) {
    u32 v = p[0x242];
    s32 t;
    if ((s32)v > 16) {
        v = (32 - (s8)v) & 0x1F;
    }
    t = (u8)v + 2;
    func_001757E0(p, 0xD, (u8)((u8)(t / 4) + 0x15));
}

void func_001CA890(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(float *)(p + 0x34) += (*(float *)(p + 0x5C) + *(float *)(q + 0x34) - *(float *)(p + 0x34)) / 8.0f;
    *(float *)(p + 0x38) += (*(float *)(p + 0x60) + *(float *)(q + 0x38) - *(float *)(p + 0x38)) / 8.0f;
    func_001CA8F0(p);
}





s32 func_00197560(u8 *a, u8 *b) {
    u8 *c = b + 0x2B8;
    s8 *r = (s8 *)(a + 0x88);
    s32 v;
    if (b[5] != 0) {
        *r = 0;
        return -1;
    }
    v = (s8)D_0044A2E0[b[0x1E4]];
    if (v < 0) {
        v = *(s8 *)(c + 0xC);
    }
    *r = v;
    return r[0] - r[1];
}

void func_003AE590(u8 *p) {
    if (*(u8 *)(*(u8 **)(p + 0x18) + 0x1E4) != 0x16) {
        func_003AE8A0(p);
    } else {
        (*(void (**)(void))(D_00473B90 + p[4] * 4))();
    }
}

extern void func_0035AE70(u8 *, u8 *);
extern u8 D_004D18A2;
extern void func_001917F0(u8 *, s32, s32);

/* Provisional: helper argument type and call sequence require reconciliation. */
void func_00359050(u8 *p, u8 *r) {
    u8 *q = *(u8 **)(p + 0x18);
    if (q[0x169] != 0x13 || q[0x168] != 4) {
        func_0035AE70(p, r);
    }
}

void func_00191430(u8 *p) {
    if (D_004D18A2 == 0) {
        u8 *q = *(u8 **)(p + 0x1DC);
        D_004D18A2 = *(s8 *)(q + 2) | 0x80;
        func_001917F0(q, 0, 0x1000000);
    }
}
