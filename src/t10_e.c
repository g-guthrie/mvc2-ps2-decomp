typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001E7F60();
extern s32 func_003B3870();
extern s16 D_00448430[];
extern s32 func_003A23F0(void *p, s32 a, s32 b);
extern void func_0018F9E0();
extern void func_00190540(void *p, s32 a);
extern void func_001902F0(void *p);
extern u8 *D_004C2794;
extern s32 func_00175670();
extern void func_001D0F70(void *a, void *b);
extern s32 func_00175700();
extern void func_001757E0();
extern s32 func_00185980();
extern void func_00185640();
extern void func_00178F20();
extern void func_00179160();
extern u8 *func_003DA750();
extern void func_00396E30();
extern u8 D_004CAB79;
typedef struct { u8 a; u8 pad; u16 b; u32 c; } E8;
extern E8 D_004CA670[];
typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
extern V3 D_0045ECD0;
extern V3 D_00460CC0[];
extern void func_0033C300();
extern void func_0033C250();
extern void func_00343B10();
extern void func_00170DF0();
extern void func_003B3880();
extern int func_00174470(const void *);
extern void func_0016B0C0();
extern void func_00166C80();
extern void func_001830D0();
extern void func_001863F0();
extern void func_0022FFB0();
extern void func_00231D70();

void func_001D0EC0(u8 *a, u8 *b) {
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140);
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    if (*(s32 *)(a + 0xD0) == *(u16 *)(b + 0x168)) {
        s8 r = func_00175670(a);
        if (r < 0) {
          if (a[0x20] == 2) return;
        } else return;
    }
    func_001D0F70(a, b);
}

void func_0023D5F0(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x1A));
        return;
    }
    if (func_00185980(p) != 0) {
        u8 *q;
        p[0x20B] = 2;
        p[0x20B] |= 0x40;
        p[0x20B] |= 0x80;
        p[7] = 0;
        p[6] = 0;
        q = *(u8 **)(p + 0x1C4);
        *(s32 *)(q + 0x6C) = 0;
        *(s32 *)(q + 0x68) = 0;
        *(s32 *)(q + 0x60) = 0;
        *(s32 *)(q + 0x5C) = 0;
        func_00185640(p, q);
    }
}

void func_00343BE0(s32 a) {
    u8 *o;
    if ((o = func_003DA750(0, 0x5B, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00343B10;
        *(s16 *)(o + 0xCC) = a * 2 + 0x48;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x800C01;
        *(f32 *)(o + 0x78) = 1.0f;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x80) = 1.0f;
        *(V3 *)(o + 0x34) = D_00460CC0[a];
        o[0x20] = a;
        func_00170DF0(*(s32 *)(o + 0x84));
    }
}

void func_0035FD30(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_001E7F60(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        p[0x1B5] = 0x3A;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        ((s16 *)((p[2] << 1) + (u32)D_004C2794))[0x3E] += 1;
        if (*(u8 *)(*(u8 **)(p + 0x1C4) + 3) == 0) {
            u32 t = p[5];
            p[5] = t + 1;
            func_001757E0(p, 0x17, 1);
            *(s16 *)(p + 0x1C) = 0x5A;
        }
    }
}

s32 func_003B3700(u8 *p, u8 *a1) {
    u8 *s = a1 + 0x2B8;
    func_003B3880(p, *(s32 *)(p + 0x14));
    func_00175700(p);
    if (*(s16 *)(p + 0x1E) == 0) func_001E7F60(p);
    if (s[6] != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, 0x17);
    }
    if (func_00174470(p) == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        return func_003B3870(p, a1);
    }
}

