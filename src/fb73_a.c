typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Ga;
typedef struct { u8 pad[0x34]; f32 f34; f32 f38; } Sf;
typedef struct { u8 pad[0x1C]; s16 h1C; s16 h1E; } Sh;
extern Ga *D_004C2794;
extern f32 D_00471A90[];
extern f32 D_00471A94[];

void func_0038F520(u8 *a) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    extern s8 func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_003DAA40(u8 *);
    u8 *p;
    u32 t;
    u32 z;
    u8 *q;
    Sf *sa;
    sa = (Sf *)a;
    p = *(u8 **)(a + 0x18);
    t = a[4];
    if (t == 0) {
        a[4] = t + 1;
        *(B3c *)(a + 0xEC) = *(B3c *)(p + 0xEC);
        a[0x13C] = 1;
        a[2] = p[2];
        a[1] = p[1];
        *(f32 *)(a + 0x50) = *(f32 *)(p + 0x50);
        *(f32 *)(a + 0x54) = *(f32 *)(p + 0x54);
        a[0x1B7] = p[0x1B7];
        a[0x1B8] = p[0x1B8];
        *(s8 *)(a + 0x30) = *(s8 *)(p + 0x30);
        *(V3 *)(a + 0x50) = *(V3 *)(p + 0x50);
        *(s8 *)(a + 0x24) = *(s8 *)(p + 0x24);
        a[0x13C] = 1;
        a[0x1B0] = 0x42;
        a[0x1B1] = 0x42;
        q = a + 2;
        if (p[0x269] == 8) {
            a[0x1B5] = 0x4B;
            z = a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
            *(s32 *)(a + 0x1D8) = 0;
            D_004C2794->f7c[q[0]]++;
            *(s16 *)(a + 0x1E) = 0xF;
            *(s16 *)(a + 0x1C) = 0xF;
        } else {
            if (a[0x20] == 0) {
                *(s8 *)(a + 0x1B5) = *(s8 *)(a + 0x1B7) + 0x32;
                z = a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
                *(s32 *)(a + 0x1D8) = 0;
                D_004C2794->f7c[q[0]]++;
            } else {
                *(s8 *)(a + 0x1B5) = *(s8 *)(a + 0x1B7) + 0x48;
                z = a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
                *(s32 *)(a + 0x1D8) = 0;
                D_004C2794->f7c[q[0]]++;
            }
            *(s16 *)(a + 0x1E) = 4;
            if (a[0x1B7] == 0) {
                *(s16 *)(a + 0x1C) = 0x19;
            } else {
                *(s16 *)(a + 0x1C) = 0x1E;
            }
        }
        func_001757E0(a, 0x17, (a[0x20] + 0x12) & 0xFF);
        func_001E3710(p, 0x4B);
    }
    ((Sf *)a)->f34 = D_00471A90[a[0x20] * 2];
    *(f32 *)(a + 0x38) = D_00471A94[a[0x20] * 2];
    if (*(s16 *)(a + 0x140) != 0) {
        sa->f34 = -sa->f34;
    }
    *(f32 *)((s32)a + 0x34) += *(f32 *)(p + 0x34);
    *(f32 *)((s32)a + 0x38) += *(f32 *)(p + 0x38);
    if (*(s32 *)(a + 0xD0) != *(u16 *)(p + 0x168)) {
        func_003DAA40(a);
        return;
    }
    if (a[4] == 1) {
        if (*(s8 *)(a + 0x1B3) != 0) {
            a[4] = a[4] + 1;
            func_001757E0(a, 0x17, (a[0x20] + 0x14) & 0xFF);
        } else if ((z = *(s8 *)(a + 0x1B4)) != 0) {
            a[0x1B4] = z - 1;
        } else {
            s16 v = *(s16 *)(a + 0x1E) - 1;
            *(s16 *)((s32)a + 0x1E) = v;
            if (v < 0) {
                ((Sh *)a)->h1E = 4;
                if (a[0x20] == 0) {
                    *(s8 *)(a + 0x1B5) = *(s8 *)(a + 0x1B7) + 0x32;
                    z = a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
                    *(s32 *)(a + 0x1D8) = 0;
                    D_004C2794->f7c[a[2]]++;
                } else {
                    *(s8 *)(a + 0x1B5) = *(s8 *)(a + 0x1B7) + 0x48;
                    z = a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
                    *(s32 *)(a + 0x1D8) = 0;
                    D_004C2794->f7c[a[2]]++;
                }
            }
            func_00175700(a);
            {
                s16 w = *(s16 *)(a + 0x1C) - 1;
                *(s16 *)((s32)a + 0x1C) = w;
                if (w < 0) {
                    ((Sh *)a)->h1C = 0;
                    t = a[4];
            a[4] = t + 1;
                    func_001757E0(a, 0x17, (a[0x20] + 0x14) & 0xFF);
                } else {
                    func_001E7F60(a);
                }
            }
        }
    } else if (a[4] == 2) {
        s32 r = func_00175700(a);
        if (r < 0) {
            t = a[4];
            a[4] = t + 1;
            a[0x13C] = 0;
            *(s32 *)(p + 0x308) = 1;
        }
    } else {
        func_003DAA40(a);
    }
}
