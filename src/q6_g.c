typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G2794;
extern G2794 *D_004C2794;
extern u16 D_004C00A8[2];
extern u16 D_004C00B0[2];
typedef struct { f32 a, b, c, d; } E4;
extern E4 D_00451A20[];

void func_00229E90(u8 *p) {
    extern void func_00185490();
    extern void func_00183D10(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t = p[6];
    p[6] = t + 1;
    func_00185490(p);
    func_00183D10(p);
    p[0x1B5] = 0x30;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_0018C4B0(p, 0x10);
    {
        u32 i = p[0x1B7];
        E4 *q;
        *(u32 *)(p + 0x2E0) = *(u16 *)((u8 *)D_004C00A8 + i * 4);
        *(s16 *)(p + 0x1E) = *(u16 *)((u8 *)D_004C00B0 + i * 4);
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        q = &D_00451A20[p[0x1B7]];
        *(f32 *)(p + 0x60) = q->a;
        *(f32 *)(p + 0x6C) = q->b;
    }
    func_001757E0(p, 0x15, 0x2C);
}
