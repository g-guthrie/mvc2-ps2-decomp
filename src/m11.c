typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(void *p, s32 a, s32 b);
extern s32 func_00175700(void *p);

void func_00377C70(u8 *p) {
    u8 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        func_001757E0(p, 0x17, 0xF);
    }
    if ((s8)func_00175700(p) < 0) {
        u32 c = p[4];
        p[4] = c + 1;
        p[0x13C] = 0;
    }
}

extern void *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0019D830();

void func_0019D740(u8 *a, s32 b) {
    u8 *r = func_003DA750(0, 3, 0);
    if (r) {
        r[0] = 1;
        *(void **)(r + 0x10) = (void *)func_0019D830;
        *(u8 **)(r + 0x18) = a;
        *(u8 **)(r + 0xD4) = a;
        r[0x20] = 0;
        r[0x21] = b;
        *(s16 *)(r + 0x26) = 0xA02;
        r[1] = a[1];
    }
}

extern void func_00394780(void *p, s32 a, s32 b);
extern u8 D_00458900[];

void func_002A9950(u8 *p, s32 n) {
    func_00394780(p, (u8)(*(s16 *)(p + 0x1C) + 3), 0);
    *(s8 *)(p + 0x168) = *(s8 *)(D_00458900 + ((((s32)*(s16 *)(p + 0x1C) << 1) + (u8)n) << 2));
    func_001757E0(p, 0x15, p[0x168]);
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_00443C40[];
extern u8 D_004D17C9;

void func_00149CF0(u8 *p) {
    if (D_004D17C9 != p[0x20]) {
        u32 c = p[4];
        p[4] = c + 1;
        p[0x13C] = 0;
    } else {
        V3 *v = &D_00443C40[p[0x21]];
        *(f32 *)(p + 0x78) = v->x;
        *(f32 *)(p + 0x7C) = v->y;
        *(f32 *)(p + 0x80) = v->z;
    }
}

typedef struct { u8 pad[0x5B8]; } E5B8;
extern s16 D_004F20CE[];
extern u8 D_00583B92[];
extern u8 D_00583BC6;

void func_00138780(u8 *p) {
    s32 i = p[0x20];
    if (*(s16 *)((u8 *)D_004F20CE + i * 0x5B8) == 1 && (D_00583B92[i] & 0x20)) {
        u32 t = p[5];
        p[5] = t + 1;
        p[0x22] = 0;
        D_00583BC6 |= 1 << (s8)p[0x20];
    }
}

void func_00284D60(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x161) & 1) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x20D] == 2) {
            p[0x168] = p[0x1B7] ? 0x12 : 0x10;
        } else {
            p[0x168] = p[0x1B7] ? 0xC : 0xA;
        }
        func_001757E0(p, 0x15, p[0x168]);
    }
}

extern void func_001843A0(void *p);
extern void func_0031A990(void *p, void *q);

void func_0031A900(u8 *a, u8 *b) {
    if ((s8)func_00175700(a) < 0) {
        *(u32 *)(a + 0x5C) = 0;
        *(u32 *)(a + 0x60) = 0;
        *(u32 *)(a + 0x68) = 0;
        *(u32 *)(a + 0x6C) = 0;
        func_001843A0(a);
    } else if (a[0x15B] != 0) {
        a[0x15B] = 0;
        *(u8 **)(b + 0x1C8) = a;
        b[0x1B5] = 0x20;
        b[0x20A] = 1;
        func_0031A990(a, b);
    }
}

extern void func_0011D8F8(void *p, s32 a, s32 b);
extern void func_0018E810(void *p, void *q);

void func_0018DF40(u8 *p, u8 *q) {
    p[0x247] = 4;
    func_0011D8F8(p + 0x370, 0, 8);
    p[0x24A] = 0x78;
    p[0x248] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF892492;
    p[0x20D] = 2;
    func_0018E810(p, q);
    func_001757E0(p, 0xD, 9);
}

extern void func_001266A0();
extern void func_001E3210(void *p, s32 a);
extern void func_00184540(void *p);

void func_00225C00(u8 *p) {
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *q;
        *(s8 *)(p + 0x151) = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        func_001266A0(p, 0, 0);
        q[0x1B5] = 0x22;
        q[0x1E6] = p[0x1E6];
        func_001E3210(p, 0x20);
    }
    if ((s8)func_00175700(p) < 0) func_00184540(p);
}

void func_0038FE80(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        *(u32 *)(p + 0x60) = 0x404DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF092492;
    }
    func_00175700(p);
}

extern void func_00357650(void *p);

void func_003575B0(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        func_00357650(p);
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        *(s8 *)(p + 0x13C) ^= 1;
    }
}

extern s32 func_00175670(void *p);
extern void func_001B87B0(void *p);

void func_001B8710(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    if ((s8)func_00175670(p) < 0) func_001B87B0(p);
}

extern void func_00191F50(u8 *p);
extern void func_00191F20();

/* func_00192490: not yet matched without a stand-in callee. */

extern void func_0018FAA0();
extern void func_0015F4B0();

void func_00374D10(u8 *a) {
    u8 *s = *(u8 **)(a + 0x18);
    *(f32 *)(a + 0x34) = *(f32 *)(s + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(s + 0x38);
    if (*(s8 *)(a + 0x1B2) != 0) {
        a[4] = 2;
        func_0018FAA0(*(u32 *)(a + 0x1C4), 0x14);
        func_0015F4B0(*(u32 *)(a + 0x1C4), 4);
        func_001E3210(a, 0x1F);
    } else {
        func_00175700(a);
        func_001E7F60(a);
        if (*(s8 *)(s + 0x151) != 0) {
            u32 t = a[4];
            a[4] = t + 1;
        }
    }
}

extern f32 func_002ADC20();
extern void func_00183d50();

void func_002AF650(u8 *p) {
    func_00175700(p);
    if (func_002ADC20(p) < 0.0f) {
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6] = 4;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 10));
        func_00183d50(p);
    }
}

extern void *func_003DA750();
extern void func_00356450();

void func_00356330(u8 *p) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = (void *)func_00356450;
        r[0x20] = 0;
        *(u8 **)(r + 0x18) = p;
        r[1] = p[1];
        *(s16 *)(r + 0x26) = 0x901;
        *(u16 *)(r + 0x1C) = *(u16 *)(p + 0x168);
    }
    r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = (void *)func_00356450;
        r[0x20] = 0;
        *(u8 **)(r + 0x18) = p;
        r[1] = p[1];
        *(s16 *)(r + 0x26) = 0x901;
        *(u16 *)(r + 0x1C) = *(u16 *)(p + 0x168);
    }
}
