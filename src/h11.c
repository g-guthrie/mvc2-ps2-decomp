typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_002CFA20(u8 *);
extern void func_00186A60(u8 *, s32);
extern void func_00176160(u8 *, s32, s32, s32);
extern void func_003B1AA0(u8 *, u32);
extern void func_003B1A70(u8 *, u8 *);
extern void func_003DAA40(u8 *);
extern s32 func_00189310(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern u8 D_00451450[];
extern u32 func_00174170(void);
extern void func_001E3CE0(s32);

void func_00238ED0(u8 *p) {
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 1;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 2;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 0x15);
}

void func_002D3190(u8 *p) {
    if (p[7] != 0) {
        u32 t = p[0x15B];
        if (t != 0) {
            u32 k = p[0x25];
            s32 a = (u8)t - 1;
            s32 b = k * 5;
            func_00176160(p, 2, a + b, 1);
            p[0x15B] = 0;
        }
    }
    func_00175700(p);
}

void func_003B19E0(u8 *p, u8 *q) {
    func_003B1AA0(p, *(u32 *)(p + 0x14));
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        func_003B1A70(p, q);
    }
}

s32 func_00222C70(u8 *p) {
    if (func_00189310(p, D_00451450, p + 0x380) == 0) return 0;
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    p[0x1FD] = 1;
    return 1;
}

void func_00236CD0(u8 *p) {
    p[0x1FE] = 1;
    if ((s8)func_00175700(p) >= 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            *(s16 *)(p + 0x140) ^= 1;
            p[0x1E6] ^= 1;
        }
    } else {
        func_001843A0(p);
    }
}

void func_00135230(s32 a) {
    switch (a) {
    case 0:
        func_001E3CE0((u8)(func_00174170() % 3 + 6));
        break;
    case 1:
        func_001E3CE0(9);
        break;
    case 2:
        break;
    }
}

extern void func_00139BA0(u8 *);
extern u8 D_00583B90[];
extern u8 D_00583B92[];
void func_00139B10(u8 *p) {
    u8 a;
    u8 b;
    func_00139BA0(p);
    a = p[0x20];
    b = p[0x21];
    if ((D_00583B92[a] & (0x10 << b)) != 0 && D_00583B90[a] == 3) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

extern void func_00175670(u8 *);
extern void func_001C1330(u8 *, u8 *);
void func_001C0EF0(u8 *p, u8 *q) {
    func_00175670(p);
    func_001C1330(p, q);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 0;
    if (*(s8 *)(q + 0x151) == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        p[0x13C] = 0;
        if (p[0x22] == 0) p[0x13C] = 1;
    }
}

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
extern int func_00174470(const void *);
extern void func_00350FD0(u8 *);
void func_00350820(u8 *p) {
    F(p, 0x34) += F(p, 0x5C);
    F(p, 0x5C) += F(p, 0x68);
    F(p, 0x38) += F(p, 0x60);
    F(p, 0x60) += F(p, 0x6C);
    func_00175700(p);
    if (func_00174470(p) == 0) {
        func_00350FD0(p);
        return;
    }
}
