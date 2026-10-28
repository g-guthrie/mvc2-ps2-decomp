typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_00223E40(u8 *p) {
    extern s32 func_00175700();
    extern void func_00184540();
    extern void func_00355BE0();
    if (p[0x2B8] != 0) p[0x200] = 1;
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_00355BE0(p, 6);
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_00184540(p);
        break;
    }
}

typedef struct G { u8 pad[0x7C]; s16 t[1]; } G;
extern G *D_004C2794;

void func_0026C300(u8 *p) {
    extern s32 func_00175700();
    extern void func_00184540();
    switch (p[0x1FC]) {
    case 2:
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
        } else if (p[0x15B] != 0) {
            p[0x1B5] = 0x11;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->t[p[2]] += 1;
            p[0x15B] = 0;
        }
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_00184540(p);
        break;
    }
}

void func_003A47A0(u8 *p, u8 *owner_unused) {
    extern s32 func_00175700();
    extern void func_003A48D0();
    extern void func_001757E0();
    extern void func_001E7F60();
    if ((s8)func_00175700(p) < 0) {
        u32 t;
        func_003A48D0(p);
        if (*(s8 *)(p + 0x1B2) != 0) {
            p[0x1B5] = *(s8 *)(p + 0x20) + 0x3E;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->t[p[2]] += 1;
        }
        t = p[5];
        p[5] = t - 1;
        func_001757E0(p, 0x17, 0x1C);
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        p[5] = 3;
        func_001757E0(p, 0x17, 0x1E);
    } else {
        func_001E7F60(p);
    }
}
