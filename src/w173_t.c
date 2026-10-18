typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G212850;
extern G212850 *D_004C2794;

void func_00212850(u8 *p, u8 *q)
{
    extern void func_00175C00(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001861B0();
    extern void func_00183D10(u8 *);
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_00175C00(p, 0);
    func_00185490(p);
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x5C) /= 16.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 64.0f;
        *(u32 *)(p + 0x68) = 0;
        func_001757E0(p, 0x15, 0x1B);
    } else {
        func_001861B0(p);
        func_00183D10(p);
        p[0x20D] = 0;
        func_001757E0(p, 0x15, 9);
    }
    p[0x1B5] = 0x36;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    q[7] = 0;
    q[6] = 0;
}
