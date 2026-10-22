typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1E]; s16 f1e; } K_e;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_e;
extern G_e *D_004C2794;

void func_00307E30(u8 *p)
{
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    s16 h, h0;
    u32 t;
    f32 f;

    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    }
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        h0 = *(s16 *)(p + 0x1E);
        if (h0 != 0) {
            if (*(s8 *)(p + 0x150) != 0) {
                h = h0 - 1;
                ((K_e *)p)->f1e = h;
                if (h != 0) {
                    p[0x1B5] = 0x3A;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(s32 *)(p + 0x1D8) = 0;
                    D_004C2794->f7c[p[2]]++;
                } else {
                    *(s16 *)(p + 0x1C) = 1;
                }
            }
        }
    }
    h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h == 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        p[0x1B5] = 0x3B;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        f = (p[0x1E6] != 0) ? 5.0f : -5.0f;
        *(f32 *)(p + 0x5C) = f;
        f = (p[0x1E6] != 0) ? -0.05208333209156990f : 0.05208333209156990f;
        *(f32 *)(p + 0x68) = f;
        *(u32 *)(p + 0x60) = 0xC0A00000;
        *(u32 *)(p + 0x6C) = 0xBF200000;
        func_001757E0(p, 0x16, 7);
    }
}
