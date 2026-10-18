typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w190_b.c "-O3 -sdatathreshold 8" */

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2794;
extern G2794 *D_004C2794;
extern s32 func_00175700(u8 *);
extern void func_001BC660(u8 *, s32);

void func_0027A570(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        s16 t;
        *(s8 *)(p + 0x151) = 0;
        t = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = t;
        if (t & 1) {
            p[0x1B5] = 0x34;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        } else {
            p[0x1B5] = 0x3D;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    if (*(s8 *)(p + 0x150) != 0) {
        u32 u = p[6];
        p[6] = u + 1;
        func_001BC660(p, 4);
        func_001BC660(p, 5);
    }
}

extern void func_00183D90();
extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001E3710(u8 *, s32);
extern void func_001863F0(u8 *);

extern void func_001843A0(u8 *);

void func_00317AD0(u8 *p) {
    if (p[0x213] == 3) func_00183D90();
    if (p[6] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001861B0(p);
        p[0x1B5] = 0x58;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x20D] = 1;
        func_0018C4B0(p, 5);
        func_001757E0(p, 0x14, 0x1B);
        func_001E3710(p, 0x15);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_0023D980(u8 *p) {
    s16 t1, t2;
    u32 u;
    s32 *v1, *a0, *a1, *a2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    v1 = (s32 *)(p + 0x5C);
    a1 = (s32 *)(p + 0x68);
    a0 = (s32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a2 = (s32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x1B2) != 0) *(s16 *)(p + 0x1E) = 0;
    if (*(s16 *)(p + 0x1E) != 0) {
        t1 = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = t1;
        if (t1 == 0) {
            p[0x1B5] = 0x3E;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    {
        t2 = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t2;
        if (t2 == 0) {
            u = p[6];
            p[6] = u + 1;
            *v1 = 0;
            *a0 = 0;
            *a1 = 0;
            *a2 = 0;
            *(s16 *)(p + 0x1C) = 10;
        }
    }
}

extern void func_00299D60(u8 *);

void func_00299F80(u8 *a) {
    s32 *s0, *s1;
    s16 t1, t2;
    u32 u;
    s1 = (s32 *)(a + 0x6C);
    s0 = (s32 *)(a + 0x60);
    a[0x40C] = 2;
    a[0x33C] = 5;
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    func_00175700(a);
    func_00299D60(a);
    if (*(s8 *)(a + 0x1B2) != 0) {
        t1 = *(s16 *)(a + 0x1E) + 1;
        *(s16 *)(a + 0x1E) = t1;
    }
    t2 = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = t2;
    if (t2 <= 0) {
        u = a[6];
        a[6] = u + 1;
        if (*(s16 *)(a + 0x1E) != 0) {
            a[0x1B5] = 0x54;
            a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
            *(s32 *)(a + 0x1D8) = 0;
            D_004C2794->f7c[a[2]]++;
            func_001757E0(a, 0x16, 0xB);
        } else {
            u = a[6];
            a[6] = u + 1;
            func_001757E0(a, 0x15, 5);
            *(s32 *)(a + 0x5C) = 0;
            *s0 = 0;
            *(s32 *)(a + 0x68) = 0;
            *s1 = 0;
            *(u32 *)(a + 0x6C) = 0xBF4DB6DB;
        }
    }
}

void func_0022DA90(u8 *p) {
    switch (p[0x1FC]) {
    case 0:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    case 1:
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            break;
        }
        if (p[6] == 0 && *(s8 *)(p + 0x151) != 0 && ((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x40) != 0) {
            u32 t;
            *(u16 *)(p + 0x366) = 0;
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 8, 4);
            func_001E3710(p, 0x15);
            p[0x1B5] = 0x19;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
        break;
    case 2:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}
