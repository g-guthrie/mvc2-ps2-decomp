typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_001820A0(void *p);
extern s32 func_001843A0(void *p);
extern s32 (*D_00455B80[])(u8 *, u8 *);

s32 func_00284950(u8 *p) {
    if (p[0x20D] == 2) {
        func_001820A0(p);
        if (*(float *)(p + 0x38) <= *(float *)(p + 0x430)) {
            *(float *)(p + 0x38) = *(float *)(p + 0x430);
            p[0x20D] = 0;
            return func_001843A0(p);
        }
    }
    return D_00455B80[p[6]](p, (u8 *)((s32)p + 0x2B8));
}


extern u8 D_004BEFA0[];
extern u8 D_004BEFC0[];
extern u8 D_004BEFE0[];
extern u8 D_004BF000[];
extern u8 D_004BF020[];
extern void func_003DCAD0(void *a, s32 b, s32 c, s32 d);

s32 func_00419EE0(void) {
    func_003DCAD0(D_004BEFA0, 0, 0, 0);
    func_003DCAD0(D_004BEFC0, 0, 0, 0);
    func_003DCAD0(D_004BEFE0, 0, 0, 0);
    func_003DCAD0(D_004BF000, 0, 0, 0);
    func_003DCAD0(D_004BF020, 0, 0, 0);
    return 1;
}

extern void func_00175C00(void *p, s32 a);
extern void func_001861B0(void *p);
extern void func_0029BEB0(void *p);
extern void func_0029BDA0(void *p);
extern void func_0029BCD0(void *p);
extern void func_0029BB90(void *p);

void func_0029BAF0(u8 *p) {
    p[6] = 0;
    func_00175C00(p, 0);
    func_001861B0(p);
    if (p[0x212] == 1) {
        if (p[0x20D] == 1) {
            func_0029BEB0(p);
        } else {
            func_0029BDA0(p);
        }
    } else {
        if (p[0x20D] == 1) {
            func_0029BCD0(p);
        } else {
            func_0029BB90(p);
        }
    }
}

extern u8 D_0045BA50[];
extern s32 func_00189310(void *p, void *q, void *r);
extern void func_00186A60(void *p, s32 a);

typedef struct { u8 a; u8 b; u8 c; u8 d; u32 e; } E3D4;
extern E3D4 D_004B91D0[];
extern void func_003D7350(s32 a, s32 b, s32 c, s32 d);


typedef struct { u32 pad0; void *fn; void *buf; u32 size; void *gp; u32 g; } S3FE;
extern void *D_004C239C;
extern void *D_004C2320;
extern u8 D_0047D100[];
extern u32 D_0047D0E4;
extern u8 _gp[];
extern void func_003FDE40(void);
extern void *func_00103BE0(void *s);
extern void func_00103C00(void *a, s32 b);
extern void func_003FE1F8(void *a);
extern void func_00103C70(void *a, u32 b);

typedef float f32;
typedef struct { u8 pad[0x160]; s8 b[8]; } S160;
extern f32 D_00459E70[];
extern f32 D_00459E74[];
extern f32 D_00459E78[];
extern f32 D_00459E7C[];
extern void func_00175700(void *p);
extern void func_00186A20(void *p);

void func_002C7D30(u8 *p) {
    s8 *q;
    s8 v;
    s8 *r;
    func_00175700(p);
    q = ((S160 *)p)->b;
    v = q[1];
    r = q + 1;
    if (v != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_00186A20(p);
        *r = 0;
        *(f32 *)(p + 0x5C) = p[0x1E6] != 0 ? D_00459E70[p[0x1B7] * 4] : -D_00459E70[p[0x1B7] * 4];
        *(f32 *)(p + 0x68) = p[0x1E6] != 0 ? D_00459E74[p[0x1B7] * 4] : -D_00459E74[p[0x1B7] * 4];
        *(f32 *)(p + 0x60) = D_00459E78[p[0x1B7] * 4];
        *(f32 *)(p + 0x6C) = D_00459E7C[p[0x1B7] * 4];
    }
}

typedef struct { f32 x, y, z; } V3;
extern void func_001BBD30(void *p, void *q);
extern s32 func_001BBD40(void *p, void *q);
extern void func_00175580(void *p, s32 a, s32 b, s32 c);

void func_001BBC20(u8 *p, u8 *q) {
    if (p[1] != q[1]) {
        func_001BBD30(p, q);
        return;
    }
    if (func_001BBD40(p, q)) {
        p[0x13C] = 0;
        func_001BBD30(p, q);
        return;
    }
    if (((s8 *)p)[0x151] == 0) {
        *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    }
    {
        s8 *b = ((S160 *)q)->b;
        s32 t = b[1];
        s8 *r = b + 1;
        if (t != 0) {
            s8 v = t;
            if (v == 9) {
                p[0x13C] = 0;
                func_001BBD30(p, q);
            } else {
                func_00175580(p, 0x1B, 1, v - 1);
                *r = 0;
            }
        }
    }
}

extern u8 *D_006337A0[];

extern s32 D_004C253C;
extern s32 D_006340C0[];
extern u8 D_00634030[];
extern void func_00103E20(s32 a);
extern void func_00103E00(s32 a);
extern s32 func_00423890();
extern s32 func_00106E68(void * a, s32 b, s32 c, void * d, s32 e, void * f, s32 g, void * h, void * i);


extern s32 D_004C2B4C;
extern s32 D_004C2B50;
extern u8 func_004188F0[];
extern void func_003FDAA0(void);
extern void func_00402818(void *a, s32 b);
extern s32 func_003DCF70(s32 a);
extern s32 func_00401150(s32 a, s32 b, s32 c);
extern void func_00402208(s32 a, s32 b);
extern void func_00402458(s32 a, s32 b);
extern void func_00400D18(s32 a);
extern void func_004188E0(void);
extern void func_004189A0(void);
extern s32 func_00104C90();

typedef struct Q6 { s32 w0; s32 w4; s32 w8; s32 wC; s32 w10; s32 w14; s32 w18; s32 w1C; s32 w20; s32 w24; s32 w28; s32 w2C; s32 w30; s32 w34; s32 w38; s32 w3C; struct Q6 *w40; } Q6;
typedef struct A6 { s32 w0; s32 w4; s32 w8; s32 wC; s32 w10; s32 w14; s32 w18; s32 w1C; s32 w20; s32 w24; s32 w28; s32 w2C; s32 w30; Q6 *w34; } A6;


typedef unsigned long long u64;
extern s32 func_0010CA20(void);
extern void func_0010CA68(void);

