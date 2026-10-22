typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0019F7A0(u8 *p, u8 *q) {
    extern void func_001757E0();
    s32 v = 0x2000;
    f32 a, b;
    *(s8 *)(p + 0x31) = -2;
    if (*(s16 *)(p + 0x140) == 0) v = -0x2000;
    a = 1.6666666269302368f * (f32)v;
    p[0x13C] = 1;
    b = 216.42855834960938f;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + a / 256.0f;
    *(f32 *)(p + 0x38) = b + *(f32 *)(q + 0x38);
    func_001757E0(p, 0x17, 1);
}

void func_001DC350(u8 *p, u8 *q) {
    extern void func_00175670();
    extern void func_001DC0F0(u8 *, u16, f32, f32);
    u32 t;
    u16 i;
    f32 x, y;
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        t = p[4];
        p[4] = t + 1;
        for (i = 0; i < 3; i++) {
            x = *(f32 *)(p + 0x34); y = 8.571428298950195f + *(f32 *)(p + 0x38); func_001DC0F0(p, p[0x21] + 0x100, x, y);
        }
    }
}

void func_002A4570(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    u32 x;
    f32 f, z = 0.0f;
    if ((s8)func_00175700(p) >= 0) {
        x = p[0x15B];
        f = (f32)x;
        if (f != z) {
            p[0x15B] = 0;
            f *= 1.6666666269302368f;
            if (p[0x1E6] == 0) f *= -1.0f;
            *(f32 *)(p + 0x34) += f;
        }
    } else {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}

typedef struct { f32 x, y, z; } V3;

void func_0034F970(u8 *p) {
    extern s32 func_00175700();
    extern int func_00174470(const void *);
    extern void func_0034FA60();
    extern void func_0015B200();
    extern void func_001E7F60();
    V3 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (func_00174470(p) == 0) {
        func_0034FA60(p);
        return;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        v = *(V3 *)(p + 0x34);
        v.y += 17.14285659790039f;
        func_0015B200(p, &v, 1, 0xC9);
        func_0034FA60(p);
    }
    func_001E7F60(p);
}
