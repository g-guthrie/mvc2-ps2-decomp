typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G94;
extern G94 *D_004C2794;
extern int func_001757E0(void *, int, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_00175C00(u8 *, s32);


void func_002CED00(u8 *p) {
    u32 t = p[6];
    s16 *e;
    p[6] = t + 1;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    func_00185490(p);
    func_00183D10(p);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    p[0x1B5] = 0x49;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    e = (s16 *)((p[2] << 1) + (u32)D_004C2794);
    e[0x3E] = e[0x3E] + 1;
    func_001757E0(p, 0x16, 0);
}





void func_002F1530(u8 *p) {
    extern void func_00175C00(u8 *, s32);
    extern int func_001757E0(void *, int, int);
    u32 t = p[6];
    p[6] = t + 1;
    func_00175C00(p, 0);
    p[0x20D] = 2;
    *(f32 *)(p + 0x38) += 137.14285278320312f;
    {
        f32 z = -30.0f;
        if (p[0x1E6] != 0) z = -z;
        *(f32 *)(p + 0x5C) = z;
    }
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xBE892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x3B;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x15, 0x26);
}
