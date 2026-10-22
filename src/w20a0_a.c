typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 D_004C0EDC[4];
extern u8 D_004C0EE0[4];
extern u8 D_004C0EE4[4];
extern u8 D_004C0EF4[4];
extern u8 D_004C0EF8[4];
extern u8 D_004C0EFC[4];
typedef struct { s16 pad[0x3E]; s16 cnt[1]; } G1;
extern G1 *D_004C2794;

void func_002CCAD0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s32 t;
    p[0x169] = 12;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 1;
        p[0x1B5] = 0x14;
        p[0x169] = 0x14;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C0EDC; else *(u8 **)(p + 0x408) = D_004C0EF4;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x169] = 0x14;
        p[0x168] = 2;
        p[0x1B5] = 0x15;
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            p[0x169] = 12;
            p[0x168] = 1;
            p[0x1B5] = 0x10;
        }
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C0EE0; else *(u8 **)(p + 0x408) = D_004C0EF8;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 3;
        p[0x1B5] = 0x16;
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            p[0x168] = 2;
            p[0x1B5] = 0x11;
        } else {
            p[0x169] = 0x14;
        }
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C0EE4; else *(u8 **)(p + 0x408) = D_004C0EFC;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->cnt[p[2]] += 1;
    func_001757E0(p, p[0x169], p[0x168]);
    t = ((s8 *)p)[0x1EA];
    if (t & 0xF0) *(s8 *)((s32)p + 0x1EA) = t - 0x10;
}

extern f32 D_00476560[];
extern f32 D_00476564[];

void func_003CA150(u8 *a, u8 *b) {
    extern s32 func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_003CA330(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 i;
    f32 f1, f2;
    u8 t;
    u32 u;
    if (*(s32 *)(a + 0xD0) == *(u16 *)(b + 0x168)) {
    if (b[5] == 0 && ((s8 *)a)[0x1B3] == 0
        && (((s8 *)a)[0x1B2] == 0
            || (((s16)((s8 *)a)[0x1B2] & 0x11) == 0 && (*(u8 **)(a + 0x1C4))[3] == 0))
        && ((s8 *)b)[0x151] == 0) {
        if ((s8)func_00175700(a) < 0 && a[0] == 0) goto call;
        ((s8 *)a)[0x24] = ((s8 *)b)[0x24];
        *(V3 *)(a + 0x34) = *(V3 *)(b + 0x34);
        i = a[0x20] << 3;
        f1 = *(f32 *)((u8 *)D_00476560 + i);
        f2 = *(f32 *)((u8 *)D_00476564 + i);
        if (*(s16 *)(a + 0x140)) f1 = -f1;
        *(f32 *)(a + 0x34) += f1;
        *(f32 *)(a + 0x38) += f2;
        u = a[0x22];
        t = u - 1;
        a[0x22] = t;
        if (t & 0x80) {
            a[0x22] = 8;
            a[0x1B5] = ((s8 *)a)[0x20] + 0x7E;
            a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
            *(s32 *)(a + 0x1D8) = 0;
            D_004C2794->cnt[a[2]] += 1;
        }
        func_001E7F60(a);
        return;
    }
    ((s8 *)b)[0x151] = 0;
    ((s8 *)a)[0x1B3] = 0;
    *(s16 *)(a + 0x1C) = ((s8 *)a)[0x1B2] = 0;
    a[0] = 0;
    func_001757E0(a, 0x17, (u8)(a[0x20] + 0x20));
    } else {
call:
        func_003CA330(a, b);
    }
}
