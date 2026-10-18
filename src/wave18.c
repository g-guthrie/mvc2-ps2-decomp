typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

u8 *func_00170E10(u8 *a0) {
    u8 *a1 = a0;
    while (*(s32 *)(a0 + 0x180) == -1 && a1) {
        u8 *v = *(u8 **)(a0 + 0x10);
        if (v) a0 = v;
        a1 = *(u8 **)(a0 + 0xC);
        if (a1) a0 = a1;
    }
    return a0;
}



s8 func_00175700(void *);
void func_00178E10(void *);
void func_001780B0(void *);
void func_00178050(u8 *a0) {
    s16 t;
    func_00175700(a0);
    t = *(s16 *)(a0 + 0x1C) - 1;
    *(s16 *)(a0 + 0x1C) = t;
    if (t == 0) {
        u32 u = a0[6];
        a0[6] = u + 1;
        func_00178E10(a0);
        func_001780B0(a0);
    }
}

void func_001DEE30(void *, s32);
void func_001DEEF0(void *, s32);
void func_001DF0B0(u8 *a0, s32 a1) {
    s16 c;
    func_001DEE30(a0, a1);
    func_001DEEF0(a0, a1);
    c = *(s16 *)(a0 + 0x1C);
    *(s16 *)(a0 + 0x1C) = c - 1;
    if (c == 0) {
        u32 u;
        *(s16 *)(a0 + 0x1C) = 0x20;
        u = a0[5];
        a0[5] = u + 1;
    }
}

void func_00186A60(void *, s32);
void func_002031E0(u8 *a0) {
    a0[5] = 0;
    a0[7] = 0;
    a0[6] = 0;
    switch (*(s8 *)(a0 + 0x4DD)) {
    case 0:
        a0[0x1FD] = 2;
        a0[0x1B7] = 1;
        break;
    case 1:
        a0[0x1FD] = 1;
        a0[0x1B7] = 1;
        break;
    case 2:
        a0[0x1FD] = 2;
        a0[0x1B7] = 1;
        break;
    }
    func_00186A60(a0, 0x15);
}

void func_003BD410(u8 *a0) {
    u8 *b;
    u8 *q;
    u8 *p = a0 + 0xD0;
    u32 t;
    t = a0[5];
    a0[5] = t + 1;
    a0[6] = 0;
    *(u32 *)(a0 + 0xD0) = *(u32 *)(a0 + 0x1C4);
    a0[0xD9] = 0xFF;
    b = *(u8 **)(a0 + 0x18);
    a0[0x22] = *(s8 *)(*(u8 **)(a0 + 0xD0) + 0x140);
    q = b + 0x2B8;
    if (b[0x2BA] == 0) q[3] = 0x78;
    p[7] = q[2];
    t = q[2];
    q[2] = t + 1;
    p[0xA] = 0;
}

void *func_003DA750(s32, s32, s32);
void func_0036AB90(void);
void func_0036A930(s32 a0, u8 a1, u8 a2, u8 a3) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_0036AB90;
        *(s32 *)(r + 0x18) = a0;
        r[0x20] = a1;
        r[0x21] = a3;
        r[0x23] = a2;
    }
}

void func_001861B0(void *);
void func_0022F590(void *, void *);
void func_0022F6D0(u8 *a0, u8 *a1) {
    u32 t = a0[7];
    a0[7] = t + 1;
    func_001861B0(a0);
    *(s8 *)(a1 + 0x14) = -0x7F;
    a0[0x169] = 0x15;
    a0[0x168] = *(s8 *)(a0 + 0x1B7) + 5;
    func_001757E0(a0, a0[0x169], a0[0x168]);
    func_0022F590(a0, a1);
}

typedef struct { f32 x, y, z; } V3;
void func_001BAD70(void *);
s8 func_00175670(void *);

void func_001843A0(void *);
void func_00272F50(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x1DC);
    if (func_00175700(a0) < 0) {
        func_001843A0(a0);
        return;
    }
    if (*(s8 *)(a0 + 0x151) != 0) {
        a0[0x151] = 0;
        *(u8 **)(s0 + 0x1C8) = a0;
        s0[0x20A] = 1;
        s0[0x1B5] = 0x20;
    }
}

extern u8 D_004CAB5A, D_004CAB5B, D_004CAB0A, D_004CAB0B, D_004CAB7A, D_004CAB7B, D_004CAB32, D_004CAB33;

s32 func_0016B250(void *, s32);
void func_0016B0C0(void *, void *, s32);
s32 func_001656A0(u8 *a0, void *a1) {
    if (!func_0016B250(a0, 0)) return 0;
    func_0016B0C0(a0, a1, 0);
    if (a0[0x1E4] != 0) {
        if (a0[0x1E4] != 7) {
            *(f32 *)(a0 + 0x38) = *(f32 *)(a0 + 0x430);
            a0[0x45A] = 0;
        }
    }
    return 1;
}

void *func_003DA750(s32, s32, s32);
void func_003B1FF0(void);
void func_003B1F70(u8 *a0, u8 a1, u8 a2) {
    u8 *r = func_003DA750((s32)a0, 1, 2);
    if (r) {
        *(void **)(r + 0x10) = func_003B1FF0;
        *(s16 *)(r + 0x26) = 0x3302;
        *(u8 **)(r + 0x14) = a0;
        r[1] = a0[1];
        *(s32 *)(r + 0x18) = *(s32 *)(a0 + 0x18);
        r[0x20] = a1;
        r[0x21] = a2;
    }
}

