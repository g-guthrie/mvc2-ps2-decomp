typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00174170(void);
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_003DAA40(void);
extern void func_00174910(void *p, s32 a);
extern s32 func_00175700();
extern s32 func_00174240(void *p);
extern void func_001E7F60(void *p);
extern u8 *func_003DA750();
extern void func_00183d50();
extern void func_0019F4F0(void);
extern u8 D_004C1730[2][4];
typedef struct { u8 p0[0x34]; f32 f34; } O;
extern O *D_004CAE80[][20];
extern s32 func_00189310();
extern void func_0018A990(u8 *p, u8 *q);
extern void func_00186A60(void *p, s32 a);
extern u8 D_0045D710[];

void func_0022C620(u8 *p) {
    s32 r;
    if (p[0x216] != 0x80) {
        r = func_00174170();
        if ((r & 3) == 0) {
            if ((r & 0x80) != 0) { p[0x168] = 10; } else { p[0x168] = 11; }
            func_001757E0(p, 0, p[0x168]);
        }
    }
}

s32 func_0014C1D0(s32 i, s32 j) {
    f32 f = D_004CAE80[i][j]->f34;
    if (f == -18.0f) return 0;
    if (f == -7.5f) return 1;
    if (f == 0.0f) return 2;
    if (f == 7.5f) return 3;
    return 4;
}

s32 func_00317110(u8 *p) {
    if (func_00189310(p, D_0045D710, p + 0x3A0) == 0) return 0;
    if (*(s8*)(p + 0x2BF) != 0) return 0;
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    *(s8*)(p + 0x1FD) = 8;
    func_00186A60(p, 0x15);
    if (*(s8*)(p + 0x539) == 0) {
        *(s16*)(p + 0x2C0) = p[0x1B7];
    } else {
        *(s16*)(p + 0x2C0) = p[0x212];
    }
    return 1;
}
