typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2840[1];
extern void (*D_004C21D0[2])();
extern void func_00172B00();
extern void func_003D2DC0();
extern s32 func_0012F930();

void func_003D2770(void) {
    u8 *p;
    func_00172B00();
    p = D_004C2840[0];
    p[0x84] = p[0x84] + 1;
    func_003D2DC0();
    if (func_0012F930(1) == 0) {
        D_004C21D0[*(s8 *)(D_004C2840[0] + 1)]();
    }
}

extern s32 func_001757E0();
extern s32 func_00175700();
extern s32 func_001841C0();
extern s32 func_00199170();

extern s32 D_004C2838[1];
extern void *func_003DA750();
extern void func_00163AA0();

void func_00163DC0(f32 *v) {
    u8 *r = (u8 *)func_003DA750(0, 0x2F, 1);
    if (r) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = (void *)func_00163AA0;
        *(u32 *)(r + 0xD0) = 0x800411;
        *(u32 *)(r + 0x50) = 0x3F800000;
        *(u32 *)(r + 0x54) = 0x3F800000;
        *(u32 *)(r + 0x58) = 0x3F800000;
        *(s16 *)(r + 0xCC) = 0x55;
        *(s32 *)(r + 0x84) = D_004C2838[0];
        *(V3 *)(r + 0x34) = *(V3 *)v;
        *(u32 *)(r + 0x78) = 0x3F800000;
        *(u32 *)(r + 0x7C) = 0x3F800000;
        *(u32 *)(r + 0x80) = 0x3F800000;
    }
}

extern u8 *D_004C2794[1];
extern s8 D_00455B5C[];

void func_002848D0(u8 *p) {
    s8 v = p[0x151];
    s32 w = (s8)(v & ~1);
    if (w != 0) {
        p[0x151] = v & 1;
        p[0x1B5] = D_00455B5C[((s8)w >> 1) << 2];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        *(s16 *)((p[2] << 1) + (u32)D_004C2794[0] + 0x7C) += 1;
    }
}

extern s32 D_004C2850[1];
extern void (*D_00477400[])();
extern void func_003D7300();
extern void func_0016CE10();
extern void func_00122880();
extern void func_003298E0();
extern void func_0016EEC0();


void func_003D7030(void) {
    if (D_004C2850[0] == 0) {
        func_003D7300();
        func_0016CE10();
        D_00477400[*(s8 *)D_004C2840[0]]();
        func_00122880();
        func_003298E0();
    }
    *(s32 *)(D_004C2840[0] + 0x1C) += 1;
    {
        s32 t = *(s32 *)(D_004C2840[0] + 0x20) + 0x50;
        *(s32 *)(D_004C2840[0] + 0x20) = t;
        if (t >= 0x10000) *(s32 *)(D_004C2840[0] + 0x20) = 0;
    }
    func_0016EEC0();
}
