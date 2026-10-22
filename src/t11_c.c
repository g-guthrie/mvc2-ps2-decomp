typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct V3 { f32 x, y, z; } V3;

extern s32 D_004C283C;
extern f32 D_004F1F4C;
extern f32 D_004F1FE8;
extern u32 D_00463E80[];
extern s32 func_00175700();
extern void func_001757E0();
extern void func_002BD2D0();
extern void func_002BCF40();
extern void func_001C8FA0();
extern void func_001C8D60();
extern int func_00174470(const void *);
extern void func_003726F0();
extern void func_0018D930();
extern void func_001E7F60();
extern void func_003A0880();
extern void func_001E3710();

void func_001C8EF0(u8 *p) {
    if (*(*(u8 **)(p + 0x18) + 0x169) != 0x13 && p[0x20] == 1) {
        u32 t = p[4];
        p[4] = t + 1;
        func_001C8FA0(p);
    } else {
        func_001C8D60(p);
        if (p[0x20] != 1) {
            if ((s8)func_00175700() < 0) {
                u32 t = p[4];
                p[4] = t + 1;
                func_001C8FA0(p);
            }
        } else {
            func_00175700();
        }
    }
}

void func_00372640(u8 *p) {
    s32 r;
    ((void (*)())D_00463E80[p[6]])(p);
    r = func_00174470(p);
    if (r == 0) {
        p[4] = 2;
    } else if (*(s8 *)(p + 0x1B2) != 0) {
        func_003726F0(p);
    } else if (*(s8 *)(p + 0x1B3) != 0) {
        *(s8 *)(p + 0x1B3) = 0;
        func_003726F0(p);
        func_0018D930(p);
    } else {
        p[0x24] = 0xB;
        func_00175700(p);
        func_001E7F60(p);
    }
}

void func_002D2AD0(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700();
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 2, 3);
        func_001E3710(p, 0x34);
    }
}

extern void func_0015B200();
extern void func_001E3710();
extern void func_003B54E0();
extern void func_003B5530();

void func_003B5090(u8 *p, u8 *q) {
    u8 *o = *(u8 **)(q + 0x1DC);
    if (*(s8 *)(o + 0x211) != 0) {
        f32 v[4];
        u32 t;
        *(s16 *)(p + 0x1C) = 3;
        t = p[5];
        p[5] = t + 1;
        *(u8 **)(o + 0x1C8) = q;
        o[0x20A] = 1;
        o[0x20D] = 2;
        o[0x1B5] = 0x20;
        q[0x1B5] = 0x20;
        v[0] = *(f32 *)(o + 0x34);
        v[1] = *(f32 *)(p + 0x38);
        func_0015B200(o, v, 1, 0x89);
        func_001E3710(p, 0x49);
    } else {
        func_003B54E0(p);
    }
    func_003B5530(p, q);
}
