typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern u8 *D_004C2794;

extern u8 *D_004C2840;

void func_001CA170(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    u8 *r = *(u8 **)(p + 0x14);
    s8 c;
    s8 m;
    extern void func_00175670();
    if (q[0x1E4] == 0x1D && q[0x1FD] == 1 && (c = *(s8 *)(r + 0x151)) != -1) {
    } else {
        p[4] = 2;
        return;
    }
    m = c;  m &= 1;
    p[0x13C] = m;
    if (m != 0) {
        if (*(s32 *)(D_004C2840 + 0x1C) & 1) {
            *(u32 *)(p + 0x34) = 0xC3555555;
            *(u32 *)(p + 0x38) = 0x437CDB6D;
        } else {
            *(u32 *)(p + 0x34) = 0xC3805555;
            *(u32 *)(p + 0x38) = 0x43722492;
        }
        if (*(s16 *)(r + 0x140) != 0) {
            *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
        }
        *(f32 *)(p + 0x34) += *(f32 *)(r + 0x34);
        *(f32 *)(p + 0x38) += *(f32 *)(r + 0x38);
        func_00175670();
    }
}

typedef struct R14 { u8 pad0[4]; s32 w4; u8 pad8[0xB]; s8 b13; } R14;
extern s32 D_004C287C;
extern R14 D_004CD170[];
extern u8 D_004F20B0[];
extern s32 D_004B6AF0[];
extern s32 D_004B6A30[];

void func_001E2150(void)
{
    extern void func_001E5980(s32);
    extern void func_0012DA40(s32, s32, s32);
    extern void func_001E5870(s32, s32);
    extern void func_003DCD40(s32, s32, s32);
    s32 base;
    s32 i;
    s32 j;
    s32 k;

    base = (D_004C287C + 0x3F) & -0x40;
    func_001E5980(5);
    func_001E5980(3);
    func_001E5980(1);
    func_001E5980(4);
    func_001E5980(2);
    func_001E5980(0);
    for (i = 0; i < 6; i++) {
        D_004CD170[i].b13 = i;
        for (k = 0; k < i; k++) {
            if ((s8)D_004F20B0[i * 0x5B8 + 0x540] == (s8)D_004F20B0[k * 0x5B8 + 0x540]) {
                D_004CD170[i].b13 = k;
                break;
            }
        }
        j = D_004B6AF0[(s8)D_004F20B0[i * 0x5B8 + 0x540]] - 1;
        D_004CD170[i].w4 = j;
        func_0012DA40(j, base, 1);
        func_001E5870(base, D_004B6A30[D_004CD170[i].b13]);
        func_003DCD40(D_004C287C, 0, 4);
    }
}

#define MOVE(p) \
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C); \
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68); \
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60); \
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C)


static void func_00231D70(p)
u8 *p;
{
    p[437] = (u8)((signed char)p[336] + 81);
    p[434] = *(unsigned short *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
}

void func_002320D0(u8 *p, u8 *q)
{
    extern void func_00230020(u8 *, u8 *);
    s16 h;
    s8 t;
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h >= 0) {
        if ((*(s8 *)(p + 0x1B2) & 0x80) == 0) {
            func_00231D70(p, q);
            MOVE(p);
            return;
        }
        *(s8 *)(q + 0x12) = -1;
        t = *(s8 *)(q + 0x14) - 1;
        *(s8 *)(q + 0x14) = t;
        if (t > 0) {
            func_00231D70(p, q);
            MOVE(p);
            return;
        }
    }
    if (*(s8 *)(q + 0x12) == 0) {
        p[7]++;
        p[7]++;
        p[0x169] = 0x16;
        p[0x168] = 0xB;
        func_001757E0(p, p[0x169], p[0x168]);
        MOVE(p);
        return;
    }
    p[7]++;
    p[0x169] = 0x16;
    p[0x168] = 0xA;
    func_001757E0(p, p[0x169], p[0x168]);
    func_00231D70(p, q);
    p[0x150] = 0;
    func_00230020(p, q);
}

typedef struct {
    u8 pad0[6]; u8 b6; u8 pad7[0x1C - 7]; s16 h1c; u8 pad1e[0x34 - 0x1E];
    f32 f34; f32 f38; u8 pad3c[0x5C - 0x3C]; f32 f5c; f32 f60; u8 pad64[4];
    f32 f68; f32 f6c; u8 pad70[0x1E6 - 0x70]; u8 b1e6; u8 pad1e7[0x430 - 0x1E7]; f32 f430;
} SD;
void func_0024A3A0(u8 *p)
{
    SD *sp = (SD *)p;
    s16 t;
    f32 *q1, *q2;
    func_00175700(p);
    q1 = (f32 *)(p + 0x60);
    q2 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60)) {
        if (sp->f38 < sp->f430) {
            sp->f38 = sp->f430;
            *q1 = 0.0f;
            *q2 = 0.0f;
        }
    }
    t = *(s16 *)(p + 0x1C);
    t = t - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        p[6]++;
        if (p[0x1E6] == 0)
            *(u32 *)(p + 0x68) = 0xBE855555;
        else
            *(u32 *)(p + 0x68) = 0x3E855555;
        func_001757E0(p, 2, 3);
    }
}
