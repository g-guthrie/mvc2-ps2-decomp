typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 f7c[1]; } G4;
extern G4 *D_004C2794;
extern u32 D_004C03BC;
extern u32 D_004C03C0;
extern u32 D_004C03C4;

static inline void reset_command(u8 *p, u8 command) {
    unsigned int offset;
    p[0x1b5] = command;
    p[0x1b2] = *(u16 *)(p + 0x1c0) = 0;
    *(int *)(p + 0x1d8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(short *)(offset + 0x7c);
}

void func_00248C00(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(u32 *)(p + 0x408) = (u32)&D_004C03BC;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        *(u32 *)(p + 0x408) = (u32)&D_004C03C0;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 5;
        func_001E3710(p, 0x16);
        *(u32 *)(p + 0x408) = (u32)&D_004C03C4;
        p[0x1BB] = 2;
        break;
    }
    reset_command(p, *(volatile u8 *)(p + 0x1B5));
    func_001757E0(p, 8, p[0x168]);
}

typedef struct { u8 pad0[1]; s8 b1; s8 b2; u8 pad3[5]; s16 h8; u8 pad4[0x29 - 0xA]; s8 b29; } G5;
extern G5 *D_004C2840;
extern u8 D_004B8C10[];
extern u8 D_004B8950[];

void func_003D1900(void) {
    extern s32 func_0012E560();
    extern void func_0016E8F0();
    extern void func_0016D4B0(u8 *, f32, s32);
    extern void func_0016E950();
    extern void func_00172450();
    u8 *s;
    D_004C2840->h8--;
    if (D_004C2840->h8 == 0) {
        if (func_0012E560() == 0) {
            D_004C2840->h8++;
        } else {
            D_004C2840->b1++;
            D_004C2840->b2 = 0;
        }
    } else {
        if (D_004C2840->b29 == 1) s = D_004B8C10;
        else s = D_004B8950;
        func_0016E8F0();
        while (*s < 100) {
            func_0016D4B0(s, 0.5f, 0);
            s += 0x40;
        }
        func_0016E950();
    }
    if (D_004C2840->h8 == 0x23) func_00172450();
}

typedef struct { f32 x, y, z; } V3;
extern u8 *D_004C2924;
extern u32 D_004C2830;
extern V3 D_0043F490[];
extern u8 D_004B1221[];

void func_0013CB50(u8 q) {
    extern u8 *func_003DA750();
    extern void func_0013CDE0();
    extern void func_00137140();
    extern void func_00170DF0();
    u8 *o;
    f32 half = 0.5f;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(u8 **)(o + 0xC8) = D_004C2924 + 0x88;
        *(void **)(o + 0x10) = func_0013CDE0;
        o[0x21] = q;
        *(V3 *)(o + 0x34) = D_0043F490[q];
        *(s16 *)(o + 0x1E) = D_004B1221[q * 2] * 2;
        *(f32 *)(o + 0x3C) += half;
        *(s16 *)(o + 0xCC) = *(s16 *)(o + 0x1E) + 0x9D;
        *(u32 *)(o + 0x84) = D_004C2830;
        *(u32 *)(o + 0xD0) = 0x815;
        func_00137140(o, o[0x21]);
        *(s16 *)(o + 0x1C) = 0;
        func_00170DF0(*(u32 *)(o + 0x84));
    }
}

void func_0025EA90(u8 *p) {
    extern void func_0036BFF0();
    extern void func_001E3710();
    extern void func_001757E0();
    extern void func_00175700();
    *(u32 *)(p + 0x50) = 0x3F800000;
    *(u32 *)(p + 0x54) = 0x3F866666;
    p[0x209] = 2;
    if (*(s8 *)(p + 0x153) < 0) {
        p[6] = 2;
        *(s16 *)(p + 0x366) = 0;
        p[0x2BE] = 0;
        *(u16 *)(p + 0x2C0) = 0;
        reset_command(p, 0x33);
        func_0036BFF0(p, 10, 0x13, 10);
        func_0036BFF0(p, 9, 0x13, 9);
        func_0036BFF0(p, 11, 0x13, 11);
        func_001E3710(p, 0x4B);
        func_001757E0(p, 0x15, (u8)(p[7] + 3));
        func_00175700(p);
    } else {
        func_00175700(p);
    }
}
