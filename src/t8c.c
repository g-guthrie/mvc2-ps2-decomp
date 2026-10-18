/* t8 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_001FED30();
extern void func_00183D10();
extern void func_00175C00();
extern void func_001757E0();
extern void func_002004B0();
extern void func_00175700();
extern void func_0035ACA0();
extern void func_0035A7B0();
extern u32 D_004C2794;
extern f32 D_004F1FD0[];
typedef struct { float x, y, z; } Float3;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003359E0();
extern void func_00335640();
extern u32 D_004C283C;
extern Float3 D_004B7F30[];
extern void func_001266A0();
extern void func_0015D010();
extern void func_0018C6E0();
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_0044FBA0[];
extern void func_0036A8D0();
extern s32 func_00174170();
extern f32 D_00583C88[];
extern f32 D_00583C8C[];
extern f32 D_00583C90[];

void func_0035A1E0(u8 *a, u8 *b) {
    u32 t = a[5];
    u8 *q = *(u8 **)(a + 0x18);
    a[5] = t + 1;
    *(f32 *)(a + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(a + 0x38) = 137.142853f + D_004F1FD0[0];
    *(u32 *)(a + 0x5C) = 0;
    *(u32 *)(a + 0x68) = 0;
    *(u32 *)(a + 0x60) = 0xC1892492;
    *(u32 *)(a + 0x6C) = 0;
    a[0x169] = 0x17;
    a[0x168] = 3;
    func_001757E0(a, a[0x169], a[0x168]);
    func_0035ACA0(a, b);
    if (*(s8 *)(a + 0x13C) != 0) func_0035A7B0(a, b);
}

void func_00378530(u8 *a, u8 *b) {
    u8 *q = b + 0x2B8;
    u32 t;
    if (a[6] == 0) {
        *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
        *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
        *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
        *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
        if (*(f32 *)(a + 0x38) <= *(f32 *)(b + 0x430)) {
            t = a[6];
            a[6] = t + 1;
        }
    } else {
        *(f32 *)(a + 0x118) -= 0.1f;
        if (*(f32 *)(a + 0x118) <= 0.0f) {
            t = a[4];
            a[4] = t + 1;
            q[4] = 0;
        }
    }
}

void func_00258190(u8 *p) {
    f32 z = 0.0f;
    s16 v;
    u32 t;
    if (*(f32 *)(p + 0x60) < z) {
        t = p[7];
        p[7] = t + 1;
        func_00175700(p);
        return;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        func_0036A8D0(p, 1);
        func_0036A8D0(p, 2);
        *(s16 *)(p + 0x1C) = 6;
    }
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x151) == 0) func_00175700(p);
}

void func_00338B30(u8 *p) {
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s16 *)(p + 0x1C) > 0x64) {
        p[4] = 0;
        *(s16 *)(p + 0x1C) = 0;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x3C) = *(f32 *)(p + 0x64);
        *(f32 *)(p + 0x34) += D_00583C88[0] * *(s16 *)(p + 0x1C);
        *(f32 *)(p + 0x38) += D_00583C8C[0] * *(s16 *)(p + 0x1C);
        *(f32 *)(p + 0x3C) += D_00583C90[0] * *(s16 *)(p + 0x1C);
    }
}

void func_0025B9D0(u8 *p) {
    f32 z = 0.0f;
    f32 *a;
    f32 *d;
    f32 *c;
    f32 *e;
    u32 t;
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    d = (f32 *)(p + 0x60);
    e = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) < z) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *a = z;
        *d = z;
        *c = z;
        *e = z;
        *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
    }
    if (*(s8 *)(p + 0x151) != 1) func_00175700(p);
}

void func_002FC4F0(u8 *a, u8 *b) {
    u32 t;
    if ((b[1] & 3) == 0) {
        if ((func_00174170() & 0x3F) == 0) {
            if (a[5] == 0) {
                switch (a[0x1E4]) {
                case 0:
                case 1:
                case 2:
                case 6:
                case 10:
                case 11:
                    break;
                default:
                    return;
                }
                t = b[2];
                b[2] = t + 1;
                b[0] = 0;
            }
        }
    }
}
