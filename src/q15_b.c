typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s32 func_001345B0();

extern s32 func_00134120();

typedef struct { u8 pad[5]; u8 f5; } S134;

extern s32 func_00189310();

extern u8 D_00453570[];

extern f32 D_004F1FF4, D_004C9F58, D_004C9F54, D_004F1FF0, D_004F1F54, D_004F1F50;

extern void func_0016B0C0();

extern s32 func_00174170();

extern void func_00174A40();

typedef struct {
    u8 p0[0x34];
    f32 f34, f38, f3c;
    u8 p1[0x5C - 0x40];
    f32 f5c, f60, f64, f68, f6c;
    u8 p2[0x430 - 0x70];
    f32 f430;
} Obj;

extern s8 func_00175700();

extern void func_001757E0();

extern void func_00175C00();

extern void func_003DAA40();

extern void func_001E7F60();

extern void func_001843A0();

extern void func_00183920();

extern void func_001E3710();

extern void func_001830D0();

extern void func_001266A0();

extern void func_0018C6E0(void *);

extern void func_0015D010();

extern u8 D_00459C50[];

extern s32 func_0018A990();

extern void func_002CAFC0();

extern void func_00186A60();

extern void func_00183d50();

extern s32 func_00194100();

extern void func_00194990();

extern void func_00175670();

extern void func_003B3880();

extern void func_003B3870();

extern int func_00174470(const void *);

extern u8 func_001898E0();

extern s8 D_004F7FC8[];

typedef struct { u8 a; s8 b; } C189;

extern void func_0011D8F8();

extern void func_0018EA00();

extern void func_0018E810();

extern void func_001E3A10();

extern void func_00158C70();

extern u8 *func_003DA750();

extern void func_00383C90();

s32 func_00254DA0(u8 *p) {
    if (*(s16 *)(p + 0x2B8) > 0) return 0;
    if (func_00189310(p, D_00453570, p + 0x3A0) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    p[0x26C] = 5;
    return 1;
}

s32 func_002C5370(u8 *p) {
    u8 *s = p + 0x2B8;
    if (func_00189310(p, D_00459C50, p + 0x388) == 0) return 0;
    if (s[1] != 0) return 0;
    func_0018A990(p, p + 0x388);
    if (p[0x215] != 0) func_002CAFC0(p);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 0x15);
    return 1;
}
