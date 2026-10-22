typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x160]; s8 b[8]; } Se;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G7E;
extern G7E *D_004C2794;
extern u8 gdummy;

void func_002CB2C0(Se *a) {
    extern void func_00175700();
    extern void func_001CEA00();
    extern void func_001830D0();
    u32 v[3];
    s8 *p;
    s8 f;
    s8 *q;
    ((u8 *)a)[0x40C] = 2;
    ((u8 *)a)[0x33C] = 5;
    {
        u8 *r = (u8 *)a;
        r[0x405] = (r[0x269] == 6) ? 2 : 0;
    }
    func_00175700(a);
    p = a->b;
    f = p[1];
    q = p + 1;
    if (f & 1) {
        *q = f & ~1;
        func_001CEA00(a, 6);
    }
    if (*(s8 *)((u8 *)a + 0x151) != 0) {
        u32 t = ((u8 *)a)[6];
        ((u8 *)a)[6] = t + 1;
        *(u8 *)((s32)a + 0x151) = 0;
        ((u8 *)a)[0x404] = 0;
        ((u8 *)a)[0x405] = 0;
        v[0] = 0x42A35555;
        v[1] = 0x4313DB6D;
        v[2] = 0;
        func_001830D0(a, v, 1);
    }
}

void func_00315460(u8 *p) {
    extern void func_0018C6E0(void *);
    extern void func_001757E0();
    extern void func_0015D010();
    u32 v[3];
    u8 *q;
    q = p + 0x2B8;
    if (p[0x22] & 1) {
        u32 t = p[0x1E6];
        p[0x1E6] = t ^ 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 3);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    q[0x14] = 0;
    *(u32 *)(p + 0x5C) = 0xC1700000;
    *(u32 *)(p + 0x68) = 0xBE555555;
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    v[0] = 0xC1A00000;
    v[1] = 0x43340000;
    v[2] = 0;
    func_0015D010(p, v);
}

void func_00230500(Se *a) {
    extern s8 func_00175700();
    extern void func_001830D0();
    u32 v[3];
    ((u8 *)a)[0x40C] = 2;
    ((u8 *)a)[0x33C] = 5;
    {
        u8 *r = (u8 *)a;
        r[0x405] = (r[0x269] == 6) ? 2 : 0;
    }
    if (func_00175700(a) < 0) {
        u32 t = ((u8 *)a)[6];
        ((u8 *)a)[6] = t + 1;
        ((u8 *)a)[7] = 0;
        ((u8 *)a)[0x404] = 0;
        ((u8 *)a)[0x405] = 0;
        ((u8 *)a)[0x1B5] = 0x50;
        ((u8 *)a)[0x1B2] = *(u16 *)((u8 *)a + 0x1C0) = 0;
        *(s32 *)((u8 *)a + 0x1D8) = 0;
        D_004C2794->f7c[((u8 *)a)[2]]++;
        v[0] = 0x41D55555;
        v[1] = 0x42CDB6DB;
        func_001830D0(a, v, 1);
    }
}

void func_002840D0(Se *a) {
    extern s8 func_00175700();
    extern void func_00383B80();
    extern void func_001830D0();
    u32 v[3];
    ((u8 *)a)[0x40C] = 2;
    ((u8 *)a)[0x33C] = 5;
    {
        u8 *r = (u8 *)a;
        r[0x405] = (r[0x269] == 6) ? 2 : 0;
    }
    func_00175700(a);
    if (*(s8 *)((u8 *)a + 0x151) != 0) {
        f32 f;
        u32 t = ((u8 *)a)[6];
        ((u8 *)a)[6] = t + 1;
        *(u8 *)((s32)a + 0x151) = 0;
        if (((u8 *)a)[0x1E6] != 0) {
            f = 13.333333015441895f;
        } else {
            f = -13.333333015441895f;
        }
        *(f32 *)((u8 *)a + 0x5C) = f;
        func_00383B80(a, 4, 3);
        ((u8 *)a)[0x404] = 0;
        ((u8 *)a)[0x405] = 0;
        v[0] = 0xC2200000;
        v[1] = 0x42B40000;
        v[2] = 0;
        func_001830D0(a, v, 1);
    }
}

void func_0020E600(u8 *p) {
    extern void func_00175700();
    extern void func_00186A20();
    extern void func_00351AE0();
    extern void func_001E3210();
    extern void func_001E3710();
    extern void func_001757E0();
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        f32 f;
        u32 t = p[6];
        p[6] = t + 1;
        func_00186A20(p);
        p[0x209] = 2;
        p[0x208] = 2;
        *(s16 *)(p + 0x1E) = 8;
        func_00351AE0(p, 0);
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        if (p[0x1E6] != 0) {
            f = -6.666666507720947f;
        } else {
            f = 6.666666507720947f;
        }
        *(f32 *)(p + 0x5C) = f;
        *(u32 *)(p + 0x60) = 0x41AB6DB6;
        func_001E3210(p, 6);
        func_001E3710(p, 0x32);
        func_001757E0(p, 0x15, 0x1F);
    }
}
