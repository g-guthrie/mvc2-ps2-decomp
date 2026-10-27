typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2794;
extern G2794 *D_004C2794;
extern s32 D_004C0780[2], D_004C0784[2], D_004C0788[2];
extern s32 D_004F54D0[];
extern f32 D_004F1F54[];
typedef struct { u8 f; u8 pad[23]; } E24;
extern E24 D_004F7D38[];
extern E24 D_004D1578[];

void func_00273FA0(u8 *p)
{
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        *(s32 **)(p + 0x408) = D_004C0780;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(s32 **)(p + 0x408) = D_004C0784;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(s32 **)(p + 0x408) = D_004C0788;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}

void func_003D6D50(void)
{
    extern void func_00414FE0();
    extern void func_004180B0();
    s32 i, off;
    s32 *q;
    func_00414FE0();
    func_004180B0();
    i = 0;
    off = 0;
    do {
        q = (s32 *)((u8 *)D_004F54D0 + off);
        q[0] = i;
        q[1] = 0x10;
        q[2] = 0;
        q[12] = i + 1;
        q[13] = 0x10;
        q[14] = 0;
        q[24] = i + 2;
        q[25] = 0x10;
        q[26] = 0;
        q[36] = i + 3;
        q[37] = 0x10;
        q[38] = 0;
        q[48] = i + 4;
        q[49] = 0x10;
        q[50] = 0;
        q[60] = i + 5;
        q[61] = 0x10;
        q[62] = 0;
        q[72] = i + 6;
        q[73] = 0x10;
        q[74] = 0;
        q[84] = i + 7;
        q[85] = 0x10;
        q[86] = 0;
        i += 8;
        off += 0x180;
    } while (i < 0x80);
}

void func_002060B0(u8 *p)
{
    extern u8 *func_001E7FD0(u8 *);
    extern s8 func_00175700();
    extern void func_00185640(u8 *, u8 *);
    extern void func_001843A0();
    extern void func_00184540();
    u8 *o;
    if (*(u8 *)(*(u8 **)(p + 0x220) + 0x20D) != 1 && *(s8 *)(p + 0x151) != 0 && (o = func_001E7FD0(p)) != 0) {
        p[6] = 0;
        p[0x22] = 1;
        p[0x20B] = 0xC0;
        func_00185640(p, o);
        return;
    }
    if (p[0x20D] != 2) {
        if (func_00175700(p) < 0) func_001843A0(p);
    } else {
        if (func_00175700(p) < 0) func_00184540(p);
    }
}

void func_0029CAC0(u8 *p)
{
    extern s8 func_00175700();
    extern void func_00184540();
    switch (p[0x1FC]) {
    case 2:
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            p[0x1B5] = 0xE;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        if (func_00175700(p) < 0) func_00184540(p);
        break;
    case 0:
    case 1:
        if (func_00175700(p) < 0) func_00184540(p);
        break;
    }
}

static void func_0014E770(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 220) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        } else {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        }
    }
}

void func_0014EF40(u8 *p)
{
    s32 i;
    func_0014E770(p);
    if (((s8 *)D_004C2840)[4] == 0) {
        i = ((s8 *)D_004C2840)[6] + *(s16 *)(*(u8 **)(p + 0x18) + 0x1E);
        if (D_004F7D38[i].f > 1) {
            p[0x13C] = 1;
            p[0x13C] = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
        } else {
            p[0x13C] = 0;
        }
    } else {
        i = ((s8 *)D_004C2840)[6] + *(s16 *)(*(u8 **)(p + 0x18) + 0x1E);
        if (D_004D1578[i].f > 1) {
            p[0x13C] = 1;
            p[0x13C] = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
        } else {
            p[0x13C] = 0;
        }
    }
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}

void func_001CF7A0(u8 *p)
{
    extern void func_00176160();
    u8 *q = *(u8 **)(p + 0x18);
    if ((*(u32 *)(D_004C2840 + 0x1C) & 1) != 0) {
        func_00176160(q, 0, q[0x25] << 1, 1);
    } else {
        func_00176160(q, 0, (q[0x25] << 1) + 1, 1);
    }
}

