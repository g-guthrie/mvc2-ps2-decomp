typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern int func_00175700(u8 *);
extern s32 func_003D92F0(void *);
extern s32 func_001843A0(void *);
s32 func_002246E0(void *p) {
    func_00175700(p);
    if (func_003D92F0(p)) {
        return func_001843A0(p);
    }
}

typedef struct { u8 pad[0x1C]; u32 flags; } G4Ctx;
extern G4Ctx *D_004C2840;
extern void func_00254EE0();
extern void func_00255380(void *);
extern void func_00255460(void *);
extern void func_00255660(void *);

void func_00254E80(u8 *p) {
    if (!(D_004C2840->flags & 1)) {
        func_00254EE0();
    }
    if (p[5] == 0) {
        func_00255380(p);
    }
    func_00255460(p);
    func_00255660(p);
}

extern void func_002EE2E0();
extern void func_002EE360(void *);

void func_002EE280(u8 *p) {
    if (*(s32 *)(p + 0x2CC)) {
        func_002EE2E0();
    }
    if (*(s32 *)(p + 0x308)) {
        *(s32 *)(p + 0x308) = *(s32 *)(p + 0x308) - 1;
    }
    if (*(s32 *)(p + 0x304)) {
        *(s32 *)(p + 0x304) = *(s32 *)(p + 0x304) - 1;
    }
    func_002EE360(p);
}

extern u8 *func_003DA750();
extern void func_00375E80();

void func_00375DA0(u8 *p, u8 b) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r) {
        *(void **)(r + 0x10) = func_00375E80;
        *(u8 **)(r + 0x18) = p;
        r[0x20] = b;
        *(s16 *)(r + 0x26) = 0x1500;
        r[0x23] = p[0x425];
    }
}

extern u8 *D_004C2794;
extern s8 D_004C279C[2];
typedef struct { u8 *list[94]; } G4E;
extern G4E D_004D3170[];

extern G4E D_004D3170E[];
extern void func_001E7F60();

extern void func_00185490(void *);
extern s32 func_00178B00(void *);
extern void func_00178D80(void *, s32);

void func_00178800(u8 *p) {
    func_00185490(p);
    if (func_00178B00(p) == 0) {
        u32 h = *(u16 *)(p + 0x354);
        if (h & 0x2000) {
            func_00178D80(p, 3);
        } else if (!(h & 0x1000)) {
            func_00178D80(p, 1);
        }
    }
}

extern void func_001CB180(u8 *);
extern void func_001E3210(void *, s32);
extern int func_001CB5D0(u8 *);

void func_001CB4D0(u8 *p, u8 *q) {
    u32 t = p[5];
    if (t == 0) {
        p[5] = t + 1;
        func_001CB180(p);
    }
    if (*(s8 *)(p + 0x151)) {
        *(s8 *)(p + 0x151) = 0;
        func_001E3210(q, 0x22);
    }
    func_001CB5D0(p);
}

extern u8 D_0044FEC0[];
extern s32 func_00189310(void *, void *, void *);


extern s32 func_00174170();
extern s8 D_00448E10[];

void func_00182DB0(u8 *p, s32 b) {
    s16 v = D_00448E10[func_00174170() & 0x1F] + b;
    *(s16 *)(p + 0x270) = v;
    if (v <= 0) {
        *(s16 *)(p + 0x270) = 1;
    }
    *(s16 *)(p + 0x272) = *(s16 *)(p + 0x270);
}

extern void func_001757E0(void *, s32, s32);

void func_0036B2F0(u8 *p) {
    p[0x13C] = 1;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
    *(f32 *)(p + 0x34) += (f32)(p[0x23] * 80);
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x17, 10);
}

extern void func_0037EA30(void *, void *, s32);

void func_0037EF00(u8 *p, u8 *q) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[5];
        p[5] = t + 1;
        func_0037EA30(q, p, (u8)(q[0x1B7] + 2));
    }
    func_001E7F60(p);
}

extern void func_00357C40();

void func_003577C0(u8 *p, u8 b) {
    u8 *r = func_003DA750(p, 1, 2);
    if (r) {
        *(void **)(r + 0x10) = func_00357C40;
        r[0x20] = b;
        r[0x21] = p[0x21];
        *(s32 *)(r + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(r + 0x14) = p;
        r[1] = p[1];
        *(s16 *)(r + 0x26) = 0x903;
    }
}

void func_00220CE0(u8 *p) {
    if (p[0x2C5]) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        p[0x13C] = 1;
        func_001757E0(p, 0x15, 0x2C);
        func_001E3210(p, 0x23);
    } else {
        p[0x209] = 2;
        p[0x1FF] = 2;
        p[0x201] = 2;
    }
}

