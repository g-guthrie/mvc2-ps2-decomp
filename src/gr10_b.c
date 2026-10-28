typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gnb;
extern Gnb *D_004C2794;
typedef struct { f32 a, b, c, d; } Enb;
extern Enb D_004535C0[];

void residual_00259620(u8 *p) {
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    Enb *e;
    f32 v;
    u32 t = p[6];
    p[6] = t + 1;
    p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    e = D_004535C0; e += p[0x1B7];
    if (p[0x1E6]) v = -e->a; else v = e->a;
    *(f32 *)(p + 0x5C) = v;
    if (p[0x1E6]) v = -e->b; else v = e->b;
    *(f32 *)(p + 0x68) = v;
    *(f32 *)(p + 0x60) = e->c;
    *(f32 *)(p + 0x6C) = e->d;
    if (p[0x20D] != 2) {
        p[0x20D] = 0;
        func_00183D10(p);
    }
    p[0x23] = 0;
    func_001757E0(p, 0x15, p[0x1B7] + 2);
}