void func_0019B110(void *, s32);
void func_00219EB0(u8 *a0) {
    a0[0x40C] = 2;
    a0[0x33C] = 5;
    func_00175700(a0);
    if (*(s8 *)(a0 + 0x151) & 1) {
        u32 t = a0[6];
        a0[6] = t + 1;
        a0[7] = 0;
        *(f32 *)(a0 + 0x5C) = -40.0f;
        if (a0[0x1E6]) {
            *(f32 *)(a0 + 0x5C) = -*(f32 *)(a0 + 0x5C);
        }
        func_0019B110(a0, 5);
    }
}

extern V3 D_00460E00[];
void func_003451F0(void);
void func_00345300(s32 a0) {
    u8 *r = func_003DA750(0, 6, 1);
    if (r) {
        *(void **)(r + 0x10) = func_003451F0;
        *(s32 *)(r + 0xD0) = 0x901;
        *(V3 *)(r + 0x34) = D_00460E00[a0];
        r[0x20] = a0;
    }
}

void func_00183D50(void *);
void func_002B5DF0(u8 *a0) {
    *(f32 *)(a0 + 0x38) += *(f32 *)(a0 + 0x60);
    *(f32 *)(a0 + 0x60) += *(f32 *)(a0 + 0x6C);
    if (*(f32 *)(a0 + 0x430) > *(f32 *)(a0 + 0x38)) {
        u32 t = a0[6];
        a0[6] = t + 1;
        *(f32 *)(a0 + 0x38) = *(f32 *)(a0 + 0x430);
        func_00183D50(a0);
    } else {
        if (*(s8 *)(a0 + 0x151) == 0) func_00175700(a0);
    }
}

void func_0035AE70(void *, void *);

void func_0028A940(void *, void *);
void func_0028A8C0(u8 *a0, u8 *a1) {
    u32 t = a1[0x18];
    a1[0x18] = t + 1;
    *(s16 *)(a0 + 0x1C) = 6;
    a1[0x19] = 0;
    if (a0[0x1E6] == 0) {
        *(f32 *)(a0 + 0x5C) = -5.0f;
    } else {
        *(f32 *)(a0 + 0x5C) = 5.0f;
    }
    *(f32 *)(a0 + 0x68) = 0.0f;
    func_001757E0(a0, 0x16, 8);
    func_0028A940(a0, a1);
}

void func_0035B440(void *, void *);
void func_0035B1A0(void *, void *);
void func_0035B0A0(u8 *a0, u8 *a1) {
    u8 *b = *(u8 **)(a0 + 0x18);
    u8 *c = b + 0x2B8;
    s32 m = b[4];
    if (m >= 2) {
        a0[4] = 2;
        a0[0x13C] = 0;
    } else if (c[0xE]) {
        a0[0x13C] = 0;
    } else if (*(s8 *)(a1 + 0x13C) == 0) {
        a0[0x13C] = 0;
    } else if (a1[0x169] != 0x1A) {
        func_0035B440(a0, a1);
    } else {
        func_0035B1A0(a0, a1);
    }
}

void func_001266A0(void *, s32, s32);
void func_00314030(u8 *a0) {
    if (func_00175700(a0) < 0) {
        if (*(s16 *)(a0 + 0x140) == 0) {
            *(f32 *)(a0 + 0x34) = *(f32 *)(a0 + 0x34) - 66.666664f;
        } else {
            *(f32 *)(a0 + 0x34) += 66.666664f;
        }
        func_001266A0(a0, 0, 0);
        func_001843A0(a0);
    }
}

void func_001E3710(void *, s32);
void func_001D7790(void *, void *);
void func_001D76E0(u8 *a0, u8 *a1) {
    s16 c;
    if (*(s8 *)(a1 + 0x1B3) != 0) goto call;
    c = *(s16 *)(a0 + 0x1C) - 1;
    *(s16 *)(a0 + 0x1C) = c;
    if (c < 0) {
        *(s16 *)(a0 + 0x1C) = 8;
        func_001E3710(a0, 0x4F);
    }
    if (func_00175670(a0) < 0) {
call:
        func_001D7790(a0, a1);
    } else {
        *(s8 *)(a0 + 0x13C) = *(s8 *)(a0 + 0x13C) ^ 1;
    }
}

typedef struct { f32 x, y, z, w; } V4;
void func_00132310(void *, void *);
void func_00132BD0(u8 *a0) {
    u8 *a1 = *(u8 **)(a0 + 0x14);
    u8 *s1;
    *(V4 *)(a0 + 0x74) = *(V4 *)(a1 + 0x74);
    s1 = *(u8 **)(a0 + 0x18);
    *(f32 *)(a0 + 0x50) = (f32)*(s16 *)(s1 + 0x434) / 144.0f;
    if (*(s16 *)(a0 + 0x1E) < *(s16 *)(s1 + 0x434) && s1[0x425]) {
        func_00132310(a0, s1);
    }
    *(s16 *)(a0 + 0x1E) = *(s16 *)(s1 + 0x434);
}
