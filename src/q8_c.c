typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C25E0;
extern s16 D_004C25F4;
extern s16 D_004C25F0;
extern u8 *D_004C2840;
extern s16 D_004F4484[];
extern s16 D_004F4498[];
extern s16 D_004F4480[];
extern s16 D_004F4494[];
extern void (*D_0043CCB8[])();
extern s32 func_0012F930();
extern void func_003DA6F0();
extern void func_003D7310();
extern void func_00152840();
void func_00128A30(void) {
    D_004C25E0 = 0;
    if (func_0012F930(1) == 0) {
        D_004C25F4 = D_004F4484[0] | D_004F4498[0];
        D_004C25F0 = D_004F4480[0] | D_004F4494[0];
        D_0043CCB8[*(s8 *)(D_004C2840 + 1)]();
        if (D_004C25E0 == 0) {
            func_003DA6F0(0xD);
            func_003DA6F0(0xF);
        }
        if (D_004C25E0 == 0) {
            func_003D7310(func_00152840);
        }
    }
}

extern f32 D_004C0D90[2];
extern void func_00183d50();
extern void func_001757E0();
void func_002BB130(u8 *p) {
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        f32 v;
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) {
            v = D_004C0D90[p[0x1B7]];
        } else {
            v = -D_004C0D90[p[0x1B7]];
        }
        *(f32 *)(p + 0x68) = v;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0xD);
    }
}

typedef struct { f32 x, y, z; } V3;
extern u8 *func_003DA750();
extern void func_00149B70();
extern s32 D_004C2804;
u8 *func_00149D70(u8 a, u32 b, V3 *c) {
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) == 0) {
        return 0;
    }
    o[0x13C] = 1;
    *(void **)(o + 0x10) = func_00149B70;
    *(s16 *)(o + 0xCC) = (b & 0xFFFF00FF) + 0x13E;
    *(s32 *)(o + 0x84) = D_004C2804;
    *(s32 *)(o + 0xD0) = 0x401;
    *(V3 *)(o + 0x34) = *c;
    o[0x20] = a;
    o[0x21] = 0;
    *(s16 *)(o + 0x1C) = b & 0xFF00;
    return o;
}

extern V3 D_004B7CC0;
extern s32 D_004C283C;
extern u8 *func_003DA750();
extern void func_00334080();
extern void func_00333FE0();
void func_003344F0(u8 *p) {
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00334080;
        *(s16 *)(o + 0xCC) = 0x15;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x805;
        *(V3 *)(o + 0x34) = D_004B7CC0;
        *(u8 **)(o + 0xC8) = p + 0x88;
        func_00333FE0(o);
    }
}
