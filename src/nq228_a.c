typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } P3c;

typedef struct { u8 pad[0x34]; f32 f34; } Qc;
extern P3c D_0043F490[];
extern u8 D_00583B90[];
extern s8 *D_004C2840;
extern P3c D_0043F498[];

void func_00137380(u8 *p) {
    extern void func_001378C0();
    extern void func_00137A00();
    extern void func_001377F0(u8 *);
    extern void func_0032D390(u8 *, s32, s32, s32, f32, f32);
    extern void func_0032D4E0(u8 *, s32, s32, f32);
    extern void func_0013AF60(u8 *);
    extern double fptodp(f32);
    extern double dpadd(double, double);
    extern f32 dptofp(double);
    s32 i;
    u32 t4;
    u8 q;
    u8 t;
    P3c *e;
    f32 f3, f1, a, b, c;
    *(f32 *)(p + 0x78) = 0.7f;
    *(f32 *)(p + 0x7C) = 0.7f;
    *(f32 *)(p + 0x80) = 0.7f;
    *(f32 *)(p + 0x50) = 1.0f;
    *(f32 *)(p + 0x54) = 1.0f;
    *(f32 *)(p + 0x58) = 1.0f;
    *(f32 *)(p + 0x3C) = D_0043F498[p[0x21]].x;
    *(f32 *)(p + 0x34) = D_0043F490[p[0x21]].x;
    if (*(u16 *)(p + 0x26) != 0) func_001378C0();
    else func_00137A00();
    if (D_004C2840[7] != 0) {
        t4 = p[4];
        p[4] = t4 + 1;
        *(f32 *)(p + 0x78) = 1.0f;
        *(f32 *)(p + 0x7C) = 1.0f;
        *(f32 *)(p + 0x80) = 1.0f;
        func_001377F0(p);
        f3 = *(f32 *)(p + 0x34);
        if (f3 >= 0.0f) {
            if (f3 > 50.0f) {
                a = 160.0f + f3;
                c = 800.0f + *(f32 *)(p + 0x3C);
            } else {
                a = 50.0f + f3;
                c = 1000.0f + *(f32 *)(p + 0x3C);
            }
        } else {
            if (f3 < -50.0f) {
                a = f3 - 160.0f;
                c = 800.0f + *(f32 *)(p + 0x3C);
            } else {
                a = f3 - 50.0f;
                c = 1000.0f + *(f32 *)(p + 0x3C);
            }
        }
        if (*(f32 *)(p + 0x38) > 150.0f) b = 40.0f + *(f32 *)(p + 0x38);
        else b = *(f32 *)(p + 0x38) - 40.0f;
        func_0032D390(p, *(s16 *)(p + 0x1C), 1, 1, a, b);
        func_0032D4E0(p, *(s16 *)(p + 0x1C), 1, c);
        func_0013AF60(p);
    } else {
    i = 0;
    while ((s16)i < 2) {
        t = D_00583B90[(s16)i + 0x30];
        if (t != 0) {
            q = (s8)t - 1;
            if (p[0x21] == q) {
                *(f32 *)(p + 0x78) = 1.0f;
                *(f32 *)(p + 0x7C) = 1.0f;
                *(f32 *)(p + 0x80) = 1.0f;
                if (i != 0) {
                    *(f32 *)(p + 0x50) = 1.149999976158142f;
                    *(f32 *)(p + 0x54) = 1.149999976158142f;
                    *(f32 *)(p + 0x58) = 1.149999976158142f;
                    e = D_0043F490 + q;
                    *(f32 *)(p + 0x3C) = (f32)(6.0 + (double)e->z);
                    if (*(f32 *)(p + 0x34) < 0.0f) ((Qc *)p)->f34 = e->x - 2.0f;
                    else ((Qc *)p)->f34 = 2.0f + e->x;
                } else {
                    *(f32 *)(p + 0x50) = 1.2f;
                    *(f32 *)(p + 0x54) = 1.2f;
                    *(f32 *)(p + 0x58) = 1.2f;
                    e = D_0043F490 + q;
                    *(f32 *)(p + 0x3C) = 8.0f + e->z;
                    if (*(f32 *)(p + 0x34) < 0.0f) ((Qc *)p)->f34 = e->x - 2.0f;
                    else ((Qc *)p)->f34 = 2.0f + e->x;
                }
            }
        }
        i = (s16)(i + 1);
    }
    }
}
