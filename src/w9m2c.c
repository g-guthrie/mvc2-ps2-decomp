typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003B7EB0(void *p);
extern void (*D_004C2038[2])(void *);
void func_003B7D10(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s16 *)(p + 0x1E) != *(u8 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_003B7EB0(p);
    } else {
        D_004C2038[p[5]](p);
    }
}

extern u8 *D_004C2840;
extern s32 D_004C2B50;
extern s32 func_00401920(s32 a);
extern void func_004026B0(s32 a, s32 b);
extern void func_00401868(s32 a);
extern void func_00123760(void);
extern void func_001E3CE0(s32 n);
extern void func_00145160(void *p);
void func_00145FB0(u8 *p) {
    if (*(s32 *)(p + 0xDC) != *(s16 *)(D_004C2840 + 0xC)) {
        p[5] = 0;
        if (*(s32 *)(p + 0xDC) > *(s16 *)(D_004C2840 + 0xC)) {
            p[6] = 0;
            func_001E3CE0(0x3F);
        }
        if (*(s32 *)(p + 0xDC) < *(s16 *)(D_004C2840 + 0xC)) {
            p[6] = 1;
        }
    }
    func_00145160(p);
    *(s32 *)(p + 0xDC) = *(s16 *)(D_004C2840 + 0xC);
}

typedef struct { u8 b[4]; } B4;
extern B4 D_004D1860[];
extern u8 D_004C2A28;
extern u8 D_004C2A24;

extern void func_00175C00(void *p, s32 a);
extern void func_00185490(void *p);
static void func_00213FD0(u8 *p) {
    *(s32 *)(p + 92) = 0x41555555;
    *(s32 *)(p + 104) = 0xBED55555;
    if (p[486] == 0) {
        *(f32 *)(p + 92) = -*(f32 *)(p + 92);
        *(f32 *)(p + 104) = -*(f32 *)(p + 104);
    }
    *(s16 *)(p + 868) = 0;
    *(s16 *)(p + 870) = 0;
    *(s16 *)(p + 28) = 0;
}
extern void func_0018C4B0(void *p, s32 a);
extern void func_00183D10(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern u8 *D_004C2794;
void func_00214020(u8 *p) {
    u32 t = p[6];
    s16 *h;
    p[6] = t + 1;
    p[0x20D] = 0;
    func_00175C00(p, 0);
    func_00185490(p);
    func_00213FD0(p);
    func_0018C4B0(p, 10);
    p[0x1B5] = 0x3B;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    h = (s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C);
    *h = *h + 1;
    func_00183D10(p);
    func_001757E0(p, 0x14, 9);
}

extern void func_003A7B10();
extern void (*D_004C1EF0[2])();
void func_003A7070(u8 *p, u8 *q) {
    if (q[0x169] != 0x16) {
        func_003A7B10();
    } else if (q[5] != 0) {
        func_003A7B10();
    } else {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
        if (*(s8 *)(p + 0x24) > 7) *(s8 *)(p + 0x24) = 7;
        if (*(s8 *)(p + 0x24) < 0) *(s8 *)(p + 0x24) = 0;
        D_004C1EF0[p[5]]();
    }
}
