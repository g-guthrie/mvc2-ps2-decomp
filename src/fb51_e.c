typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_e;
extern H_e *D_004C2794;

void func_002CA2E0(u8 *p, u8 *q)
{
    extern s32 func_0018AB10(u8 *);
    extern void func_00175700(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *t;
    u32 a;
    u32 c;
    u8 k;
    f32 x;
    s16 h;
    u32 n;
    s32 m;

    p[0x40C] = 2;
    p[0x33C] = 5;
    t = *(u8 **)(p + 0x14);
    if (t != 0 && *(s8 *)(t + 0x1B3) != 0) {
        if (p[0x1E6] != 0) x = -1.25f;
        else x = 1.25f;
        *(f32 *)(p + 0x5C) -= x;
        q[7] = 6;
    }
    if (*(s8 *)(p + 0x151) != 0) q[4] = 1;
    p[0x209] = 1;
    a = p[0x1E6];
    if (!((a != 0 || (*(s8 *)(p + 0x211) & 2) != 0) && (a == 0 || (*(s8 *)(p + 0x211) & 1) != 0))) {
        c = q[7];
        if (c != 0) {
            c = c - 1;
            q[7] = c;
            if ((c & 0xFF) != 0) goto call18;
            if (p[0x1E6] != 0) x = 0.1041666641831398f;
            else x = -0.1041666641831398f;
            *(f32 *)(p + 0x68) += x;
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        }
    call18:
        if (func_0018AB10(p) != 0) {
            p[0x152] = 1;
            n = q[9];
            q[9] = n + 1;
            k = (*(s8 *)(p + 0x539) != 0) ? 6 : 2;
            if (q[9] >= k) {
                q[9] = 0;
                if (*(s16 *)(p + 0x1E) >= 10) q[6] = 1;
                if (q[6] == 0) *(s16 *)(p + 0x1E) += 1;
            }
        }
        func_00175700(p);
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h < 0) goto done;
        if (*(s8 *)(p + 0x1B2) != 0) {
            c = q[5];
            c = c - 1;
            q[5] = c;
            if ((c & 0xFF) == 0) {
                m = q[8];
                m = m + 1;
                q[8] = m;
                if ((m & 0xFF) < 10) {
                    h = *(s16 *)(p + 0x1E) - 1;
                    *(s16 *)(p + 0x1E) = h;
                    if (h != 0) {
                        p[0x1B5] = 0x41;
                        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                        *(u32 *)(p + 0x1D8) = 0;
                        D_004C2794->f7c[p[2]]++;
                        q[5] = 2;
                    }
                }
            }
        }
    } else {
    done:
        c = p[7];
        p[7] = c + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_00175C00(p, 0);
        func_00183d50(p);
        func_001757E0(p, 0x15, 0x17);
    }
}
