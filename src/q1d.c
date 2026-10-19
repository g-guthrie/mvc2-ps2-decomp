typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern f32 D_0045CE50[];
extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);

static void func_00296FB0(u8 *p) {
    u8 t = p[0x15B];
    if (t != 0) {
        p[0x1B5] = t; p[0x1B2] = p[0x1C0] = 0; *(s32 *)(p + 0x1D8) = 0;
        { u8 *q = D_004C2794 + p[2] * 2; s16 v = *(s16 *)(q + 0x7C) + 1; *(s16 *)(q + 0x7C) = v; }
        p[0x15B] = 0;
    }
}

static void func_002CFA20(u8 *p) {
    u8 t = p[0x15B];
    if (t != 0) {
        p[0x1B5] = t; p[0x1B2] = p[0x1C0] = 0; *(s32 *)(p + 0x1D8) = 0;
        { u8 *q = D_004C2794 + p[2] * 2; s16 v = *(s16 *)(q + 0x7C) + 1; *(s16 *)(q + 0x7C) = v; }
        p[0x15B] = 0;
    }
}

static void func_0030A450(u8 *p) {
    if (*(s8 *)(p + 0x151) < 0) {
        u32 i; p[0x209] = 1; i = *(s8 *)(p + 0x151) & 0x7F;
        if (i != 0) {
            f32 x; *(s8 *)(p + 0x151) = -0x80; x = D_0045CE50[i & 0xFF];
            if (p[0x1E6] == 0) x = -x;
            *(f32 *)(p + 0x34) += x;
        }
    }
}

void func_00299AF0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p+0x5C) = 0; *(s32 *)(p+0x60) = 0; *(s32 *)(p+0x68) = 0; *(s32 *)(p+0x6C) = 0;
        func_001843A0(p);
    } else func_00296FB0(p);
}

void func_002D0070(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p+0x5C) = 0; *(s32 *)(p+0x60) = 0; *(s32 *)(p+0x68) = 0; *(s32 *)(p+0x6C) = 0;
        func_001843A0(p);
    } else func_002CFA20(p);
}

void func_002D00D0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p+0x5C) = 0; *(s32 *)(p+0x60) = 0; *(s32 *)(p+0x68) = 0; *(s32 *)(p+0x6C) = 0;
        func_001843A0(p);
    } else func_002CFA20(p);
}

void func_0030A620(u8 *p) {
    if ((s8)func_00175700(p) < 0) { u32 t = p[6]; p[6] = t + 1; func_001757E0(p, 2, 3); }
    func_0030A450(p);
}
