typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_b;
extern H_b *D_004C2794;
extern s8 D_004D18D6[];

#define INTEG() \
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C); \
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68); \
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60); \
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);

void func_002CA8F0(u8 *p, u8 *q) {
    extern s32 func_0018AB10(u8 *);
    extern void func_00175700(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *v;
    u8 *s;
    f32 c;
    s32 lim;

    p[0x40C] = 2;
    p[0x33C] = 5;
    v = *(u8 **)(p + 0x14);
    if (v != 0 && *(s8 *)(v + 0x1B3) != 0) {
        if (p[0x1E6] != 0) c = -1.25f; else c = 1.25f;
        *(f32 *)(p + 0x5C) -= c;
        q[7] = 6;
    }
    if (*(s8 *)(p + 0x151) != 0) q[4] = 1;
    p[0x209] = 1;
    s = *(u8 **)(p + 0x220);
    if (*(s16 *)(s + 0x434) <= 0 && D_004D18D6[s[2]] <= 2) goto fail;
    if ((p[0x1E6] == 0 && (*(s8 *)(p + 0x211) & 2) == 0) || (p[0x1E6] != 0 && (*(s8 *)(p + 0x211) & 1) == 0)) {
        if (q[7] != 0) {
            {
                u32 t7 = q[7] - 1;
                q[7] = t7;
                if ((t7 & 0xFF) == 0) {
                if (p[0x1E6] != 0) c = 0.10416666418313980f; else c = -0.10416666418313980f;
                *(f32 *)(p + 0x68) += c;
                INTEG()
                }
            }
        } else {
            INTEG()
        }
        if (func_0018AB10(p) != 0) {
            p[0x152] = 1;
            {
                u32 t = q[9];
                q[9] = t + 1;
            }
            lim = (*(s8 *)(p + 0x539) != 0) ? 6 : 2;
            if (q[9] >= (u8)lim) {
                q[9] = 0;
                if (*(s16 *)(p + 0x1E) >= 10) q[6] = 1;
                if (q[6] == 0) *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
            }
        }
        func_00175700(p);
        {
            s16 h = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = h;
            if (h < 0) goto fail;
        }
        if (*(s8 *)(p + 0x1B2) != 0) {
            {
            u32 t5 = q[5] - 1;
            q[5] = t5;
            if ((t5 & 0xFF) == 0) {
                s32 t8 = q[8] + 1;
                q[8] = t8;
                if ((t8 & 0xFF) < 10) {
                    s16 h = *(s16 *)(p + 0x1E) - 1;
                    *(s16 *)(p + 0x1E) = h;
                    if (h != 0) {
                        p[0x1B5] = 0x41;
                        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                        *(u32 *)(p + 0x1D8) = 0;
                        D_004C2794->f7c[p[2]] += 1;
                        q[5] = 2;
                    }
                }
            }
            }
        }
    } else {
fail:
    {
        u32 t7 = p[7];
        p[7] = t7 + 1;
    }
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    func_00175C00(p, 0);
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_001757E0(p, 0x15, 0x30);
    }
}
