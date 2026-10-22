typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;



void func_00362350(u8 *p) {
    extern void func_00175700();
    extern int func_00174470(const void *);
    extern void func_001E7F60();
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (func_00174470(p) == 0 || (v = *(s16 *)(p + 0x1C) - 1, *(s16 *)(p + 0x1C) = v, v == 0)) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        f32 k = 0.0099999998f;
        *(f32 *)(p + 0x50) += k;
        *(f32 *)(p + 0x54) += k;
        *(f32 *)(p + 0x118) = 0.03333333507f * (f32)*(s16 *)(p + 0x1C);
        func_001E7F60(p);
    }
}

void func_001C5BC0(u8 *p, u8 *q) {
    extern void func_00175700();
    u8 *r = q + 0x2B8;
    if (q[0x2C3] == 0) {
        p[7] = 5;
        p[0] = 1;
        p[0x13C] = 1;
        if (*(s16 *)(p + 0x140) == 0) {
            *(u32 *)(p + 0x5C) = 0xC0D55555;
        } else {
            *(u32 *)(p + 0x5C) = 0x40D55555;
        }
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0;
        func_00175700(p);
        return;
    }
    if (r[0xA] == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0] = 0;
        p[0x13C] = 0;
    } else {
        f32 d = 8.0f;
        *(f32 *)(p + 0x34) += (*(f32 *)(q + 0x34) - *(f32 *)(p + 0x34)) / d;
        *(f32 *)(p + 0x38) += (85.71427917480469f + *(f32 *)(q + 0x38) - *(f32 *)(p + 0x38)) / d;
        func_00175700(p);
    }
}
