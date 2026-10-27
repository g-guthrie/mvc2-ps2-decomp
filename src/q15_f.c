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

extern f32 D_004C9F54[2], D_004F1FF0[2], D_004F1F50[2];

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

extern s32 func_001E7F60(u8 *);

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

extern void *func_00194100(u8 *);

extern void func_00194990();

extern void func_00175670();

extern void func_003B3880();

extern void func_003B3870();

extern int func_00174470(const void *);

extern u8 func_001898E0();

extern s8 D_004F7FC8[];

typedef struct { u8 a; s8 b; } C189;

typedef struct { u8 p0[0x34]; f32 f34; u8 p1[0x434 - 0x38]; s16 s434; } Q2B;

extern void func_0011D8F8();

extern void func_0018EA00();

extern void func_0018E810();

extern void func_001E3A10();

extern void func_00158C70();

extern u8 *func_003DA750();

extern void func_00383C90();

extern s16 D_004B5712[], D_004B5710[];

typedef struct {
    u8 p0[0x34];
    f32 f34, f38;
    u8 p1[0x140 - 0x3C];
    s16 s140;
} B3D;

typedef struct N52 { u8 p0[0xC]; struct N52 *next; } N52;

extern N52 *D_004D36AC;

extern u8 D_00444800[];

extern void func_00123090();

extern void func_00151A20();

extern void func_001520E0();

extern void func_00417AE0();

extern void func_00417FE0();

extern void func_00153AB0();

void func_001526A0(void) {
    N52 *s;
    func_00123090();
    func_00151A20(0xD);
    func_001520E0(0xD);
    func_00417AE0(4, D_00444800);
    func_00417FE0(0);
    s = D_004D36AC;
    if (s != 0) do {
        func_00153AB0((u8 *)s + 0xEC, 0);
        s = s->next;
    } while (s != 0);
}
