typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G2794;
extern G2794 *D_004C2794;

void func_00264C10(u8 *p) {
    extern void func_00185490();
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183D10(u8 *);
    extern void func_00175C00(u8 *, s32);
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_0018C4B0(p, 5);
    p[0x1B5] = 0x30;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x5C) /= 16.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 64.0f;
        *(u32 *)(p + 0x68) = 0;
        func_001757E0(p, 0x15, 1);
    } else {
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D10(p);
        func_001757E0(p, 0x15, 0);
        func_00175C00(p, 0);
    }
}
