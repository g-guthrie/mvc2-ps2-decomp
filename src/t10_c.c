typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
extern V3 D_0045ECD0;
extern V3 D_00460CC0[];
extern u8 *func_003DA750();
extern void func_0033C300();
extern void func_0033C250();
extern void func_00343B10();
extern void func_00170DF0(u32);
extern void func_003B3880();
extern void func_00175700();
extern void func_001E7F60();
extern void func_001757E0();
extern int func_00174470(const void *);
extern void func_003B3870();
extern void func_0016B0C0();
extern int func_00166C80();
extern void func_001830D0();
extern void func_001863F0();
extern void func_0022FFB0();
extern void func_00231D70();
typedef struct { s32 a, b; } P8;
extern u8 D_004C2688[2];
extern P8 D_004F4420[];
extern s32 func_0010DF60(s32 i, s32 z, u8 *p);

int func_001681A0(u8 *p, u8 *a1) {
    s32 a2;
    func_0016B0C0(p, a1, 0);
    func_0016B0C0(p, a1, 1);
    a2 = 0;
    switch (p[1]) {
    case 0x2F: a2 = *(s32 *)(p + 0x2D4); break;
    case 0x31: a2 = p[0x2CE]; break;
    case 0x22: a2 = *(s32 *)(p + 0xD0); break;
    case 0x2D: a2 = *(s8 *)(p + 0x2C1); break;
    }
    return func_00166C80(p, a1, a2 == *(s32 *)(p + 0x4C8));
}

void func_0016EE50(void) {
    s32 i = 0;
    s32 j = 0;
    do {
        u8 *q;
        D_004C2688[0] = 0;
        D_004C2688[1] = 0;
        func_0010DF60(i, 0, D_004C2688);
        i++;
        q = (u8 *)D_004F4420 + j;
        *(s32 *)q = 0;
        j += 8;
        *(s32 *)(q + 4) = 0;
    } while (i < 2);
}

