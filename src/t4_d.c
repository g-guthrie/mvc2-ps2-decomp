typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;

extern void func_003B7FC0();
extern void func_00175700();
extern void func_001757E0(void *p, s32 a, u8 b);
extern void func_003B7A20();
extern void func_001E7F60();

void func_003B7DB0(u8 *p) {
    u8 *q;
    s16 v;
    u32 t;
    s32 r;
    func_003B7FC0(p);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    q = *(u8 **)(p + 0x18);
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[5];
        p[5] = t + 1;
        if (p[0x20] != 0) {
            r = 7;
        } else {
            r = (u8)(q[0x1B7] * 2 + 6);
        }
        func_001757E0(p, 0x15, r);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_003B7A20(p);
    }
    func_001E7F60(p);
}

extern f32 *D_004C2974;
extern u8 *D_004C2978;

void func_00367BB0(u8 *p) {
    s16 v = *(s16 *)(p + 0x1E);
    u32 t;
    if (v != 0) {
        v = v - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v != 0) return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *D_004C2974) {
        t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *D_004C2974;
        *(u32 *)(p + 0x118) = 0x3F800000;
        D_004C2978[0xD] = 1;
    }
}
