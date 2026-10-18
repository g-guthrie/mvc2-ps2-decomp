typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_004CAE80[];
extern u16 D_004F7F92;
extern u8 D_004CAFC0[];
extern void func_003DAA40(u32);
extern void func_0014C760(u8 *, s32, s32, s32, s32, f32);
void func_0014CA80(void) {
    s32 i = 0;
    do {
        u32 v = D_004CAE80[i + 0x50];
        if (v != 0) {
            func_003DAA40(v);
        }
        i++;
    } while (i < 12);
    func_0014C760(D_004CAFC0, 5, D_004F7F92, 0, 1, -5.99f);
}

extern void func_001B5350(u8 *, u8 *);
extern void func_001754A0(u8 *, s32, s32);
void func_001B4E90(u8 *p) {
    f32 x;
    u8 *g = *(u8 **)(p + 0x18);
    p[6]++;
    p[0x13C] = 1;
    func_001B5350(g, p);
    func_001754A0(p, 0x1B, p[0x20]);
    p[0x24] = 0;

    if (g[0x1E6] != 0) {
        x = -1.25f;
    } else {
        x = 1.25f;
    }
    *(f32 *)(p + 0x5C) = x;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = 8.5714283f;
    *(f32 *)(p + 0x6C) = -1.09375f;
}

extern u8 D_004528F0[];
void func_002413C0(u8 *p, f32 *q) {
    s8 t = p[0x151];
    s16 *e = (s16 *)(D_004528F0 + (t & ~1));
    f32 a = 1.6666666f * e[0];
    f32 b = 2.1428571f * e[1];
    if (p[0x1E6]) a = -a;
    q[3] = a;
    q[4] = b;
}

extern s32 func_00175700(u8 *);
void func_00289890(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x151] = 0;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x34) += -40.0f;
        } else {
            *(f32 *)(p + 0x34) += 40.0f;
        }
    }
}

extern void func_001757E0(u8 *, s32, s32);
void func_002B6CA0(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    *(f32 *)(p + 0x5C) = -6.25f;
    *(f32 *)(p + 0x68) = 0.0390625f;
    *(f32 *)(p + 0x60) = 20.625f;
    *(f32 *)(p + 0x6C) = -0.9040178f;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    func_001757E0(p, 0x15, 0x16);
}
