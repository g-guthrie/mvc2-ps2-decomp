typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x2B8]; f32 b[2]; } S2B8;

extern void *func_003DA750(u8 *,s32,s32);
extern void func_0019D830(u8 *);

void func_0019D7C0(u8 *a, u8 *b) {
    u8 *o;
    if ((o = (u8 *)func_003DA750(a, 3, 2)) != 0) {
        *(u8 *)(o + 0) = 1;
        *(u32 *)(o + 0x10) = (u32)func_0019D830;
        *(u8 **)(o + 0x18) = a;
        *(u32 *)(o + 0xD4) = (u32)b;
        *(u8 *)(o + 0x20) = 1;
        *(s16 *)(o + 0x26) = 0xA02;
        *(u8 *)(o + 1) = b[1];
    }
}

void func_002CB890(u8 *p) {
    extern void func_0015D010(u8 *, u32 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 v[3];
    s16 t;
    p[0x1B4] = 10;
    if (p[0x22] & 2) {
        t = p[0x1E6] ^ 1;
        *(s16 *)(p + 0x140) = t;
        p[0x1E6] = t;
        t = p[0x1E6] ^ 1;
        *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
        (*(u8 **)(p + 0x1DC))[0x1E6] = t;
    }
    v[0] = 0xC2F00000;
    v[1] = 0x432B6DB6;
    v[2] = 0;
    func_0015D010(p, v);
    func_001757E0(p, 15, 0);
}

void func_002B0D00(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s8 r;
    f32 *w;
    u8 *q;
    p[0x40C] = 2;
    p[0x33C] = 5;
    r = func_00175700(p);
    if (r < 0) {
        p[6] = 3;
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        func_001757E0(p, 0x16, 0);
        if ((*(u32 *)(p + 0x428) & 0x7000000) == 0) {
            w = ((S2B8 *)p)->b;
            q = *(u8 **)(p + 0x2D0);
            if (*(s16 *)(q + 0x434) != 0) {
                *(f32 *)(q + 0x34) = *(f32 *)(p + 0x34) - *w;
            }
        }
    }
}

void func_002EF760(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_0018AB60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001D6B50(u8 *, s32);
    extern void func_003A8DB0(u8 *);
    s16 v;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x15, 5);
        return;
    }
    if (func_0018AB60(p)) {
        v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v >= 0) *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001E3210(p, 0x1F);
        func_001D6B50(p, 1);
    }
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        func_003A8DB0(p);
    }
}
