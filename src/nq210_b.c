typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3d;
typedef struct {
    u8 pad0[0x1C];
    s16 h1c, h1e; u8 pad20[0x34 - 0x20];
    f32 f34, f38; u8 pad3c[0x50 - 0x3C];
    f32 f50, f54, f58, f5c, f60;
    u8 pad64[0x68 - 0x64];
    f32 f68, f6c;
} S;
extern G3d *D_004C2794;

void func_00371B90(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern int func_00175700(u8 *);
    extern f64 litodp(s32);
    extern f64 dpmul(f64, f64);
    extern f64 dpdiv(f64, f64);
    extern f64 dpadd(f64, f64);
    extern s32 dptoli(f64);
    extern f32 func_00417440(u16);
    extern void func_001E7F60(u8 *);
    s32 c = *(s8 *)(p + 0x1B2);
    if (c != 0) {
        if (p[0x21] >= 3) {
            u8 *q = *(u8 **)(p + 0x1C4);
            if (q[3] == 0) {
                if (q[0x425] == 0) {
                    if (((s8)c & 1) == 0) {
                        p[5] = 3;
                        *(s16 *)(p + 0x1C) = 0x3C;
                        func_001757E0(p, 0x17, 0x1D);
                        return;
                    }
                } else {
                    p[5] = 3;
                    *(s16 *)(p + 0x1C) = 0x28;
                    func_001757E0(p, 0x17, 0x1D);
                    return;
                }
            } else {
                p[5]++;
                *(s16 *)(p + 0x1C) = 0x28;
                func_001757E0(p, 0x17, 0x1D);
                return;
            }
        }
        if (p[7] == 6) {
            p[0x1B0] = 0x42;
            p[0x1B1] = 0x42;
            p[0x1B5] = 0x45;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x21]++;
        }
        if (p[7] == 0xC) {
            p[0x1B0] = 0x42;
            p[0x1B1] = 0x42;
            p[0x1B5] = 0x40;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x21]++;
        }
        p[7]++;
    }
    {
        s16 v = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = v - 1;
        if (v == 0) {
            p[5]++;
            func_001757E0(p, 0x17, 1);
        }
    }
    {
        S *sp = (S *)p;
        f32 one = 1.0f;
        f32 k;
        s16 w;
        if (sp->f50 > one) {
            sp->f50 = one;
            sp->f54 = one;
        } else {
            k = 0.04f;
            sp->f50 += k;
            sp->f54 += k;
        }
        func_00175700(p);
        sp->f34 += sp->f5c;
        sp->f5c += sp->f68;
        sp->f38 += sp->f60;
        sp->f60 += sp->f6c;
        sp->f38 += 5.0f * func_00417440((u16)((u32)(s32)(65536.0 * (double)sp->h1e / 360.0 + 0.5)));
        w = sp->h1e - 6;
        sp->h1e = w;
        if (w == 0) {
            sp->h1e = 0x168;
        }
    }
    func_001E7F60(p);
}
