typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;


extern f32 *D_004C2708;
static void func_001C88F0(u8 *p) {
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s16 *)(p + 0x140) != 0) *(f32 *)(p + 0x34) += D_004C2708[0];
    else *(f32 *)(p + 0x34) -= D_004C2708[0];
    *(f32 *)(p + 0x38) += D_004C2708[1];
}
extern void func_001C8AE0();
extern void func_00175700();
void func_001C8A90(u8 *p) {
    func_001C88F0(p);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x161) != 3) {
        func_001C8AE0();
    } else {
        func_00175700();
    }
}

extern void func_001E3710();
void func_00309350(u8 *p) {
    u8 *q = p + 0x2B8;
    u32 t = p[0x2BB];
    if (t != 0) q[3] = t - 1;
    t = q[9];
    if (t != 0) {
        t = t - 1;
        q[9] = t;
        if ((t & 0xFF) == 0) {
            func_001E3710(p, 0x3B);
        }
    }
}


extern u16 D_004F4484[];
extern void func_001E3CE0();
s32 func_00131750(s8 i) {
    s32 r;
    if ((D_004F4484[i * 10] & 0x100) == 0) {
        r = 0;
    } else {
        func_001E3CE0(3);
        r = 1;
    }
    return r;
}

extern void func_00175670();
extern void func_001C1330();
void func_001C0D20(u8 *p, u8 *q) {
    s8 v;
    func_00175670(p);
    func_001C1330(p, q);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 0;
    v = *(s8 *)(q + 0x151);
    if (v == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    } else if (v < 0) {
        p[0x13C] = 1;
    }
}
