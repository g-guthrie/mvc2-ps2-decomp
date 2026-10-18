typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


extern s8 D_004C2860;
extern u8 *D_004C2840;
extern void (*D_004C1E40[2])(u8 *);
extern void (*D_004BFE38[2])(void);
extern s32 func_0012ABC0(s32, s32);
extern s32 func_0012A990(s32, s32, s32, s32);
extern void func_0020D2A0(void);
extern void func_003D3080(void *);
extern void func_00396EC0(u8 *, u8 *);

void func_0012A170(u8 *p) {
    D_004C2860 = func_0012A990(func_0012ABC0(3, 0), D_004C2860, 3, 2);
    p[2] = D_004C2860;
}

void func_0020C230(u8 *p, u8 *q) {
    if (q[9] != 0) func_0020D2A0();
    else D_004BFE38[p[7]]();
}


