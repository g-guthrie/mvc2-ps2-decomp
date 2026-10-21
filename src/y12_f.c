typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a, b; } SP;
extern SP D_00444A40[];
extern f32 D_00444A60[];
extern s32 D_004C2838;
typedef struct { u8 p0; s8 b1; s8 b2, b3, b4, b5, b6, b7; s16 h8; u8 pad[0x24]; s8 b2E; } G22;
extern G22 *D_004C2840;
extern u8 D_004F4384[];
extern u8 D_004D18A0[];
typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G7C;
extern G7C *D_004C2794;
typedef struct LaunchRecord { s16 vx,vy,x,y; u8 animation,event; } T10;
extern T10 D_004B8300[];

void func_00154FF0(u8 *p) {
    extern void func_003DAA40();
    s32 h;
    s16 hh;
    switch (p[4]) {
    case 0:
        hh = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = hh;
        if (hh > 2) {
            u32 t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1C) = 0;
            p[0x13C] = 1;
        }
        break;
    case 1:
        h = *(s16 *)(p + 0x1C);
        if (h > 5) {
            func_003DAA40();
        } else {
            *(s16 *)(p + 0xCC) = D_00444A40[h].a;
            *(s32 *)(p + 0x84) = D_004C2838;
            *(f32 *)(p + 0x78) = D_00444A60[*(s16 *)(p + 0x1C)];
            *(f32 *)(p + 0x7C) = *(f32 *)(p + 0x78);
            *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
            *(s16 *)(p + 0x1C) += 1;
        }
        break;
    }
}

void func_00172A10(void) {
    extern void func_003298B0();
    extern void func_001E42D0();
    extern void func_003DA410();
    extern void func_0011D8F8();
    extern void func_001E40E0();
    extern void func_001E4140();
    extern void func_001E4150();
    D_004C2840->h8 -= 1;
    if (D_004C2840->h8 == 0x3C) {
        func_003298B0(0xFF000000, 0x3C, 1);
        func_001E42D0(0x3C);
    }
    if (D_004C2840->h8 == 0) {
        D_004C2840->b1 += 1;
        D_004C2840->b2 = 0;
        D_004C2840->b3 = 0;
        D_004C2840->b4 = 0;
        D_004C2840->b5 = 0;
        D_004C2840->b6 = 0;
        D_004C2840->b7 = 0;
        D_004C2840->b2E = 3;
        func_003DA410();
        func_0011D8F8(D_004F4384, 0, 0x80);
        func_0011D8F8(D_004D18A0, 0, 0xC0);
        func_001E40E0();
        func_001E4140();
        func_001E4150();
    }
}

void func_003458F0(u8 *p) {
    extern void func_00345BD0();
    extern void func_00345CB0(u8 *, u8 *, T10 *);
    u8 *q;
    u8 *r;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    r = q + 0x2B8;
    func_00345BD0(p);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
    } else {
        if (p[0x20] == 0) r[2] = 1;
        func_00345CB0(p, q, &D_004B8300[p[0x1B7] + p[0x20] * 2]);
        if (q[0x269] == 3) {
            p[0x1B5] = 0x57;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
}

void func_0029FB30(u8 *p) {
    extern void func_0018C4B0();
    extern void func_001757E0();
    extern void func_0029D5E0();
    extern void func_00390300();
    extern void func_0029FA00();
    extern s8 func_00175700();
    extern void func_0029B130();
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        p[0x20D] = 0;
        func_0018C4B0(p, 5);
        p[0x1B5] = 0x30;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x15, 1);
        func_0029D5E0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) & 0x80) {
        p[0x28F] = 0;
        p[0x28E] = 0x10;
        *(s8 *)(p + 0x151) = *(s8 *)(p + 0x151) & 0x7F;
        func_00390300(p, (u8)(p[0x1B7] + 2));
    }
    func_0029FA00(p);
    if (func_00175700(p) < 0) func_0029B130(p);
}
