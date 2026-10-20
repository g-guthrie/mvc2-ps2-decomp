typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;

extern s32 func_00175700();

static void func_002B5100(u8 *p) {
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (*(float *)(p + 0x60) * *(float *)(p + 0x6C) > 0.0f)
        *(float *)(p + 0x6C) = -1.607142806053161621f;
}

void func_002B62B0(u8 *p) {
    f32 z;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_002B5100(p);
    z = 0.0f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) <= z)) {
        u32 t = p[6];
        p[6] = t + 1;
    }
    func_00175700(p);
}

extern void func_00174910(void *p, s32 a);
extern void func_001E7F60(void *p);
extern s32 func_00174470(void *p);

void func_00361ED0(u8 *p, u8 *q) {
    u32 t;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    func_00174910(p, 0x320);
    if (*(s8 *)(p + 0x1B3) != 0) {
        t = p[4];
        p[4] = t + 1;
    } else {
        func_001E7F60(p);
        if (*(s8 *)(p + 0x1B2) != 0) {
            t = p[4];
            p[4] = t + 1;
        } else {
            if (func_00174470(p) == 0) {
                t = p[4];
                p[4] = t + 1;
            }
        }
    }
}

extern void func_00175670();
extern void func_001E0A30(void *p, void *q);

void func_001E09A0(u8 *p, u8 *q) {
    func_00175670(p);
    p[0x159] = 0x1A;
    if (*(s8 *)(p + 0x151) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    }
    if (*(u32 *)(p + 0xD0) == q[0x169]) {
        if (func_00174470(p) != 0) return;
    }
    func_001E0A30(p, q);
}

