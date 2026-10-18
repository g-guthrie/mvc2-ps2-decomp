typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s16 D_004C27A4;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00354AB0(u8 *);
extern void func_0039FD90(u8 *);
extern s32 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_002CFA20(u8 *);
extern void func_001266A0(u8 *, s32, s32);
extern void func_001843A0(u8 *);
extern s32 func_0016A1F0(u8 *, s32);
extern s32 func_0016A130(u8 *, s32, s32);
extern void func_0015D010(u8 *, u32 *);

s32 func_00354A20(u8 *p) {
    u8 *o;
    s32 i;
    if (D_004C27A4 < 3) return 0;
    i = 0;
    do {
        o = func_003DA750(0, 1, 1);
        *(u16 *)(o + 0x26) = 0x702;
        o[0x20] = 0;
        o[0x21] = i;
        *(void **)(o + 0x10) = func_00354AB0;
        *(u8 **)(o + 0x18) = p;
        i++;
    } while (i < 2);
    return 1;
}

void func_0029A730(u8 *p) {
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *o;
        p[0x151] = 0;
        o = *(u8 **)(p + 0x1DC);
        *(u8 **)(o + 0x1C8) = p;
        o[0x20A] = 1;
        o[0x20D] = 2;
        func_001266A0(p, 0, 0);
        o[0x1B5] = 0x21;
        o[0x1E6] = p[0x1E6];
    }
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

s32 func_00169060(u8 *p, s32 n) {
    u32 a;
    u32 b;
    if (n > 3) return 0;
    if (p[0x215] != 0) return func_0016A1F0(p, 5);
    a = p[0x1E4];
    b = p[0x1E5];
    if (a == b) return 1;
    if (b == 0x12 && a != 0x13) return func_0016A130(p, 5, 3);
    return func_0016A1F0(p, 5);
}

void func_002AB2C0(u8 *p) {
    u32 v[3];
    s16 t = p[0x1E6] ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
    (*(u8 **)(p + 0x1DC))[0x1E6] = t;
    v[0] = 0xC2A00000;
    v[1] = 0x43384924;
    v[2] = 0;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_001266A0(p, 5, 5);
    func_001757E0(p, 0xF, 1);
}

