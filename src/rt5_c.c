typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G_c;
extern G_c *D_004C2794;
void func_00303230(u8 *p, u8 *q) {
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_001E3210(u8 *, s32);
    extern void func_00303340(u8 *, u8 *);
    u32 t = p[6];
    p[6] = t + 1;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = 0x33;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x15, p[0x1B7] + 6);
    *(s16 *)(p + 0x1C) = 4;
    if (p[0x1B7] == 0) {
        *(s16 *)(p + 0x1E) = 8;
    } else {
        *(s16 *)(p + 0x1E) = 0xC;
    }
    p[0x21] = 0;
    func_001E3210(p, 0x15);
    func_00303340(p, q);
}
