/* func_001428E0: Metrowerks 3.0 (./try30.sh) -O4 -Op -sdatathreshold 8.
 * func_001422E0 is a static copy of the real callee (credited in src/grok_gp_r2.c). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 h0; u8 pad[26]; } T1;

extern u8 *D_004C2840;
extern s32 D_004C264C;
extern s32 D_004C2638[2];
extern s32 D_004C2640;
extern s32 D_004C2644;
extern u8 D_004C27C0;
extern u8 D_004C27C4;
extern s32 D_004C2814;
extern u8 D_004F1D20[];
extern u8 *D_004CACB0[];
extern u8 *D_004CACB8[];
extern u8 *D_004CACBC[];
extern u8 *D_004CACC0[];
extern u8 *D_004CACC4[];
extern u8 *D_004CACD4[];
extern u8 *D_004CACD8[];
extern u8 *D_004CACDC[];
extern u8 *D_004CACE0[];
extern u8 *D_004CACE4[];
extern u8 *D_004CACE8[];
extern u8 *D_004CACEC[];
extern u8 *D_004CACF0[];
extern u8 *D_004CACF4[];
extern u8 *D_004CAD00[];
extern u8 *D_004CAD04[];
extern u8 *D_004CAD08[];
extern u8 *D_004CAD0C[];
extern u8 *D_004CAD3C[];
extern u8 *D_004CAD40[];
extern u8 *D_004CAD44[];
extern u8 D_004415F0[];
extern u8 D_004416D0[];
extern u8 D_00441480[];
extern u8 D_00441550[];
extern u8 D_00441620[];
extern u8 D_00441700[];
extern u8 D_004413D0[];
extern T1 D_00441E30[];

static void func_001422E0(u8 *p, s32 a1) {
    p[35] = a1 + 55;
    *(s16 *)(p + 204) = p[35];
    *(s32 *)(p + 132) = D_004C2814;
    p[32] = 0;
    *(s32 *)(p + 116) = 0;
    *(s32 *)(p + 208) = 0;
    p[49] = a1 + 13;
    *(s32 *)(p + 64) = 0;
    *(s32 *)(p + 72) = 0;
}

void func_001428E0(void) {
    extern void func_003298B0();
    extern void func_001E3CA0();
    extern void func_001E3FE0();
    extern void func_00141C90(s32, s32);
    extern void func_001415B0();
    extern u8 *func_00142610(s32);
    s32 jo;
    s32 i, j, m;
    u8 *o;
    u8 *v;

    switch (*(s16 *)(D_004C2840 + 10)) {
    case 0:
        D_004C2638[0] = 0xFF000000;
        D_004C2638[1] = 0xFF000000;
        func_003298B0(0, 0x1E, 0);
        func_001E3CA0(0);
        D_004C264C = 0;
        D_004C2644 = 0;
        break;
    case 0x3C:
        func_003298B0(0, 0x3C, 1);
        break;
    case 0x78:
        func_001E3FE0();
        break;
    case 0x6E:
        func_003298B0(0, 0x78, 0);
        break;
    case 0x1E3:
        D_004C2638[0] = 0xFF0000FF;
        D_004C27C4 = 1;
        D_004C2638[1] = 0xFF000000;
        D_004C27C0 = 4;
        o = D_004CACC4[0];
        o[0x13C] = 0;
        o[0x320] = 0;
        *(u8 **)(o + 0x3D8) = D_004415F0;
        *(s16 *)(o + 0x3E4) = 1;
        *(u8 **)(o + 0x5BC) = D_004416D0;
        *(s16 *)(o + 0x5C8) = 1;
        break;
    case 0x233:
        D_004C2640 = 0;
        D_004C2638[0] = 0xFF90B0C0;
        D_004F1D20[0] = 1;
        for (i = 0; i < 9; i++) {
            o = D_004CACB0[i];
            o[0x13C] = 0;
        }
        for (; i < 13; i++) {
            o = D_004CACB0[i];
            o[0] = 0;
            o[0x13C] = 0;
        }
        for (; i < 18; i++) {
            func_001422E0(D_004CACB0[i], i - 13);
        }
        break;
    case 0x346:
        D_004F1D20[0] = 0;
        D_004C2638[0] = 0xFF000000;
        D_004C2638[1] = 0xFF000000;
        o = D_004CACE4[0]; o[0] = 0; o[0x13C] = 0;
        o = D_004CACE8[0]; o[0] = 0; o[0x13C] = 0;
        o = D_004CACEC[0]; o[0] = 0; o[0x13C] = 0;
        o = D_004CACF0[0]; o[0] = 0; o[0x13C] = 0;
        o = D_004CACF4[0]; o[0] = 0; o[0x13C] = 0;
        D_004CAD3C[0][0x13C] = 0;
        D_004CAD40[0][0x13C] = 0;
        D_004CAD44[0][0x13C] = 0;
        D_004C2644 = 0;
        func_00141C90(5, (s32)D_00441480);
        func_00141C90(6, (s32)D_00441550);
        func_00141C90(7, (s32)D_00441620);
        func_00141C90(8, (s32)D_00441700);
        for (j = 0, jo = 0; j < 5; j++, jo += 4) {
            o = *(u8 **)((u8 *)D_004CACB0 + jo);
            o[0x13C] = 1;
            if (j == 1) {
                *(s16 *)(o + 0xCC) = 2;
                *(u8 **)(o + 0x84) = (u8 *)D_004C2814;
                *(u8 **)(o + 0x10) = D_004413D0;
                func_001415B0(o);
            }
        }
        for (i = 9; i < 18; i++) {
            o = D_004CACB0[i];
            o[0] = 0;
            o[0x13C] = 0;
        }
        break;
    case 0x3CA:
        D_004C2638[0] = 0xFFFF0000;
        D_004C2638[1] = 0xFF000000;
        D_004C27C4 = 1;
        D_004C27C0 = 5;
        o = D_004CACC4[0];
        *(u8 **)(o + 0x10) = D_004415F0;
        *(s16 *)(o + 0x1C) = 1;
        *(u8 **)(o + 0x1F4) = D_004416D0;
        *(s16 *)(o + 0x200) = 1;
        o[0x504] = 0;
        o[0x6E8] = 0;
        D_004CACD4[0][0x13C] = 0;
        D_004CACD8[0][0x13C] = 0;
        D_004CACDC[0][0x13C] = 0;
        D_004CACE0[0][0x13C] = 0;
        o = D_004CACF4[0];
        o[0] = 0;
        o[0x13C] = 0;
        D_004CAD00[0][0x13C] = 0;
        D_004CAD04[0][0x13C] = 0;
        D_004CAD08[0][0x13C] = 0;
        D_004CAD0C[0][0x13C] = 0;
        break;
    case 0x41A:
        D_004C2640 = 0;
        D_004C2638[0] = 0xFF90B0C0;
        D_004F1D20[0] = 1;
        for (i = 0; i < 9; i++) {
            o = D_004CACB0[i];
            o[0x13C] = 0;
        }
        for (i = 13; i < 18; i++) {
            o = D_004CACB0[i];
            o[0] = 0;
            o[0x13C] = 0;
            func_001422E0(o, i - 13);
        }
        D_004CAD3C[0][0x13C] = 1;
        D_004CAD40[0][0x13C] = 1;
        D_004CAD44[0][0x13C] = 1;
        break;
    case 0x52F:
        D_004C2638[0] = 0xFF000000;
        D_004C2638[1] = 0xFF000000;
        D_004F1D20[0] = 0;
        func_00141C90(5, (s32)D_00441480);
        func_00141C90(6, (s32)D_00441550);
        func_00141C90(7, (s32)D_00441620);
        func_00141C90(8, (s32)D_00441700);
        for (i = 0; i < 13; i++) {
            o = D_004CACB0[i];
            o[0x13C] = 1;
        }
        for (; i < 18; i++) {
            o = D_004CACB0[i];
            o[0] = 0;
            o[0x13C] = 0;
        }
        D_004CAD00[0][0x13C] = 1;
        D_004CAD04[0][0x13C] = 1;
        D_004CAD08[0][0x13C] = 1;
        D_004CAD0C[0][0x13C] = 1;
        o = D_004CAD3C[0]; o[0x13C] = 0; o[0] = 0;
        o = D_004CAD40[0]; o[0x13C] = 0; o[0] = 0;
        o = D_004CAD44[0]; o[0x13C] = 0; o[0] = 0;
        break;
    case 0x60B:
        o = D_004CACBC[0];
        *(f32 *)(o + 0x64) = 0.25f;
        o[0x20] = 1;
        break;
    case 0x615:
        o = D_004CACC0[0];
        *(f32 *)(o + 0x64) = 0.25f;
        o[0x20] = 1;
        D_004CACB0[0][0x25] = 2;
        D_004CACB8[0][0x25] = 2;
        break;
    case 0x6B5:
        func_003298B0(-1, 5, 1);
        break;
    }
    while (*(s16 *)(D_004C2840 + 10) == D_00441E30[D_004C264C].h0) {
        v = func_00142610(D_004C264C);
        if (D_004C264C >= 9 && D_004C264C < 12) {
            *(s16 *)(v + 0x1E) = 0x50;
        }
        if (D_004C264C == 12) {
            *(s16 *)(v + 0x1E) = 0x5A;
        }
        D_004C264C = D_004C264C + 1;
    }
}
