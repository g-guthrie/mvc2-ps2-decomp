typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x74]; s8 f74[2]; u8 f76; } G183;
extern G183 *D_004C2794;
extern u8 D_004F1F43[];
extern u8 D_004F1F44[];
extern s32 D_004D18B8[];
extern s32 D_004D18BC[];
extern s32 D_004D18C0[];

void func_00183630(u8 *p) {
    extern s32 func_00327CF0();
    extern void func_00183A70();
    extern void func_001E3710();
    extern void func_001E3210();
    extern void func_001356F0();
    extern void func_00175C00();
    u32 x;
    p[0x33B] = D_004C2794->f74[p[2]] + 1;
    D_004C2794->f76 = (D_004C2794->f74[p[2]] + 1) | (p[2] << 4);
    p[0x33C] = 0x10;
    if (func_00327CF0(p, 1) != 0) {
        func_00183A70(p);
        func_001E3710(p, 0x1E);
        func_001E3210(p, 0x2B);
        func_001356F0(p, 0);
        D_004F1F43[0] = 1;
        D_004F1F44[0] = 7;
        x = p[2] ^ 1;
        func_00175C00(D_004D18B8[x * 3], 2);
        x = p[2] ^ 1;
        func_00175C00(D_004D18BC[x * 3], 2);
        x = p[2] ^ 1;
        func_00175C00(D_004D18C0[x * 3], 2);
    }
}