extern void func_002F8EB0(void *);
extern void func_002F8E40(void *);

void func_002F9160(u8 *p, u8 *q) {
    if ((s8)func_00175700(p) < 0) {
        func_002F8EB0(p);
    } else {
        if (*(s8 *)(p + 0x151)) {
            *(s8 *)(p + 0x151) = 0;
            q[0xC] = *(s8 *)(p + 0x1B7) + 1;
        }
        func_002F8E40(p);
    }
}

extern void func_001D37D0();

void func_001D3750(u8 *p, u8 b, u8 c) {
    u8 *r = func_003DA750(0, 3, 0);
    if (r) {
        *(void **)(r + 0x10) = func_001D37D0;
        r[0x20] = b;
        r[0x21] = c;
        *(u8 **)(r + 0x18) = p;
        r[1] = p[1];
        *(s16 *)(r + 0x26) = 0x2C01;
    }
}

extern void func_003DAA40();

void func_0032EC30(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    if (q[4] == 1) {
        func_003DAA40();
        return;
    }
    *(s8 *)(p + 0x13C) = *(s8 *)(q + 0x13C);
    switch (p[0x20]) {
    case 0:
        *(s32 *)(p + 0x48) = *(s32 *)(p + 0x48) - 0x100;
        break;
    case 1:
        *(s32 *)(p + 0x48) = *(s32 *)(p + 0x48) + 0x100;
        break;
    }
}

extern f32 D_004C1FF8[2];
extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
extern s32 func_003B5640();

s32 func_003B55C0(u8 *p, u8 idx) {
    if (*(f32 *)(p + 0x34) - D_004C1FF8[idx] < D_004F1FC8[0]) {
        return 1;
    }
    if (*(f32 *)(p + 0x34) + D_004C1FF8[idx] > D_004F1FCC[0]) {
        return 1;
    }
    return func_003B5640();
}

void func_0028AD20(u8 *p, u8 *q) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = q[0x18];
        q[0x18] = t + 1;
        *(s16 *)(p + 0x1C) = 10;
        if (p[0x1E6] == 0) {
            *(u32 *)(p + 0x68) = 0x3ED55555;
        } else {
            *(u32 *)(p + 0x68) = 0x3ED55555;
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
}

extern void func_003B93A0(void *);

void func_0030B320(u8 *p) {
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        if (*(s8 *)(p + 0x151)) {
            *(s8 *)(p + 0x151) = 0;
            p[0x28F] = 1;
            p[0x28E] = 0x10;
            func_003B93A0(p);
        }
    } else {
        func_001843A0(p);
    }
}

extern s32 func_00175670();


extern void func_00175C00(void *, s32);

void func_00252DB0(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        func_001757E0(p, 0x14, 2);
    } else if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}

extern void func_00186A20(void *);
extern void func_001830D0(void *, void *, s32);

void func_002B6EA0(u8 *p) {
    u32 v[3];
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s8 *)(p + 0x151) = 0;
        func_00186A20(p);
        v[0] = 0xC1D55555;
        v[1] = 0x42CDB6DB;
        v[2] = 0;
        func_001830D0(p, v, 1);
        *(s16 *)(p + 0x1C) = 10;
    }
}

extern void (*D_00464A10[])();


extern s32 func_0016B250(void *, s32);
extern void func_0016B0C0(void *, void *, s32);
extern s32 func_00166C80(void *, void *, s32);

s32 func_00166970(u8 *p, u8 *q) {
    if (func_0016B250(p, 3) == 0) {
        return 0;
    }
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    return func_00166C80(p, q, **(s8 **)(p + 0x420) >= *(s32 *)(p + 0x4C8));
}

extern u8 D_004D18A0[];
extern void (*D_00450880[])();
extern void func_0020D2A0();

void func_0020BFB0(u8 *p, u8 *q) {
    if (D_004D18A0[0] >= 5) {
        func_0020D2A0();
    } else {
        if (q[9] == 0) {
            s16 v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v == 0) {
                q[9] = 1;
            }
        }
        D_00450880[*(s16 *)(p + 0x1E)]();
    }
}

void func_00204B70(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x168] == 0xD) {
            *(u32 *)(p + 0x5C) = 0xC0BAAAAA;
            *(u32 *)(p + 0x60) = 0xC0F00000;
            if (*(s16 *)(p + 0x140)) {
                f32 x = *(f32 *)(p + 0x5C);
                *(f32 *)(p + 0x5C) = -x;
            }
        } else {
            *(u32 *)(p + 0x60) = 0xC1092492;
        }
    }
}
