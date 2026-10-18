typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18D3[];
extern u8 D_004D1900[];
extern u8 D_004461C0[];

extern u8 D_004B55F0[];
extern u8 D_00457490[];
extern void (*D_00473B10[])(u8 *);
extern void func_001360C0(u8 *);
extern void func_001CA7E0(u8 *);
extern void func_003DAA40(void);
extern void func_001E3710();
extern void func_0034CF30(u8 *, u8 *);
extern void func_0034D080(u8 *);
extern s32 func_00185980(u8 *);
extern void func_00175700();
extern void func_00294B20(u8 *, u8 *);
extern void func_00294BC0(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_003DDB70(u8 *);
extern void func_003DDC30(u8 *, f32);
extern void func_003DDD00(u8 *, f32);
extern void func_00193180(u8 *);
extern void func_00193380(u8 *);
extern s32 func_00174170(u8 *);
extern void func_001CB5A0(u8 *, s32, s32);
extern void func_00289570(u8 *);
extern void func_003AE8A0(u8 *);



void func_00337800(u8 *p) {
    s16 v;
    *(s16 *)(p + 28) = *(s16 *)(p + 28) + 1;
    v = *(s16 *)(p + 28) % 40;
    *(s16 *)(p + 28) = v;
    if (v == 0) p[4] = 0;
}

void func_00136070(u8 *p) {
    s16 v;
    *(f32 *)(p + 60) += *(f32 *)(p + 100);
    v = *(s16 *)(p + 28) - 1;
    *(s16 *)(p + 28) = v;
    if (v <= 0) func_001360C0(p);
}

void func_00154B10(u8 *p) {
    if (*(s16 *)(p + 28) > 10) {
        func_003DAA40();
        D_004D1900[0] = D_004D1900[0] - 1;
    } else {
        *(s16 *)(p + 28) += 1;
    }
}

typedef struct { f32 f[3]; } V3;
typedef void (*Fn)(u8 *);
typedef struct { Fn f[3]; } FnTbl;
extern FnTbl D_00472780;

void func_0039D020(u8 *p) {
    FnTbl t = D_00472780;
    t.f[p[5]](p);
}

void func_001695A0(u8 *p) {
    s32 v = *(s8 *)(p + 0x4A9);
    if (v != 0 && ((s8)v & 2) == 0 && *(s8 *)(p + 0x1B2) != 0) {
        *(s8 *)(p + 0x4A9) = v | -128;
        if (*(s8 *)(p + 0x1B2) & 1) {
            *(s8 *)(p + 0x4A9) = *(s8 *)(p + 0x4A9) | 2;
        }
    }
}

void func_001CA780(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    *(f32 *)(p + 52) += (*(f32 *)(p + 92) + *(f32 *)(q + 52) - *(f32 *)(p + 52)) / 8.0f;
    *(f32 *)(p + 56) += (*(f32 *)(p + 96) + *(f32 *)(q + 56) - *(f32 *)(p + 56)) / 8.0f;
    func_001CA7E0(p);
}



void func_0036CBD0(u8 *p) {
    p[316] = 1;
    *(f32 *)(p + 52) = *(f32 *)(*(u8 **)(p + 24) + 52);
    *(f32 *)(p + 56) = *(f32 *)(*(u8 **)(p + 24) + 56);
    *(f32 *)(p + 60) = *(f32 *)(*(u8 **)(p + 24) + 60);
    p[36] = 11;
    *(f32 *)(p + 280) = 0.5f;
    func_001757E0(p, 0x17, (u8)((*(u8 **)(p + 24))[7] + 13));
}

void func_003DDEC0(u8 *p, f32 x, f32 a, f32 b) {
    func_003DDB70(p);
    func_003DDC30(p, a);
    func_003DDD00(p, b);
}
extern void func_003F38E0(u8 *);
extern void func_003F39E0(u8 *, f32);
extern void func_003F3AE0(u8 *, f32);
void func_003F3BE0(u8 *p, f32 x, f32 a, f32 b) {
    func_003F38E0(p);
    func_003F39E0(p, a);
    func_003F3AE0(p, b);
}

void func_001CB0D0(u8 *p) {
    p[5] = 0;
    if ((func_00174170(p) & 3) != 0) {
        func_001CB5A0(p, 0x1B, 0x50);
    } else {
        func_001CB5A0(p, 0x1B, 0x51);
    }
}

void func_0028C2C0(u8 *p) {
    u8 *q = p + 0x2B8;
    func_00289570(p);
    func_00175700();
    if (*(s8 *)(p + 0x151) != 0) {
        p[7]++;
        q[9] = 1;
    }
}

void func_003ADA10(u8 *p) {
    if (*(u16 *)(*(u8 **)(p + 24) + 0x168) != *(s16 *)(p + 28)) {
        func_003AE8A0(p);
    } else {
        D_00473B10[p[4]](p);
    }
}
