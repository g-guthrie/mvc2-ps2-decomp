/* v2_c: mw -O3 -Op -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
void func_001D2680(u8 *p) {
    u8 *q;
    f32 a, b;
    if (p[0x23] != 0) q = *(u8 **)(p + 8);
    else q = *(u8 **)(p + 0x14);
    *(s16 *)(p + 0x140) = p[0x21];
    a = 51.66666412f;
    b = -34.28571320f;
    *(s8 *)(p + 0x13C) = *(s8 *)(q + 0x13C);
    *(int *)(p + 0x154) = *(int *)(q + 0x154);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if (p[0x20] != 0) {
        a = -a;
        b = -b;
    }
    if (*(s16 *)(p + 0x140) != 0) {
        a = -a;
    }
    *(f32 *)(p + 0x34) += a;
    *(f32 *)(p + 0x38) += b;
}

typedef struct { u8 pad[0x34]; f32 f34, f38; u8 pad2[0x1C]; f32 f58, f5c, f60, f64, f68, f6c; } S_0022E580;
extern int func_00175700();
extern void func_001843A0();
void func_0022E580(u8 *p) {
    f32 v = *(volatile f32 *)(p + 0x5C);
    f32 z = 0.0f;
    if (p[0x1E6] == 0) v = -v;
    if (v < z) {
        ((S_0022E580 *)p)->f34 += ((S_0022E580 *)p)->f5c;
        ((S_0022E580 *)p)->f5c += ((S_0022E580 *)p)->f68;
        ((S_0022E580 *)p)->f38 += ((S_0022E580 *)p)->f60;
        ((S_0022E580 *)p)->f60 += ((S_0022E580 *)p)->f6c;
    }
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

extern void func_002AD110();
extern void func_001757E0();
void func_002AD060(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    if (*(int *)(p + 0xD0) == 0) {
        func_002AD110(p);
        return;
    }
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x6C) = 0;
    {
        f32 v;
        if (p[0x1E6] != 0) {
            v = -16.66666603f;
        } else {
            v = 16.66666603f;
        }
        *(f32 *)(p + 0x5C) = v;
    }
    {
        f32 v;
        if (p[0x1E6] != 0) {
            v = 0.4166666567f;
        } else {
            v = -0.4166666567f;
        }
        *(f32 *)(p + 0x68) = v;
    }
    func_001757E0(p, 2, 5);
}

extern V3 D_004B8260[];
extern f32 D_004B8278[];
void func_0033DF70(u8 *p) {
    u8 i = p[0x20];
    s16 n = *(s16 *)(p + 0x1C);
    *(f32 *)(p + 0x34) = D_004B8260[i].x + (f32)n * D_004B8278[i] / 6000.0f;
    {
        s16 v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 0x1770) {
            *(s16 *)(p + 0x1C) = 0;
            *(V3 *)(p + 0x34) = D_004B8260[p[0x20]];
        }
    }
}

extern int func_00175700();
extern void func_001AD170(u8 *, int, u8);
void func_00250610(u8 *p, u8 *q) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s16 *)(p + 0x1C) = (p[0x1B7] != 0) ? 0x1E : 0xF;
        *(s16 *)(p + 0x1E) = *(s8 *)(q + 0xE) + 1;
        p[0x22] = 1;
        q[7] = 0;
        {
            f32 v;
            if (p[0x1E6] != 0) {
                v = 13.33333302f;
            } else {
                v = -13.33333302f;
            }
            *(f32 *)(p + 0x5C) = v;
        }
        func_001AD170(p, 3, (*(s8 *)(q + 0xE) != 0) ? 1 : 0);
    }
}

extern u8 *func_003DA750(int, int, int);
extern void func_00358A70();
void func_003589A0(u8 *p, u8 q, f32 a, f32 b) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r != 0) {
        *(void **)(r + 0x10) = func_00358A70;
        *(u8 **)(r + 0x18) = p;
        r[1] = p[1];
        *(s16 *)(r + 0x26) = 0xA00;
        *(u16 *)(r + 0xD0) = *(u16 *)(p + 0x168);
        if (*(s16 *)(p + 0x140) != 0) {
            a = -a;
        }
        *(f32 *)(r + 0x34) = *(f32 *)(p + 0x34) + 1.6666666f * a;
        *(f32 *)(r + 0x38) = *(f32 *)(p + 0x38) + 2.1428571f * b;
        r[0x21] = q;
    }
}

