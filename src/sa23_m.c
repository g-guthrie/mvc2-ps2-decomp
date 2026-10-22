typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 f7c[1]; } G4;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 x[49]; } B49;

extern G4 *D_004C2794;

static void func_003A2AE0(u8 *p, u8 *q) {
    u32 t = p[4];
    p[4] = t + 1;
    if (p[6] == 0) {
        *(B49 *)(p + 0xEC) = *(B49 *)(q + 0xEC);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    }
    p[0x1B1] = p[0x1B0] = 0x42;
    p[0x14C] = p[0x14D] = 0x16;
    p[0x14E] = p[0x14F] = 0x1E;
    p[0x1B4] = 0;
    p[0x13C] = 0;
    p[0x1B5] = 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
}


void func_003A2E20(u8 *p, u8 *src) {
    extern void func_001757E0(u8 *, s32, s32);
    extern s8 func_00175700(u8 *);
    extern void func_003DAA40(u8 *);
    extern void func_001E7F60(u8 *);
    extern s32 func_00174240(u8 *);
    u8 *o;
    s8 r;
    u32 t;
    o = *(u8 **)(p + 0x14);
    if (p[4] == 0) {
        func_003A2AE0(p, src);
        p[0x1B5] = 0x3A;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x13C] = 1;
        p[0x24] = *(s8 *)(src + 0x24);
        *(s8 *)(p + 0x31) = -4;
        *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
        if (p[0x21] != 0) {
            *(f32 *)(p + 0x38) = 8.0f + (334.2857055664f + *(f32 *)(o + 0xD0));
            p[0x22] = 0x15;
        } else {
            p[0x22] = 7;
        }
        func_001757E0(p, 0x16, p[0x22]);
    }
    r = func_00175700(p);
    if (p[5] == 0) {
        if (o[5] != 1) {
            t = p[0x22];
            p[0x22] = t + 1;
            func_001757E0(p, 0x16, p[0x22]);
            t = p[5];
            p[5] = t + 1;
        }
        r = 0;
    }
    if (r < 0) {
        func_003DAA40(p);
        return;
    }
    if (p[0x21] != 0) {
        func_001E7F60(p);
        if (func_00174240(p) != 0) {
            p[0x13C] = 1;
        } else {
            p[0x13C] = 0;
        }
    }
}
