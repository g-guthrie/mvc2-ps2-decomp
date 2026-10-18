typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));
extern void func_00186A60(u8 *, s32);
void func_002D5FD0(u8 *p) {
    p[5] = 0; p[7] = 0; p[6] = 0; p[0x1B7] = 1;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0: p[0x1FD] = 1; break;
    case 1: p[0x1FD] = 3; p[0x1B7] = 0; break;
    case 2: p[0x1FD] = 0xF; break;
    }
    func_00186A60(p, 0x15);
}
void func_003089E0(u8 *p) {
    p[5] = 0; p[7] = 0; p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0: p[0x1FD] = 0; p[0x1B7] = 0; break;
    case 1: p[0x1FD] = 5; p[0x1B7] = 0; break;
    case 2: p[0x1FD] = 2; p[0x1B7] = 0; break;
    }
    func_00186A60(p, 0x15);
}
void func_0030C560(u8 *p) {
    p[5] = 0; p[7] = 0; p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0: p[0x1FD] = 2; p[0x1B7] = 0; break;
    case 1: p[0x1FD] = 3; p[0x1B7] = 1; break;
    case 2: p[0x1FD] = 10; p[0x1B7] = 1; break;
    }
    func_00186A60(p, 0x15);
}
extern void func_001820A0(u8 *);
extern s32 func_001864A0(u8 *);
extern void func_001865B0(u8 *);
extern s8 func_00175700(u8 *);
extern void func_00184540(u8 *);
void func_002D5E40(u8 *p) {
    func_001820A0(p);
    if (func_001864A0(p)) {
        func_001865B0(p);
    } else {
        if (func_00175700(p) < 0) { p[0x1E7] = 1; func_00184540(p); }
    }
}
extern void func_003BE2C0(u8 *);
void func_003BDFC0(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) { u32 t = p[5]; p[5] = t + 1; *(s16 *)(p + 0x1C) = 0x30; *(s16 *)(p + 0x1E) = 0; }
    }
    func_003BE2C0(p);
}
extern void func_001E3A70(u8 *);
extern void func_00183D50(u8 *);
void func_002EB200(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        func_001E3A70(p);
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        { u32 t = p[5]; p[5] = t + 1; }
        func_00183D50(p);
    }
}
extern void func_00175670();
extern s32 func_00174470();
void func_001B44D0(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175670(p);
    if (!func_00174470(p)) { p[4] = 2; return; }
}
