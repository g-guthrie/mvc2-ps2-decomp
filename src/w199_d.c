typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[0x31]; } W199S;
typedef struct { float x, y, z; } V3;

u8 *func_003CA900(u8 *a, unsigned int b) {
    extern u8 *func_003DA750();
    extern void func_003CAA20();
    extern void func_003CAB20(u8 *, u8 *, unsigned int);
    u8 *o;
    if ((o = func_003DA750(0, 1, 1)) != 0) {
        *(void **)(o + 0x10) = func_003CAA20;
        *(u8 **)(o + 0x18) = a;
        o[1] = a[1];
        *(s16 *)(o + 0x26) = 0x3A01;
        *(W199S *)(o + 0xEC) = *(W199S *)(a + 0xEC);
        o[0x13C] = 1;
        o[2] = a[2];
        o[1] = a[1];
        *(float *)(o + 0x50) = *(float *)(a + 0x50);
        *(float *)(o + 0x54) = *(float *)(a + 0x54);
        o[0x1B7] = a[0x1B7];
        o[0x1B8] = a[0x1B8];
        *(s8 *)(o + 0x30) = *(s8 *)(a + 0x30);
        *(V3 *)(o + 0x50) = *(V3 *)(a + 0x50);
        *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
        *(s8 *)(o + 0x24) = 8;
        func_003CAB20(o, a, b);
    }
    return o;
}

void func_001D0710(u8 *d, u8 *s) {
    extern void func_00175910();
    extern void func_003DAA40();
    if (d[4] == 0) {
        u32 t = d[4];
        d[4] = t + 1;
        *(W199S *)(d + 0xEC) = *(W199S *)(s + 0xEC);
        d[0x13C] = 1;
        d[2] = s[2];
        d[1] = s[1];
        *(float *)(d + 0x50) = *(float *)(s + 0x50);
        *(float *)(d + 0x54) = *(float *)(s + 0x54);
        d[0x1B7] = s[0x1B7];
        d[0x1B8] = s[0x1B8];
        *(s8 *)(d + 0x30) = *(s8 *)(s + 0x30);
        *(V3 *)(d + 0x50) = *(V3 *)(s + 0x50);
        *(s8 *)(d + 0x24) = *(s8 *)(s + 0x24);
        d[0x13C] = 0;
        *(s8 *)(d + 0x31) = -1;
    }
    if (*(u16 *)(s + 0x168) == *(s32 *)(d + 0xD0)) {
        s32 t = *(s8 *)(s + 0x151);
        if (t != 0) {
            func_00175910(d, 0x17, 2, (s8)t - 1);
            *(float *)(d + 0x34) = *(float *)(s + 0x34);
            *(float *)(d + 0x38) = *(float *)(s + 0x38);
            *(s8 *)(d + 0x24) = *(s8 *)(s + 0x24);
            d[0x13C] = 1;
        } else {
            d[0x13C] = 0;
        }
    } else {
        func_003DAA40(d);
    }
}

typedef struct { s8 b0; u8 b1; u8 b2; u8 b3; u8 pad4[3]; u8 b7; f32 f8, fC; } G;
extern G *D_004C299C;
extern s16 D_00464300[];

typedef struct { u8 pad[0x18]; u8 *src; u8 pad1c[0x34 - 0x1C]; f32 f34, f38; } A37;

static void func_0037F2C0(u8 *p) {
    A37 *a = (A37 *)p;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x34) += D_004C299C->f8;
    *(f32 *)(p + 0x38) += D_004C299C->fC;
    if (*(s16 *)(p + 0x140) == 0) {
        a->f34 += 1.6666666269302368f * (f32)D_00464300[D_004C299C->b0];
    } else {
        a->f34 -= 1.6666666269302368f * (f32)D_00464300[D_004C299C->b0];
    }
}

#define SRC (*(u8 **)(p + 0x18))
void func_0037F630(u8 *p) {
    extern void func_0037F120(u8 *);
    u32 t = p[4];
    p[4] = t + 1;
    *(W199S *)(p + 0xEC) = *(W199S *)(SRC + 0xEC);
    p[0x13C] = 1;
    p[2] = SRC[2];
    p[1] = SRC[1];
    *(float *)(p + 0x50) = *(float *)(SRC + 0x50);
    *(float *)(p + 0x54) = *(float *)(SRC + 0x54);
    p[0x1B7] = SRC[0x1B7];
    p[0x1B8] = SRC[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(SRC + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(SRC + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(SRC + 0x24);
    if (p[1] != SRC[1]) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        p[0x13C] = 0;
        p[0x24] = 0;
        D_004C299C->b7 = 0;
        D_004C299C->b0 = 0;
        *(s16 *)(p + 0x1C) = 1;
        p[0x22] = 0xC;
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        D_004C299C->b2 = 1;
        D_004C299C->b3 = 1;
        func_0037F2C0(p);
        func_0037F120(p);
    }
}
#undef SRC
