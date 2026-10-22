typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_h;
extern H_h *D_004C2794;

void func_00312B70(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern void func_001DD8A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    s16 h;

    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        if (*(s8 *)(p + 0x150) != 0) {
            p[0x150] = 0;
            q[2] = 1;
            func_001DD8A0(p, 7, 0);
        }
        t = q[0];
        if (t != 0) {
            t = t - 1;
            q[0] = t;
            if ((t & 0xFF) == 0) {
                q[1] = 0;
                q[0] = 0;
                t = q[3];
                q[3] = t ^ 1;
                if ((u8)(t ^ 1) != 0) {
                    p[0x1B5] = *(s8 *)(p + 0x1B7) * 2 + 0x30;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(s32 *)(p + 0x1D8) = 0;
                    D_004C2794->f7c[p[2]] += 1;
                } else {
                    p[0x1B5] = *(s8 *)(p + 0x1B7) * 2 + 0x4E;
                    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                    *(s32 *)(p + 0x1D8) = 0;
                    D_004C2794->f7c[p[2]] += 1;
                }
            }
        }
        if (*(s8 *)(p + 0x1B2) != 0) {
            if (q[1] == 0) {
                q[1] = 1;
                q[0] = 8;
            }
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        if (p[0x1E6] == 0) {
            if (*(s8 *)(p + 0x211) == 2) *(s16 *)(p + 0x1C) = 0;
        } else {
            if (*(s8 *)(p + 0x211) == 1) *(s16 *)(p + 0x1C) = 0;
        }
        h = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = h - 1;
        if (h == 0) {
            p[6]++;
            q[2] = 0;
            func_001757E0(p, 0x15, (u8)(p[0x1B7] + 4));
            func_001DD8A0(p, 1, 0);
        }
    }
}
