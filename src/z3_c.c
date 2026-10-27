#include "action_record.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G1;
extern G1 *D_004C2794;
void func_001FD5B0(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_00183d50();
    extern void func_001757E0();
    s32 r;
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7]; p[7] = t + 1;
        func_00183d50(p);
        p[0x20D] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 8, 5);
        return;
    }
    r = *(s8 *)(p + 0x151);
    if (r != 0) {
        p[0x1B5] = r;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x151] = 0;
    }
}

extern Mvc2ActionRecord D_00455EF0[];
void func_0028C810(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_0028D810(u8 *, u8 *);
    extern void func_0041AC70();
    extern void func_001E3710();
    extern void func_001757E0();
    u8 *q;
    u32 t;
    p[0x40C] = 2;
    q = p + 0x2B8;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        *(s16 *)(p + 0x1E) = 0x12;
        p[7] = 0;
        q[0xC] = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        func_0028D810(p, (u8 *)D_00455EF0);
        p[0x1B5] = 0x44;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_0041AC70(p);
        func_001E3710(p, 0x48);
        func_001757E0(p, 0x16, 3);
    }
}

extern u8 D_004C1128[4];
extern u8 D_004C112C[4];
extern u8 D_004C1130[4];
void func_002E94E0(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    u32 v;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        *(u8 **)(p + 0x408) = D_004C1128;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        *(u8 **)(p + 0x408) = D_004C112C;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004C1130;
        p[0x1BB] = 2;
        p[6] = 0;
        *(s16 *)(p + 0x1C) = 0x28;
        break;
    default:
        break;
    }
    v = p[0x1B5];
    p[0x1B5] = v;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}

void func_002B08B0(u8 *p) {
    extern int func_00175700(u8 *);
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    t = p[0x15B];
    if (t != 0) {
        p[0x1B5] = t;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x15B] = 0;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 u = p[6];
        p[6] = u + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        *(u32 *)(p + 0x68) = 0x3ED55555;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        *(u32 *)(p + 0x60) = 0x41CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}
