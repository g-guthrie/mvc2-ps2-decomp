typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_i;
extern G_i *D_004C2794;

void func_002768D0(u8 *p)
{
    extern void func_0018C4B0();
    extern void func_00185490();
    extern void func_00175C00();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001B9D50(u8 *, s32);
    extern void func_00275A80();
    extern void func_00276A80(u8 *);
    u32 t;
    f32 a, b, c;
    t = p[6];
    p[6] = t + 1;
    if (p[0x269] != 3) func_0018C4B0(p, 5);
    if (p[0x20D] == 2) {
        func_00185490(p);
        func_00175C00(p, 0);
        if (p[0x1B7] != 0) func_001757E0(p, 0x15, 7);
        else func_001757E0(p, 0x15, 6);
        func_001B9D50(p, 1);
    } else {
        func_00275A80(p);
        if (p[0x1B7] != 0) func_001757E0(p, 0x15, 3);
        else func_001757E0(p, 0x15, 2);
        func_001B9D50(p, 0);
    }
    a = 16.0f;
    *(f32 *)(p + 0x5C) /= a;
    b = 8.0f;
    c = 64.0f;
    *(f32 *)(p + 0x60) /= b;
    *(f32 *)(p + 0x6C) /= c;
    *(u32 *)(p + 0x68) = 0;
    if (p[0x1B7] != 0) {
        p[0x1B5] = 0x45;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]] += 1;
    } else {
        p[0x1B5] = 0x38;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]] += 1;
    }
    func_00276A80(p);
}
