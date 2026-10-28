typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 m[16]; } M16;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0xC8]; f32 *c8; } PK;

extern s32 D_004C2658;
typedef union { u32 w; u16 h; } WH;
extern WH D_004CB0F0[];
extern WH D_004CB0F4[];
extern WH D_004CB0F8[];
extern f32 D_004F1F58[];
extern f32 D_004F1F5C[];
extern f32 D_004F1F60[];
extern s32 D_004F7FD8[];
extern double func_00119B08(s32);
extern double func_001195D0(double, double);
extern double func_00119858(double, double);
extern f32 dptofp(double);

void func_00151A90(u8 *p, s32 mode)
{
    extern void func_003DD260(M16 *);
    extern void func_003DDB20(M16 *, f32, f32, f32);
    extern void func_003DDB60(M16 *, f32, f32, f32);
    extern void func_003DDB70(M16 *, f32);
    extern void func_003DDC30(M16 *, f32);
    extern void func_003DDEC0(M16 *, f32, f32, f32);
    extern f32 func_003DE6F0(f32);
    extern void func_003DE160(M16 *, M16 *, M16 *);
    M16 a;
    M16 b;
    V3 v;
    u32 fl = *(u32 *)(p + 0xD0);
    f32 f20, f21, g20, g21;
    double h0;
    PK *pk;
    V3 *pv;
    f32 *py, *pz;

    if (D_004C2658 == 0) {
        func_003DD260(&a);
        if (fl & 0x10) {
            func_003DD260(&b);
            func_003DDB20(&b, *(f32 *)(p + 0x50), *(f32 *)(p + 0x54), *(f32 *)(p + 0x58));
            func_003DE160(&a, &a, &b);
        }
        if (fl & 0xE) {
            func_003DD260(&b);
            D_004CB0F0[0].w = *(u32 *)(p + 0x40);
            D_004CB0F4[0].w = *(u32 *)(p + 0x44);
            D_004CB0F8[0].w = *(u32 *)(p + 0x48);
            if (!(fl & 8)) D_004CB0F8[0].w = 0;
            if (!(fl & 4)) D_004CB0F4[0].w = 0;
            if (!(fl & 2)) D_004CB0F0[0].w = 0;
            h0 = func_00119B08(D_004CB0F0[0].h);
            f21 = dptofp(func_00119858(func_001195D0(6.283185307179586, h0), 65536.0));
            f20 = dptofp(func_00119858(func_001195D0(6.283185307179586, func_00119B08(D_004CB0F4[0].h)), 65536.0));
            func_003DDEC0(&b, f21, f20, dptofp(func_00119858(func_001195D0(6.283185307179586, func_00119B08(D_004CB0F8[0].h)), 65536.0)));
            func_003DE160(&a, &a, &b);
        }
        if (fl & 0x80) {
            g20 = D_004F1F5C[0] - *(f32 *)(p + 0x38);
            g21 = D_004F1F60[0] - *(f32 *)(p + 0x3C);
            func_003DD260(&b);
            func_003DDB70(&b, func_003DE6F0(-g20 / g21));
            func_003DE160(&a, &a, &b);
        }
        if (fl & 0x100) {
            g20 = D_004F1F58[0] - *(f32 *)(p + 0x34);
            g21 = D_004F1F60[0] - *(f32 *)(p + 0x3C);
            func_003DD260(&b);
            func_003DDC30(&b, func_003DE6F0(g20 / g21));
            func_003DE160(&a, &a, &b);
        }
        if (fl & 1) {
            switch (mode & 0xFF) {
            case 91: case 52: case 43: case 40: case 38: case 36: case 34: case 13: case 16: case 14: case 18: case 7: case 6: case 5:
                func_003DD260(&b);
                func_003DDB60(&b, *(f32 *)(p + 0x34), *(f32 *)(p + 0x38), *(f32 *)(p + 0x3C));
                func_003DE160(&a, &a, &b);
                break;
            case 8: case 9: case 10: case 11: case 17: case 19: case 20: case 21: case 22: case 23: case 24: 
            case 25: case 26: case 27: case 28: case 29: case 30: case 31: case 32: case 33: case 35: case 37: 
            case 39: case 41: case 42: case 44: case 45: case 46: case 47: case 48: case 49: case 50: case 51: 
            case 53: case 54: case 55: case 56: case 57: case 58: case 59: case 60: case 61: case 62: case 63: 
            case 64: case 65: case 66: case 67: case 68: case 69: case 70: case 71: case 72: case 73: case 74: 
            case 75: case 76: case 77: case 78: case 79: case 80: case 81: case 82: case 83: case 84: case 85: 
            case 86: case 87: case 88: case 89: case 90: 
                pv = &v;
                py = &v.y;
                pz = &v.z;
                *pv = *(V3 *)(p + 0x34);
                v.x *= 0.1f;
                *py *= 0.1f;
                *pz *= 0.1f;
                func_003DD260(&b);
                func_003DDB60(&b, v.x, v.y, v.z);
                func_003DE160(&a, &a, &b);
                break;
            }
        }
        if (D_004F7FD8[0] == 1) {
            if (*(u32 *)(p + 0xD0) & 0x10000) {
                if ((mode & 0xFF) == 13 || (mode & 0xFF) == 14 || (mode & 0xFF) == 18) {
                    if (*(s32 *)(p + 0xC8) == 0) {
                        func_003DD260(&b);
                        func_003DDB20(&b, 1.0f, 0.93f, 1.0f);
                        func_003DE160(&a, &a, &b);
                    }
                }
            }
        }
        if (fl & 0x4000) {
            b.m[0] = *(f32 *)(p + 0x88);
            b.m[1] = *(f32 *)(p + 0x8C);
            b.m[2] = *(f32 *)(p + 0x90);
            b.m[3] = *(f32 *)(p + 0x94);
            b.m[4] = *(f32 *)(p + 0x98);
            b.m[5] = *(f32 *)(p + 0x9C);
            b.m[6] = *(f32 *)(p + 0xA0);
            b.m[7] = *(f32 *)(p + 0xA4);
            b.m[8] = *(f32 *)(p + 0xA8);
            b.m[9] = *(f32 *)(p + 0xAC);
            b.m[10] = *(f32 *)(p + 0xB0);
            b.m[11] = *(f32 *)(p + 0xB4);
            b.m[12] = *(f32 *)(p + 0xB8);
            b.m[13] = *(f32 *)(p + 0xBC);
            b.m[14] = *(f32 *)(p + 0xC0);
            b.m[15] = *(f32 *)(p + 0xC4);
            func_003DE160(&a, &a, &b);
        }
        pk = (PK *)p;
        if (*(s32 *)(p + 0xC8) != 0) {
            b.m[0] = pk->c8[0];
            b.m[1] = pk->c8[1];
            b.m[2] = pk->c8[2];
            b.m[3] = pk->c8[3];
            b.m[4] = pk->c8[4];
            b.m[5] = pk->c8[5];
            b.m[6] = pk->c8[6];
            b.m[7] = pk->c8[7];
            b.m[8] = pk->c8[8];
            b.m[9] = pk->c8[9];
            b.m[10] = pk->c8[10];
            b.m[11] = pk->c8[11];
            b.m[12] = pk->c8[12];
            b.m[13] = pk->c8[13];
            b.m[14] = pk->c8[14];
            b.m[15] = pk->c8[15];
            func_003DE160(&a, &a, &b);
        }
        *(f32 *)(p + 0x88) = a.m[0];
        *(f32 *)(p + 0x8C) = a.m[1];
        *(f32 *)(p + 0x90) = a.m[2];
        *(f32 *)(p + 0x94) = a.m[3];
        *(f32 *)(p + 0x98) = a.m[4];
        *(f32 *)(p + 0x9C) = a.m[5];
        *(f32 *)(p + 0xA0) = a.m[6];
        *(f32 *)(p + 0xA4) = a.m[7];
        *(f32 *)(p + 0xA8) = a.m[8];
        *(f32 *)(p + 0xAC) = a.m[9];
        *(f32 *)(p + 0xB0) = a.m[10];
        *(f32 *)(p + 0xB4) = a.m[11];
        *(f32 *)(p + 0xB8) = a.m[12];
        *(f32 *)(p + 0xBC) = a.m[13];
        *(f32 *)(p + 0xC0) = a.m[14];
        *(f32 *)(p + 0xC4) = a.m[15];
    }
}
