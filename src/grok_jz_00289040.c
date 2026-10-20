typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 a[1]; } G7C;
extern G7C *D_004C2794;

void residual_00289040(u8 *p)
{
    extern void func_002891F0();
    extern void func_00289390();
    extern void func_00185490();
    extern void func_00175C00();
    extern void func_0018C4B0();
    extern void func_001757E0();
    extern void func_00183D10();
    extern void func_00289130();
    u32 t;

    switch (p[0x20D]) {
    case 1:
        p[6] = 1;
        func_002891F0(p);
        return;
    case 2:
        p[6] = 2;
        func_00289390(p);
        return;
    }
    t = p[7];
    p[7] = t + 1;
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = 0x31;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->a[p[2]]++;
    func_0018C4B0(p, 5);
    func_001757E0(p, 0x15, 0);
    func_00183D10(p);
    func_00289130(p);
}
