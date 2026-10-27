typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_001E3710(void *p, s32 a);
extern void func_0033C6E0(void *p);
extern u8 *func_003DA750();
extern void func_003A5E90(void *p);
extern s32 func_0016A930(void *p, s32 a, s32 b);
extern void func_003DAA40(void *p);
extern void (*D_00442580[])(void *);

typedef struct { u8 pad[0x10]; u8 x, y; u8 pad2[0xA]; } E16;

extern s8 *D_004C2840;

typedef struct { s16 a, b; } P2;
extern P2 D_004CB010[];

extern void (*D_00442580[])(void *);
extern void func_003DAA40(void *p);

extern void func_003D77C0(void *p);

extern f32 D_004F1FC8;
extern f32 D_004F1FD4;

extern u8 *D_004C2794;
extern u8 D_004BFCB0[8];

extern s32 func_002B2EC0(void *p);
extern s32 func_002B2F20(void *p);
extern s32 func_002B2F80(void *p);
extern s32 func_002B2FE0(void *p);
extern s32 func_002B3050(void *p);

extern void (*D_004C1BC0[2])(void *);

extern void func_00175670(void *p);
extern void func_001975C0(void *p, void *q);

extern s32 func_00292DC0(void *p);
extern u8 D_00457970[];

extern void func_00175910(void *p, s32 a, s32 b, s32 c);
extern u8 D_0044B290[];

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B7CD8;
extern s32 D_004C283C;
extern void func_00333B00(void *p);

extern u8 *D_004C2930;
extern u8 *D_004C2934;
extern u8 *D_004C2938;
extern void (*D_00461E10[])(void *);
extern void (*D_00461E20[])(void *);

typedef struct { u8 b[0x5B8]; } E5B8;
extern E5B8 D_004F20B0[];
extern void func_00175C00(void *p, s32 a);

extern u8 D_00459C50[];
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_0018A990(void *p, s32 a);
extern void func_002CAFC0(void *p);

extern s16 D_004C27A4;
extern void func_001A3FF0(void *p);

extern s32 D_004C2838;
extern void func_001610C0(void *p);
extern void func_00161240(void *p);
extern void func_00170DF0(u32);
extern void func_00152550(void *, void (*)(u8 *));

typedef struct { s16 a, b; } P2s;
extern P2s D_0045F800[];
extern V3 D_0045F820[];
extern u32 func_00417A40(void);

extern void func_001843A0(void *p);
extern void func_00296FB0(void *p);


s32 func_00273B40(u8 *p) {
    if ((u8)func_001891F0(p, 7) == 0) return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 0x15);
    *(s32 *)(p + 0x2C0) = 0;
    return 1;
}

s32 func_0016A8B0(u8 *p, s32 a, u32 idx) {
    u8 *e = *(u8 **)(p + 0x184);
    e += (idx & 0x7F) * 28;
    if (func_0016A930(p, a, e[0x10]) != 0) return 1;
    return func_0016A930(p, a, e[0x11]) != 0;
}
