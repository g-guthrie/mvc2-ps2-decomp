typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


typedef struct { s32 pad[0xB7]; s32 f2DC; s32 f2E0; } S1;
void func_00176160(S1 *p, s32 a, s32 b, s32 c);
void func_002DAB90(S1 *p) {
    s32 n;
    if (--p->f2DC == 0) {
        p->f2DC = 2;
        n = p->f2E0 + 1;
        p->f2E0 = n;
        if (n > 2) p->f2E0 = 0;
        func_00176160(p, 0, p->f2E0, 1);
    }
}

typedef struct { u8 pad[0x5C]; s32 f5C; s32 f60; u8 pad2[4]; s32 f68; s32 f6C; } S6;
s8 func_00175700(void *p);
void func_001843A0(S6 *p);
void func_002CFA20(S6 *p);
extern u32 D_00583BB0[][2];
u8 func_0032D620(u32 *out, s8 b);
u32 func_0032D6D0(u8 *a, u8 b) {
    u32 m;
    u8 r = func_0032D620(&m, ((s8 *)a)[0x540]);
    u32 *row = D_00583BB0[b];
    u32 v = row[r];
    return v & m;
}

typedef struct { u8 b0; u8 b1; u8 b2; } T1;
typedef struct { u8 p0[7]; u8 f7; u8 p1[0x138]; s16 f140; u8 p2[0xA4]; s8 f1E6; u8 p3[0xD1]; T1 f2B8; } S7;
s8 func_00175700(void *p);
void func_001757E0(void *p, s32 a, s32 b);
void func_001F4A50(S7 *a) {
    T1 *t = &a->f2B8;
    if (func_00175700(a) < 0) {
        u32 n = a->f7;
        a->f7 = n + 1;
        t->b2 = 0;
        a->f140 = a->f140 ^ 1;
        a->f1E6 = (s8)a->f140;
        func_001757E0(a, 15, 0x3A);
    }
}

extern s32 D_004F1CB8[];
void func_0016CED0(void *a);
void func_0022A530(u8 *a) {
    u32 n;
    s16 v;
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x1FE] = 1;
    a[0x201] = 2;
    a[0x209] = 2;
    v = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = v;
    if (v <= 0) {
        n = a[6];
        a[6] = n + 1;
        *(s16 *)(a + 0x1C) = 0x40;
        *(s16 *)(a + 0x1E) = 0;
        func_0016CED0(a);
        D_004F1CB8[0] = 2;
        func_001757E0(a, 15, 10);
    }
}

void func_003BD800(void *a);
void func_00175910(void *a, s32 b, s32 c, s32 d);
void func_001E7F60(void *a);
void func_003BC650(u8 *a) {
    u8 *t = *(u8 **)(a + 0x18);
    if (t[0x169] != 0xB || t[0x168] != 1) {
        func_003BD800(a);
    } else {
        if ((s8)t[0x151] < 0) {
            *(float *)(a + 0x34) = *(float *)(t + 0x34);
            *(float *)(a + 0x38) = *(float *)(t + 0x38);
            a[0x13C] = 1;
            func_00175910(a, 0x17, 6, (s8)t[0x151] & 0x7F);
            func_001E7F60(a);
        } else {
            a[0x13C] = 0;
        }
    }
}
