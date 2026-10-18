typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004BF510[2];
void func_001875A0(u8 *p) {
    extern void func_00185490(); extern void func_001861B0(); extern s32 func_001879C0(); extern void func_001757E0();
    func_00185490(p);
    func_001861B0(p);
    *(u32*)(p+0x60) = 0;
    *(u32*)(p+0x6C) = 0;
    if (func_001879C0(p) == 0) {
        p[0x1F1] = 0;
        if (p[0x1E5] != 0x12 && p[0x1E5] != 0x13) {
            p[0x1F2] = 0;
            *(u32*)(p+0x5C) = 0;
            *(u32*)(p+0x68) = 0;
        }
        *(u32*)(p+0x1D0) = 0;
        *(u8**)(p+0x228) = D_004BF510;
        if (p[0x20D] != 1) { p[0x168] = 0; p[0x20D] = 0; }
        else { p[0x168] = 4; p[0x20D] = 1; }
        func_001757E0(p, 5, p[0x168]);
    }
}

typedef struct { u8 pad[0x7C]; s16 t7c[1]; } G2;
extern G2 *D_004C2794;
void func_00265D80(u8 *p) {
    extern void func_00185490(); extern void func_001757E0(); extern void func_00183D10();
    if (p[0x269] == 6) { p[0x404] = 0xFF; p[0x405] = 0x10; }
    { u32 t = p[6]; p[6] = t + 1; }
    func_00185490(p);
    *(u32*)(p+0x5C) = 0; *(u32*)(p+0x60) = 0; *(u32*)(p+0x68) = 0; *(u32*)(p+0x6C) = 0;
    *(s16*)(p+0x4C) = 0; *(s16*)(p+0x4E) = 0;
    *(f32*)(p+0x38) = *(f32*)(p+0x430);
    p[0x1B5] = 0x3F;
    p[0x1B2] = *(u16*)(p+0x1C0) = 0;
    *(u32*)(p+0x1D8) = 0;
    D_004C2794->t7c[p[2]]++;
    func_001757E0(p, 0x16, 5);
    func_00183D10(p);
}

typedef struct { u8 pad[0x1C]; u32 f1c; } G1;
extern G1 *D_004C2840;
void func_0034C310(u8 *p) {
    u8 *q = *(u8**)(p+0x14);
    s16 *e;
    p[0x24] = *(s8*)(q+0x24);
    if ((D_004C2840->f1c & 3) != 0) {
        p[0x1B5] = 0x45;
        p[0x1B2] = *(u16*)(p+0x1C0) = 0;
        *(u32*)(p+0x1D8) = 0;
        D_004C2794->t7c[p[2]]++;
    } else {
        p[0x1B5] = 0x44;
        p[0x1B2] = *(u16*)(p+0x1C0) = 0;
        *(u32*)(p+0x1D8) = 0;
        D_004C2794->t7c[p[2]]++;
    }
    *(u32*)(p+0x5C) = 0x42A00000;
    {
        s16 v = *(s16*)(q+0x140);
        *(s16*)(p+0x140) = v;
        if (v != 0) *(f32*)(p+0x5C) = -*(f32*)(p+0x5C);
    }
}

extern void (*D_004C2030[2])();
void func_003B6F00(u8 *p, u8 *q) {
    extern void func_003B6D90();
    u32 k;
    *(s8*)(p+0x24) = *(s8*)(q+0x24);
    if (p[0x21] != 0) { func_003B6D90(p); return; }
    k = p[0x20];
    if (k == 2) {
        if (q[5] != 0 || q[0x1E4] != 0x1D) { u32 t = p[4]; p[4] = t + 1; p[0x13C] = 0; return; }
    } else {
        if (q[5] != 0 || q[0x1E4] != 0x14) { u32 t = p[4]; p[4] = t + 1; p[0x13C] = 0; return; }
    }
    D_004C2030[p[5]](p, q);
}

