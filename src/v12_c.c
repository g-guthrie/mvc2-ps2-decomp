typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004C27A4;
void func_001A59C0(u8 *a, s32 b) {
    extern u8 *func_003DA750();
    extern void func_001A5600();
    s32 i;
    u8 *o;
    if (D_004C27A4 > 8) {
        i = 0;
        do {
            if ((o = func_003DA750(0, 3, 1)) != 0) {
                *(u16*)(o+0x26) = 0xE04;
                o[0x20] = 2;
                o[0x21] = (i >> 1) | ((i & 1) << 7);
                o[0x23] = a[0x23];
                *(void**)(o+0x10) = func_001A5600;
                *(s32*)(o+0x18) = b;
                *(u8**)(o+0x14) = a;
            }
            i++;
        } while (i < 8);
    }
}

typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
void func_00343A60(V3 *a, s32 b) {
    extern u8 *func_003DA750();
    extern s32 func_00417A40();
    extern void func_003439D0();
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003439D0;
        *(s16 *)(o + 0xCC) = b * 3 + 0x1C + func_00417A40() % 3;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = *a;
    }
}

typedef struct { u8 pad[0x7C]; s16 t[1]; } G;
extern G *D_004C2794;
void func_00231E90(u8 *p, s32 b) {
    extern void func_0022F190();
    extern void func_00183D10();
    extern void func_001757E0();
    extern void func_00231DB0();
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    { u32 t = p[7]; p[7] = t + 1; }
    func_0022F190(p);
    func_00183D10(p);
    p[0x169] = 0x16;
    p[0x168] = 0xC;
    func_001757E0(p, p[0x169], p[0x168]);
    p[0x1B5] = 0x52;
    p[0x1B2] = *(u16*)(p + 0x1C0) = 0;
    *(s32*)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]] += 1;
    func_00231DB0(p, b);
}

