typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002A05F0(u8 *p) {
    extern void func_0018C6E0(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 v[4];
    s16 t;
    u8 *q;
    f32 c;
    if (p[0x20B] == 0) {
        v[0] = 0xC1D55555;
        v[1] = 0x432FB6DB;
    } else {
        v[0] = 0xC276AAAA;
        v[1] = 0x42DA9249;
    }
    if ((*(u16 *)(p + 0x20E) & 0x800) == 0) {
        t = *(s16 *)(p + 0x140) ^ 1;
        *(s16 *)(p + 0x140) = t;
        p[0x1E6] = t;
    }
    t = *(s16 *)(p + 0x140) ^ 1;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) = t;
    (*(u8 **)(p + 0x1DC))[0x1E6] = t;
    func_0018C6E0(p);
    p[0x1B4] = 10;
    q = *(u8 **)(p + 0x1DC);
    if ((*(u32 *)(q + 0x42C) & 0x4000000) != 0) {
        if (p[0x20B] == 0) {
            c = 102.85713958740234f;
            *(f32 *)(q + 0x38) = c + *(f32 *)(p + 0x430);
        }
    }
    func_001266A0(p, 6, 6);
    func_0015D010(p, v);
    func_001757E0(p, 0xF, 0);
}

void func_00213080(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    extern void func_00353730(u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001830D0(u8 *, u32 *, s32);
    u32 v[4];
    s8 r;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    r = func_00175700(p);
    if (r >= 0) {
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            p[0x404] = 0;
            p[0x405] = 0;
            if (p[0x20D] == 2) {
                v[0] = 0xC0D55555;
                v[1] = 0x435EDB6D;
            } else {
                v[0] = 0xC23AAAAA;
                v[1] = 0x43340000;
            }
            v[2] = 0;
            func_001830D0(p, v, 1);
        }
    } else {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        q[1] = 0;
        func_00353730(p, 0);
        q[4] = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        q[5] = 0x30;
        func_001E3710(p, 0x48);
    }
}

typedef struct { u8 pad[0x2B8]; u8 b[16]; } S2B8_j;
extern u8 D_00456DE0[];

void func_00293830(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_00294B20(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001830D0(u8 *, u32 *, s32);
    u32 v[4];
    s8 r;
    u32 t;
    u8 *s0;
    s0 = ((S2B8_j *)p)->b;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    r = func_00175700(p);
    if (r < 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        s0[0xB] = 6;
        func_00294B20(p, D_00456DE0);
        if (p[0x20D] != 2) {
            func_001757E0(p, 0x16, 1);
        } else {
            func_001757E0(p, 0x16, 2);
        }
        if (p[2] == 0) {
            func_001266A0(p, 0xD, 3);
        } else {
            func_001266A0(p, 0xD, 4);
        }
        v[0] = 0xC1555555;
        v[1] = 0x42D20000;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}
