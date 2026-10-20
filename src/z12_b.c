typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[2]; u8 b2; u8 p3; u8 b4; u8 b5; u8 b6; u8 b7; u8 p8[0x1C-8]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PH;

typedef struct { u8 pad0[4]; u8 b4; u8 b5; u8 b6; u8 pad7[0x34-7]; f32 f34; f32 f38; u8 pad3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; } E1;
extern u8 D_004C1B54[4];
void func_0035C310(E1 *p, u8 *q) {
    extern void func_00175700();
    extern s32 func_00174240();
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_001E7F60();
    u8 *r;
    r = q + 0x2B8;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (func_00174240(p) == 0) {
        p->b4 = 2;
        ((u8 *)p)[0x13C] = 0;
    } else if (((s8 *)p)[0x1B2] != 0) {
        p->b5 = 2;
        *(s8 *)(r + 7) = -1;
        func_001757E0((u8 *)p, 0x17, D_004C1B54[((u8 *)p)[0x1B7]] + ((s8 *)p)[0x151]);
    } else {
        func_001E7F60(p);
    }
}

typedef struct { u8 pad[0x7C]; s16 h7c[4]; } GA;
extern GA *D_004C2794;
void func_00241B50(PH *p) {
    extern void func_00175700();
    extern void func_00185490(PH *);
    extern void func_001757E0(PH *, s32, s32);
    s16 h;
    ((u8 *)p)[0x40C] = 2;
    ((u8 *)p)[0x33C] = 5;
    ((u8 *)p)[0x209] = 2;
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    h = p->h1c - 1;
    p->h1c = h;
    if (h == 0) {
        p->b7++;
        ((u8 *)p)[0x1B5] = 0x38;
        ((u8 *)p)[0x1B2] = *(u16 *)((u8 *)p + 0x1C0) = 0;
        *(s32 *)((u8 *)p + 0x1D8) = 0;
        D_004C2794->h7c[p->b2]++;
        func_00185490(p);
        func_001757E0(p, 0x16, 2);
    }
}

void func_0039AA40(PH *p) {
    extern void func_00175700();
    extern void func_001757E0(PH *, s32, s32);
    extern void func_001E7F60(PH *);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_00175700();
    if (((s8 *)p)[0x1B2] != 0) {
        ((u8 *)p)[0x1B5] = 0x48;
        *(u8 *)((s32)p + 0x1B2) = *(u16 *)((u8 *)p + 0x1C0) = 0;
        *(s32 *)((u8 *)p + 0x1D8) = 0;
        D_004C2794->h7c[p->b2]++;
        *(s16 *)((u8 *)p + 0x1C0) = 0x10;
        if (*(u8 *)(*(u8 **)((u8 *)p + 0x1C4) + 3) != 0) return;
        p->b5++;
        func_001757E0(p, 0x17, 0x12);
        p->h1c = 0xE;
        *(s16 *)((u8 *)p + 0x1E) = 0;
    }
    func_001E7F60(p);
}

void func_002A2010(PH *p) {
    extern s8 func_00175700();
    extern void func_001843A0(PH *);
    switch (((u8 *)p)[0x1FC]) {
    case 2:
        if (p->b6 != 0) {
            if (func_00175700(p) < 0) {
                func_001843A0(p);
            } else if (((s8 *)p)[0x151] != 0) {
                *(s8 *)((s32)p + 0x151) = 0;
                ((u8 *)p)[0x1B5] = 0x1C;
                ((u8 *)p)[0x1B2] = *(u16 *)((u8 *)p + 0x1C0) = 0;
                *(s32 *)((u8 *)p + 0x1D8) = 0;
                D_004C2794->h7c[p->b2]++;
            }
            break;
        }
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    }
}

typedef struct { f32 x, y, z; } V47;
typedef struct { V47 v0; V47 v1; u16 h18; u8 pad1a; s8 b1b; } T47;
extern T47 D_00442B50[];
extern u32 D_004C2804;



extern u8 *D_004C29FC;
void func_00399EC0(PH *p) {
    extern void func_0039A210();
    extern void func_00175700(PH *);
    extern void func_001E3210(PH *, s32);
    extern void func_00399720(PH *, s32);
    extern void func_001757E0(PH *, s32, s32);
    extern void func_001E7F60(PH *);
    s16 h;
    ((u8 *)p)[0x24] = 0;
    if (*(*(u8 **)((u8 *)p + 0x18) + 5) != 0) {
        func_0039A210(p);
    }
    func_00175700(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    h = p->h1c - 1;
    p->h1c = h;
    if (h == 0) {
        p->b5++;
        func_001E3210(p, 0x20);
        func_00399720(p, 1);
        func_00399720(p, 2);
        p->h1c = 0x32;
        ((u8 *)p)[0x22] = 0;
        D_004C29FC[2] = 2;
        *(s16 *)((u8 *)p + 0x1E) = 2;
        func_001757E0(p, 0x17, 3);
    }
    func_001E7F60(p);
}

typedef struct { u8 pad0[4]; s8 b4; u8 pad5[3]; s16 h8; u8 padA[4]; s16 hE; } G40;
extern G40 *D_004C2840;
extern f32 D_004F1D2C[];
extern u8 D_004F1D2B[];
void func_003DA110(void) {
    extern void func_001E43F0(s32, s32);
    extern void func_00122840(s32);
    extern void func_0016F0D0();
    extern void func_0016D190();
    f32 z;
    s16 v;
    v = D_004C2840->h8 - 1;
    D_004C2840->h8 = v;
    if (v == 0) {
        D_004C2840->b4++;
    }
    if (D_004C2840->h8 < 0x1F) {
        func_001E43F0(6, 0x1E);
    }
    if (D_004C2840->h8 == 10) {
        D_004C2840->hE = 3;
    }
    if (D_004C2840->hE >= 2) {
        z = 0.0f;
        D_004F1D2C[0] -= 140.0f;
        D_004F1D2B[0] += 2;
        if (D_004F1D2C[0] < z) {
            D_004C2840->hE = 3;
            D_004F1D2C[0] = z;
            D_004F1D2B[0] = 0xFF;
            func_00122840(-1);
        }
    }
    func_0016F0D0();
    func_0016D190();
}

void func_002C2690(PH *p) {
    extern void func_0018C4B0();
    extern void func_00185490(PH *);
    extern void func_002C25A0(PH *);
    extern void func_00183D10(PH *);
    extern void func_001757E0(PH *, s32, s32);
    p->b6++;
    ((u8 *)p)[0x1B5] = 0x42;
    ((u8 *)p)[0x1B2] = *(u16 *)((u8 *)p + 0x1C0) = 0;
    *(s32 *)((u8 *)p + 0x1D8) = 0;
    D_004C2794->h7c[p->b2]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    if (((u8 *)p)[0x20D] != 2) {
        func_002C25A0(p);
        func_00183D10(p);
        if (((u8 *)p)[0x1FD] == 7) ((u8 *)p)[0x168] = 0xB; else ((u8 *)p)[0x168] = 0;
    } else {
        ((u8 *)p)[0x168] = 7;
        p->f5c /= 16.0f;
        p->f60 /= 8.0f;
        p->f68 = 0;
        p->f6c /= 64.0f;
    }
    func_001757E0(p, 0x15, ((u8 *)p)[0x168]);
}
