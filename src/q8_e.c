typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G4;
extern G4 *D_004C2794;

void func_00324AB0(u8 *p) {
    extern void func_00185490();
    extern void func_00183D10();
    extern void func_001E15A0();
    extern void func_001757E0();
    u32 t = p[6];
    p[6] = t + 1;
    p[0x216] = 0x80;
    func_00185490(p);
    func_00183D10(p);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    p[0x1B5] = 0x7C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001E15A0(p);
    func_001757E0(p, 0x16, 5);
}



void func_00364BB0(u8 *p, u8 *q) {
    extern s8 func_00175700();
    extern void func_001E3210();
    extern void func_001757E0();
    f32 a, b;
    if (func_00175700(p) < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        if (*(s32 *)(p + 0xD0) != 0 && p[0x23] == 0) {
            func_001E3210(p, 0x1A);
        }
        a = *(f32 *)(q + 0x34);
        b = *(f32 *)(p + 0x34);
        if (!(b < a)) {
            *(s16 *)(p + 0x140) = 0;
            *(u32 *)(p + 0x5C) = 0xC0D55555;
        } else {
            *(s16 *)(p + 0x140) = 1;
            *(u32 *)(p + 0x5C) = 0x40D55555;
        }
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x17, (u8)(*(s32 *)(p + 0xD0) + 0x4F));
    }
}
