typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct O_0 {
    u8 p0[0x10]; void *f10; void *f14; u8 p18[8]; u8 f20; u8 p21[0x13]; V3 f34; u8 p40[0x44]; s32 f84; u8 p88[0x40]; void *fc8; s16 fcc; u8 pce[2]; s32 fd0;
} O_0;
extern O_0 *func_003DA750(s32, s32, s32);
extern void func_0032EC30();
extern s32 D_004C283C;
extern V3 D_004B7780[];
void func_0032EB80(void *a, s32 i) {
    O_0 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o->f10 = (void*)func_0032EC30;
        o->fcc = i + 7;
        o->f84 = D_004C283C;
        o->f34 = D_004B7780[i];
        o->fd0 = 0x809;
        o->fc8 = (u8*)a + 0x88;
        o->f14 = a;
        o->f20 = i;
    }
}


extern void func_001237A0();
extern void func_0016CDA0();
extern void func_003298B0();
typedef struct { u8 p0[4]; s8 f4; u8 p5[3]; s16 f8; u8 pa[0xE]; s8 f18; u8 f19; } G;
extern G *D_004C2840;
extern f32 D_004F1F54[];
extern s8 D_004F1F47[];
void func_0032C090(void) {
    s8 t;
    func_001237A0();
    if (D_004F1F54[0] < 40.0f) {
        D_004C2840->f19 = 1;
        D_004F1F54[0] = 10.0f;
    }
    if (D_004F1F47[0] == 2) {
        t = D_004C2840->f4;
        D_004C2840->f4 = t + 1;
        func_0016CDA0();
        func_003298B0(-1, 0x14, 1);
        D_004C2840->f8 = 0x14;
        D_004C2840->f19 = 1;
    }
}


extern void func_001757E0();
extern s32 func_00175700();
extern void func_001E7F60();
extern void func_00388780();
typedef struct { u8 p0[0x7C]; s16 h7c; } T_2;
extern T_2 *D_004C2794;
typedef struct { u8 p0[0xD4]; s32 fd4; } B_2;
typedef struct {
    u8 p0[2]; u8 f2; u8 p3[2]; u8 f5; u8 p6[0x1AA]; u8 f1b0, f1b1, f1b2; u8 p1b3[2]; u8 f1b5; u8 p1b6[0xA]; u16 f1c0; u8 p1c2[0x16]; s32 f1d8;
} P_2;
void func_00388390(P_2 *a, B_2 *b) {
    u32 t;
    s16 v;
    s16 *q;
    if (b->fd4 != 0) {
        t = a->f5; a->f5 = t + 1;
        a->f1b0 = 0x44;
        a->f1b1 = 0x44;
        a->f1b5 = 0x48;
        a->f1b2 = a->f1c0 = 0;
        a->f1d8 = 0;
        q = (s16*)((a->f2 << 1) + (u32)D_004C2794);
        v = q[0x7C / 2] + 1;
        q[0x7C / 2] = v;
        func_001757E0(a, 0x17, 0xA);
        func_00175700(a);
        func_001E7F60(a);
    } else {
        func_00388780();
        func_00175700(a);
    }
}


extern s32 func_00174470();
typedef struct {
    u8 p0[4]; u8 f4, f5; u8 p6[0x2E]; f32 f34; u8 p38[0x24]; f32 f5c; u8 p60[8]; f32 f68; u8 p6c[0xD0]; u8 f13c; u8 p13d[0x75]; s8 f1b2, f1b3;
} P_3;
void func_00389D00(P_3 *a) {
    u32 t;
    a->f34 += a->f5c;
    a->f5c += a->f68;
    if (func_00174470(a) == 0) {
        t = a->f4; a->f4 = t + 1;
        a->f13c = 0;
    } else if (a->f1b2 != 0 || a->f1b3 != 0) {
        t = a->f5; a->f5 = t + 1;
        func_001757E0(a, 0x16, 0x1F);
    } else {
        func_00175700(a);
        func_001E7F60(a);
    }
}


typedef struct {
    u8 p0[6]; u8 f6; u8 p7[0x2D]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0xE0]; s8 f150; u8 p151[0x1EA]; u8 f33b, f33c;
} P_4;
void func_0022A930(P_4 *a) {
    u32 t;
    a->f33c = 5;
    if (a->f150 == 0) {
        a->f34 += a->f5c;
        a->f5c += a->f68;
        a->f38 += a->f60;
        a->f60 += a->f6c;
    }
    if ((s8)func_00175700(a) < 0) {
        a->f33b = 0;
        a->f33c = 0;
        t = a->f6; a->f6 = t + 1;
        func_001757E0(a, 0x16, 7);
    }
}


extern void func_001843A0();
extern void func_001E3A40();
typedef struct R_5 { u8 p0[0x1B5]; u8 f1b5; u8 p1b6[0x10]; void *f1c8; u8 p1cc[0x1A]; u8 f1e6; u8 p1e7[0x23]; u8 f20a; } R_5;
typedef struct {
    u8 p0[0x22]; u8 f22; u8 p23[0x11D]; s16 f140; u8 p142[0xF]; s8 f151; u8 p152[0x8A]; R_5 *f1dc; u8 p1e0[6]; u8 f1e6;
} P_5;
void func_002150C0(P_5 *a) {
    R_5 *q;
    if (a->f151 < 0) {
        a->f151 = 0;
        if (a->f22 & 2) {
            a->f1e6 ^= 1;
            a->f140 = a->f1e6;
        }
    }
    if (a->f151 == 1) {
        a->f151 = 0;
        q = a->f1dc;
        q->f1c8 = a;
        q->f1e6 = a->f1e6;
        q->f1b5 = 0x22;
        q->f20a = 0xB;
        func_001E3A40(q);
    }
    if ((s8)func_00175700(a) < 0) func_001843A0(a);
}


extern u8 D_004D18A0[];
extern void func_001E3CE0();
typedef struct {
    u8 p0[2]; u8 f2; u8 p3[2]; u8 f5; u8 p6[0x16]; s16 f1c; u8 p1e[2]; u8 f20; u8 p21[0x12B]; u8 f14c;
} P_6;
typedef struct { u8 p0[0x1E4]; u8 f1e4, f1e5; } B_6;
s32 func_001342D0(P_6 *a, B_6 *b) {
    u8 c;
    if (D_004D18A0[0] != 4) return 1;
    c = b->f1e4;
    if (c != 0x1B) return 1;
    if (b->f1e5 == 0x1B) return 1;
    b->f1e5 = c;
    a->f14c = 1;
    a->f5 = 0;
    a->f1c = 0;
    a->f20 = 3;
    if (D_004C2840->f18 & (1 << a->f2)) {
        func_001E3CE0(0xB);
    }
    return 0;
}

