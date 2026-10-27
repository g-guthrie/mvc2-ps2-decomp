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
extern s32 func_00118FA8(f32 x);

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


void func_00252440(u8 *p) {
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        f32 f;
        u32 t = p[6];
        p[6] = t + 1;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) f = -4.166666508f;
        else f = 4.166666508f;
        *(f32 *)(p + 0x5C) = f;
    }
}

void func_003C28B0(u8 *p) {
    s16 *q = (s16 *)(p + 0xD0);
    *(f32 *)(p + 0x34) = 320.0f + D_004F1FC8;
    q[1] = func_00118FA8(D_004F1FD4 - 274.28570556640625f);
    *(f32 *)(p + 0x38) = q[0] + q[1];
}

void func_002528A0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        f32 f;
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 2;
        if (p[0x1E6] != 0) f = -10.0f;
        else f = 10.0f;
        *(f32 *)(p + 0x5C) = f;
        *(s32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x411A4924;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}
