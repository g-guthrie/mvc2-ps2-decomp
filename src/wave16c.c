typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, s32, u8);
extern s8 *D_004C29C4;
extern s8 *D_004C29C0;

void func_0038E740(u8 *p) {
    if (*D_004C29C4 != *D_004C29C0) {
        u32 a = 0;
        u32 n;
        *D_004C29C4 = *D_004C29C0;
        n = *D_004C29C4;
        n = (u8)(n * 3);
        if (((u8 *)D_004C29C4)[6] != 0) a = ((u8 *)D_004C29C4)[1];
        func_001757E0(p, 25, a + n);
    }
}

extern u8 D_004C1308[8];
extern void func_002F48D0(u8 *, u16 *);

void func_002F4860(u8 *p, u16 *q) {
    u32 t = p[6];
    p[6] = t + 1;
    ((s8 *)p)[433] = -128;
    p[513] = 0;
    func_001757E0(p, 21, D_004C1308[*q]);
    func_002F48D0(p, q);
}

extern u8 *D_004C2704;
extern u8 *D_004C2700;
extern void (*D_0044C490[4])(void);
extern void (*D_0044C4A0[4])(void);

void func_001BF460(u8 *p) {
    if (p[32] == 0) {
        D_004C2704 = p + 208;
        D_0044C490[p[4]]();
    } else {
        D_004C2704 = p + 208;
        D_004C2700 = *(u8 **)(p + 24) + 208;
        D_0044C4A0[p[4]]();
    }
}
