typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;

s32 func_0025C240(u8 *p) {
    if (p[0x20D] != 2) {
        return 1;
    }
    if (p[0x210] == 0) {
        if (*(s8 *)(p + 0x1E8) != 0) {
            return 0;
        }
        *(s8 *)(p + 0x1E8) += 1;
    }
    return 1;
}

extern s32 func_00175700(void *p);
extern void func_001830D0(void *p, u32 *v, s32 a, s32 b);

void func_0022A8C0(u8 *p) {
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 v[4];
        u32 t = p[6] + 1;
        p[6] = t;
        p[0x151] = 0;
        v[0] = 0x422D5555;
        v[1] = 0x42F00000;
        func_001830D0(p, v, 1, t);
    }
}

extern void func_001266A0(void *p, s32 a, s32 b);
extern void func_001757E0(void *p, s32 a, s32 b);

void func_002D0890(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    *(u8 **)(q + 0x1C8) = p;
    q[0x20A] = 1;
    q[0x20D] = 2;
    func_001266A0(p, 0, 0);
    q[0x1B5] = 0x22;
    q[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
    func_001757E0(p, 0xF, 2);
}

void func_00374390(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0xD4) < *(f32 *)(p + 0x38))) {
        u32 t;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0xD4);
        t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 5;
    }
}

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern s16 D_004C27A4;
extern void func_003B81F0(void);

s32 func_003B8170(u8 *p) {
    u8 *r;
    if (D_004C27A4 < 2) {
        return 0;
    }
    r = func_003DA750(0, 1, 1);
    *(void **)(r + 0x10) = func_003B81F0;
    *(u8 **)(r + 0x18) = p;
    *(u32 *)(r + 0x14) = *(u32 *)(p + 0x14);
    r[1] = p[1];
    *(s16 *)(r + 0x26) = 0x3502;
    r[0x20] = 3;
    r[0x21] = 0;
}
