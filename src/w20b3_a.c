typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G2794;
extern G2794 *D_004C2794;




void func_0031E500(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001865B0();
    extern void func_00184540();
    u8 *q;
    u32 *v0, *v1, *a1, *a2;
    s32 b;
    q = p + 0x2B8;
    v0 = (u32 *)(p + 0x5C);
    a1 = (u32 *)(p + 0x68);
    v1 = (u32 *)(p + 0x60);
    a2 = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *v0 = 0;
        *v1 = 0;
        *a1 = 0;
        *a2 = 0;
        func_001865B0(p);
        return;
    }
    if (p[7] == 0) {
        if (func_00175700(p) < 0) {
            p[0x20D] = 2;
            q[0] = 1;
            b = *(s8 *)(p + 0x1B2);
            if (b != 0 && ((s8)b & 1) == 0) {
                p[0x1E8] = 0;
                p[0x1EA] = 0x11;
                *(s8 *)(p + 0x1E7) = -1;
                func_00184540(p);
            } else {
                p[7]++;
                p[0x1E8] = 1;
                p[0x1E9] = 1;
                p[0x210] = 0;
                p[0x1EA] = 0;
            }
        }
    } else {
        func_00175700(p);
    }
}

extern u8 D_0045DEA0[];
extern u8 D_0045DE70[];
extern u8 D_0045DE80[];
extern u8 D_0045DE90[];
extern u32 D_0045DD40[];
extern u8 D_004C17F8[8];

void func_00322A60(u8 *p)
{
    extern void func_001861B0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003CD6B0(u8 *, s32);
    s32 a;
    s32 b;
    func_001861B0(p);
    p[7] = 0;
    p[6] = 0;
    a = p[0x1FC];
    if (p[0x20D] == 1) a = (u8)(a + 6);
    if (p[0x212] != 0) a = (u8)(a + 3);
    a = (u8)a;
    *(u32 *)(p + 0x334) = D_0045DEA0[a];
    *(u32 *)(p + 0x408) = D_0045DD40[a % 6];
    p[0x1BB] = D_004C17F8[p[0x1FC]];
    p[0x1B5] = D_0045DE70[a];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, D_0045DE90[a], D_0045DE80[a]);
    b = *(s8 *)(p + 0x151);
    if (b != 0) {
        func_003CD6B0(p, (s8)b - 1);
        p[0x151] = 0;
    }
    b = *(s8 *)(p + 0x150);
    if (b != 0) {
        func_003CD6B0(p, (s8)b - 1);
        p[0x150] = 0;
    }
}

void func_0039AB30(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    s16 t;
    func_00175700(p);
    t = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = t;
    if ((t & 7) == 0) {
        *(s16 *)(p + 0x1E) = 0;
        t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t <= 0) {
            p[5]++;
            *(s32 *)(p + 0x48) = 0;
            func_001757E0(p, 0x17, 0x13);
        } else if (*(s16 *)(p + 0x1C) > 1) {
            if ((*(s16 *)(p + 0x1C) & 1) != 0) {
                p[0x1B5] = 0x47;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
                *(u16 *)(p + 0x1C0) = 0x10;
            } else {
                p[0x1B5] = 0x48;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
                *(u16 *)(p + 0x1C0) = 0;
            }
        } else {
            p[0x1B5] = 0x49;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            *(u16 *)(p + 0x1C0) = 0;
        }
    }
    func_001E7F60(p);
}

extern f32 D_00462380[];
extern f32 D_00462384[];
extern f32 D_00462388[];
extern f32 D_0046238C[];

void func_0034EE70(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0034F330(u8 *);
    extern void func_0034F3B0(u8 *);
    extern void func_001E7F60(u8 *);
    if (func_00175700(p) < 0) {
        p[5]++;
        *(f32 *)(p + 0x5C) = (*(s16 *)(p + 0x140) != 0) ? D_00462380[p[0x21] * 4] : -D_00462380[p[0x21] * 4];
        *(f32 *)(p + 0x68) = (*(s16 *)(p + 0x140) != 0) ? D_00462384[p[0x21] * 4] : -D_00462384[p[0x21] * 4];
        *(f32 *)(p + 0x60) = D_00462388[p[0x21] * 4];
        *(f32 *)(p + 0x6C) = D_0046238C[p[0x21] * 4];
        func_001E3210(p, 0x1F);
        func_001757E0(p, 0x17, 0x13);
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        func_0034F330(p);
    } else if (*(s8 *)(p + 0x1B2) != 0) {
        func_0034F3B0(p);
    } else {
        func_001E7F60(p);
    }
}

typedef struct { u8 pad[0x18]; u8 *o; } P18;
