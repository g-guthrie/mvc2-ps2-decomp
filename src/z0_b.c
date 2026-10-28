typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
extern s16 *D_004C298C;

void func_00378A00(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00378B80(u8 *);
    extern void func_00174A40(u8 *, s32);
    extern s32 func_00174240(u8 *);
    extern void func_00378CA0(u8 *);
    extern void func_001E7F60(u8 *);
    func_00175700(p);
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
    if (*(s16 *)(p + 0x1E) <= 0) {
        *(s16 *)(p + 0x1E) = 0;
        func_00378B80(p);
        func_00174A40(p, *D_004C298C);
        *D_004C298C += 0x32;
    }
    if (func_00174240(p) == 0) {
        func_00378CA0(p);
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0)
        p[4]++;
    func_001E7F60(p);
}
typedef struct { u8 pad0[0x7C]; s16 f7c[1]; } G7;
extern G7 *D_004C2794;
extern u8 D_004C1468[4];
extern u8 D_004C146C[4];
extern u8 D_004C1470[4];

void func_00300D40(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        *(u8 **)(p + 0x408) = D_004C1468;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        *(u8 **)(p + 0x408) = D_004C146C;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004C1470;
        p[0x1BB] = 2;
        p[6] = 0;
        *(s16 *)(p + 0x1C) = 0x28;
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad0[0x50]; f32 f50, f54, f58; u8 pad1[0x78 - 0x5C]; f32 f78, f7c, f80; u8 pad2[0xDC - 0x84]; s32 fdc; } P61;
extern V3 D_004B3ED0[];
extern u8 *D_004C2840;

void func_00161410(P61 *p)
{
    V3 *t = D_004B3ED0;
    s32 k = *(s8 *)(D_004C2840 + 0x9C);
    if (k == 1 || k == 0x11)
        p->fdc = 0;
    else
        t = &D_004B3ED0[((k & 0xF) - 1) % 3];
    if (p->fdc == 0) {
        p->f50 = (t->x - p->f78) / 20.0f;
        p->f54 = (t->y - p->f7c) / 20.0f;
        p->f58 = (t->z - p->f80) / 20.0f;
        p->fdc = 0x14;
    }
    if (p->fdc != 0) {
        p->fdc = p->fdc - 1;
        p->f78 += p->f50;
        p->f7c += p->f54;
        p->f80 += p->f58;
    }
}
extern void (*const jtbl_004C20F8[16])(u8 *, void *) __attribute__((section(".sdata")));

/* Slot 14 + p[5] of jtbl_004C20F8 (== D_004C2130): func_003C3EA0 / func_003C4090,
   both defined as void (u8 *, void *) in src/q4_c.c. */
void func_003C3DE0(u8 *p, u8 *q)
{
    if (q[5] != 0) {
        p[4]++;
        return;
    }
    if (q[0x169] != 0x16) {
        p[4]++;
        return;
    }
    p[0x24] = 0xC;
    jtbl_004C20F8[14 + p[5]](p, q);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7)
        *(s8 *)(p + 0x24) = 7;
    if (*(s8 *)(p + 0x24) < 0)
        *(s8 *)(p + 0x24) = 0;
}
